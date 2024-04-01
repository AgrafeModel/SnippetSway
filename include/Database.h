#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <vector>
#include <exception>
#include <iostream>

class Database {
public:
    Database();
    Database(std::string file);
    ~Database();

    
    bool executeQuery(const std::string query);
    bool executeQuery(const std::string query,const std::vector<std::string>& params);

private:
    sqlite3 *db;
    std::string _file;

};

#endif // DATABASE_H
