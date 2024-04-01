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

    Database(bool *debug=nullptr);
    Database(std::string file, bool *debug=nullptr);
    ~Database();

    int executeQuery(const std::string query);
    int executeQuery(const std::string query, const std::vector<std::string> &params);


    // Debugging
    void error(const std::string &msg)
    {
        if (_debug)
            std::cerr << "[Error:sqlite] " << msg << std::endl;
    }

private:
    sqlite3 *db;
    std::string _file;
    bool _debug = false;
};

#endif 
