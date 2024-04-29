#include "FileManager.h"

FileManager::FileManager(std::string filepath)
{
    this->_fs = std::fstream(filepath);
    if (!this->_fs.is_open())
    {
        std::cerr << "[Error:file] The file " << filepath << " can't be openned" << std::endl;
        throw std::runtime_error("Can't open the file");
    }
}

FileManager::~FileManager()
{
    this->_fs.close();
}

int FileManager::insertInFile(std::string data, int line)
{
    if(line < 0){
        std::cout << "Inserting data at the end of the file" << std::endl;
        this->_fs << data << std::endl;
        return 0;
    }

    std::cout << "Inserting data in line " << line << std::endl;
    if (!this->_fs)
    {
        std::cout << "[Error:file] No file stream" << line << std::endl;
        throw std::runtime_error("[Error:file] No file stream");
    }

    std::vector<std::string> lines;
    std::string temp;
    while (std::getline(this->_fs, temp))
    {
        lines.push_back(temp);
    }

    if (line < 0 || line > lines.size())
    {
        std::cout << "[Error:file] The line number is out of range" << std::endl;
        throw std::runtime_error("[Error:file] The line number is out of range");
    }

    lines.insert(lines.begin() + line, data);

    this->_fs.clear();
    this->_fs.seekp(0, std::ios::beg);
    for (auto &l : lines)
    {
        this->_fs << l << std::endl;
    }




    return 0;
}
