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

void Database::error(const std::string &msg)
{
    if (_debug)
        std::cerr << "[Error:sqlite] " << msg << std::endl;
}

int Database::executeQuery(const std::string query, std::vector<std::vector<std::string>> *result)
{
    if (result != nullptr)
        result->clear();

    sqlite3_stmt *stmt;

    // Prepare the query
    int r = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (r != SQLITE_OK)
    {
        this->error("Failed to prepare the query");
        throw std::runtime_error("Failed to prepare the query");
    }
    // Execute the query
    while ((r = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        std::vector<std::string> row;
        int numColumns = sqlite3_column_count(stmt);
        for (int i = 0; i < numColumns; ++i)
        {
            const char *columnValue = (const char *)sqlite3_column_text(stmt, i);
            row.push_back(columnValue != nullptr ? columnValue : "");
        }
        if (result != nullptr)
            result->push_back(row);
    }

    if (r != SQLITE_DONE)
    {
        this->error("Failed to execute the query");
        throw std::runtime_error("Failed to execute the query");
    }

    sqlite3_finalize(stmt);
    return r;
}

int Database::executeQuery(const std::string query, const std::vector<std::string> &params, std::vector<std::vector<std::string>> *result)
{

    if (result != nullptr)
        result->clear();

    sqlite3_stmt *stmt;

    // Prepare the query
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
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        std::vector<std::string> row;
        int numColumns = sqlite3_column_count(stmt);
        for (int i = 0; i < numColumns; ++i)
        {
            const char *columnValue = (const char *)sqlite3_column_text(stmt, i);
            row.push_back(columnValue != nullptr ? columnValue : "");
        }
        if (result != nullptr)
            result->push_back(row);
    }

    sqlite3_finalize(stmt);
    return rc;
}
