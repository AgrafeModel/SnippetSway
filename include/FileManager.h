#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <exception>
#include <vector>

class FileManager
{
public:
    FileManager(std::string filepath);
    ~FileManager();




    int insertInFile(std::string data, int line);

private:
    std::string _filepath; 
    std::fstream _fs;      // filestream

};

#endif
