#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <vector>
#include <exception>
#include <iostream>

class Database
{
public:
    Database(bool *debug = nullptr);
    Database(std::string file, bool *debug = nullptr);
    ~Database();

    /**
     * @brief Execute a query and return the result in a vector of vector of strings
     *
     * @param query The query to execute
     * @param result The result of the query. The first vector is the row and the second vector is the column
     *
     * @return int The return code of the query. SQLITE_DONE if the query was successful or an error code
     */
    int executeQuery(const std::string query, std::vector<std::vector<std::string>> *result = nullptr);

    /**
     * @brief Execute a query with parameters and return the result in a vector of vector of strings
     *
     * @param query The query to execute
     * @param params The parameters of the query. The order of the parameters must match the order of the '?' in the query
     * @param result The result of the query. The first vector is the row and the second vector is the column
     *
     * @return int The return code of the query. SQLITE_DONE if the query was successful or an error code
     */
    int executeQuery(const std::string query, const std::vector<std::string> &params, std::vector<std::vector<std::string>> *result = nullptr);

private:
    sqlite3 *db;         // The SQLite3 database object
    std::string _file;   // The database file name.
    bool _debug = false; // Debug mode

    /**
     * @brief Display an error message for debugging
     *
     * @param msg The message to display
     *
     * @return void
     */
    void error(const std::string &msg);
};

#endif
