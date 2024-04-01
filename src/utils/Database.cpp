#include "Database.h"

Database::Database(bool *debug)
{
    if (debug != NULL)
        _debug = *debug;

    _file = ":memory:";
    int r = sqlite3_open(_file.c_str(), &db);
    if (r != SQLITE_OK)
    {
        db = nullptr;
        this->error("Failed to open the database");
        throw std::runtime_error("Failed to open the database");
    }
}

Database::Database(std::string file, bool *debug)
{
    if (debug != NULL)
        _debug = *debug;

    _file = file;
    int r = sqlite3_open(_file.c_str(), &db);
    if (r != SQLITE_OK)
    {
        db = nullptr;
        this->error("Failed to open the database");
        throw std::runtime_error("Failed to open the database");
    }
}

Database::~Database()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
    }
}

int Database::executeQuery(const std::string query)
{
    char *errMsg;
    int r = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
    if (r != SQLITE_OK)
    {
        this->error("Error during the execution of the request: " + std::string(sqlite3_errmsg(db)));
        sqlite3_free(errMsg);
        return sqlite3_errcode(db);
    }
    return r;
}

int Database::executeQuery(const std::string query, const std::vector<std::string> &params)
{
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        this->error("Error during the preparation of the request: " + std::string(sqlite3_errmsg(db)));
        return sqlite3_errcode(db);
    }

    // Bind query parameters
    for (int i = 0; i < params.size(); ++i)
    {
        rc = sqlite3_bind_text(stmt, i + 1, params[i].c_str(), -1, SQLITE_STATIC);
        if (rc != SQLITE_OK)
        {
            this->error("Error during the binding of the parameters: " + std::string(sqlite3_errmsg(db)));
            sqlite3_finalize(stmt);
            return sqlite3_errcode(db);
        }
    }

    // Execute the query
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        this->error("Error during the execution of the request: " + std::string(sqlite3_errmsg(db)));
        sqlite3_finalize(stmt);
        return sqlite3_errcode(db);
    }

    sqlite3_finalize(stmt);
    return rc;
}