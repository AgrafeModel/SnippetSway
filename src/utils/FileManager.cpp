#include "FileManager.h"

FileManager::FileManager(std::string filepath){
    this->_fs = std::fstream(filepath);
    if (!this->_fs.is_open())
    {
        std::cerr << "[Error:file] The file "<< filepath << " can't be openned" << std::endl;
        throw std::runtime_error("Can't open the file");
    }
}
FileManager::~FileManager(){
    this->_fs.close();
}

int FileManager::insertInFile(std::string data, int line){
    if(!this->_fs){
        std::cerr << "[Error:file] No file stream" <<std::endl;
        return 1;
    }

    std::string l;
    int c =0;
    while(getline(this->_fs,l)){
        c++; // :)
        if(c==line){
            this->_fs << data << std::endl;
        }
        this->_fs << l << std::endl;
    }

    return 0;
}