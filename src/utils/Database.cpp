#include "Database.h"

Database::Database()
{
    _file = ":memory:";
    int r = sqlite3_open(_file.c_str(), &db);
    if (r != SQLITE_OK)
    {
        db = nullptr;
        throw std::runtime_error("Failed to open the database");
    }
}

Database::Database(std::string file)
{
    _file = file;
    int r = sqlite3_open(_file.c_str(), &db);
    if (r != SQLITE_OK)
    {
        db = nullptr;
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

bool Database::executeQuery(const std::string query)
{
    char *errMsg;
    int r = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
    if (r != SQLITE_OK)
    {
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::executeQuery(const std::string query, const std::vector<std::string> &params)
{
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "[Error:sqlite] Error during the preparation of the request" << std::endl;
        return false;
    }

    // Bind query parameters
    for (int i = 0; i < params.size(); ++i)
    {
        rc = sqlite3_bind_text(stmt, i + 1, params[i].c_str(), -1, SQLITE_STATIC);
        if (rc != SQLITE_OK)
        {
            std::cerr << "[Error:sqlite] Error during the biding of the request's parameters" << std::endl;
            sqlite3_finalize(stmt);
            return false;
        }
    }

    // Execute the query
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cerr << "[Error:sqlite] Error during the execution of the request" << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}