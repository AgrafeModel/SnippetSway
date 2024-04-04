#include "SnippetManager.h"

SnippetManager::SnippetManager(Database *db)
{
  _db = db;
  _db->executeQuery("CREATE TABLE if not exists snippets ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "title TEXT NOT NULL UNIQUE,"
                    "code TEXT NOT NULL,"
                    "language TEXT NOT NULL,"
                    "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
                    ");");
};

int SnippetManager::newSnippet(const std::string &name, const std::string &code, const std::string &language)
{
  if (name.empty() || code.empty() || language.empty())
  {
    std::cout << "[Error] All fields are required" << std::endl;
    return 0;
  }

  std::vector<std::string> params = {name, code, language};
  int r = _db->executeQuery("INSERT INTO snippets (title,code,language) VALUES (?,?,?)", params, nullptr);
  if (r == SQLITE_DONE)
  {
    std::cout << "Snippet added successfully" << std::endl;
  }
  else if (r == 19)
  {
    std::cout << "[Error] The snippet already exists" << std::endl;
  }
  else
  {
    std::cout << "[Error] An error occurred while adding the snippet: " << r << std::endl;
  }

  return r;
}

int SnippetManager::deleteSnippet(const std::string &name)
{
  if (name.empty())
  {
    std::cout << "[Error] The name is required" << std::endl;
    return 0;
  }

  std::vector<std::string> params = {name};
  int r = _db->executeQuery("DELETE FROM snippets WHERE title = ?", params, nullptr);
  if (r == SQLITE_DONE)
  {
    std::cout << "Snippet deleted successfully" << std::endl;
  }
  else
  {
    std::cout << "[Error] An error occurred while deleting the snippet: " << r << std::endl;
  }

  return r;
}

int SnippetManager::deleteSnippet(const int id)
{
  if (id == 0)
  {
    std::cout << "[Error] The ID is required" << std::endl;
    return 0;
  }

  std::vector<std::string> params = {std::to_string(id)};
  int r = _db->executeQuery("DELETE FROM snippets WHERE id = ?", params, nullptr);
  if (r == SQLITE_DONE)
  {
    std::cout << "Snippet deleted successfully" << std::endl;
  }
  else
  {
    std::cout << "[Error] An error occurred while deleting the snippet: " << r << std::endl;
  }

  return r;
}

void SnippetManager::listSnippets()
{
  std::vector<std::vector<std::string>> result;
  int r = _db->executeQuery("SELECT * FROM snippets", &result);
  if (r != SQLITE_DONE)
  {
    std::cout << "[Error] An error occurred while fetching the snippets: " << r << std::endl;
    return;
  }

  if (result.size() == 0)
  {
    std::cout << "No snippets found" << std::endl;
    return;
  }

  std::cout << std::setw(5) << std::left << "ID"
            << std::setw(20) << std::left << "Title"
            << std::setw(20) << std::left << "Language"
            << std::setw(20) << std::left << "Created At" << std::endl;
  for (auto row : result)
  {
    std::cout << std::setw(5) << std::left << row[0]
              << std::setw(20) << std::left << row[1]
              << std::setw(20) << std::left << row[3]
              << std::setw(20) << std::left << row[4] << std::endl;
  }
}

int SnippetManager::deleteAllSnippets(){
  int r = _db->executeQuery("DELETE * FROM snippets");
  if (r == SQLITE_DONE)
  {
    std::cout << "All snippets deleted successfully" << std::endl;
  }
  else
  {
    std::cout << "[Error] An error occurred while deleting the snippets: " << r << std::endl;
  }

  return r;

}

int SnippetManager::newSnippetFromFile(const std::string &name,const std::string &file, int ls, int le){
  if (name.empty() || file.empty())
  {
    std::cout << "[Error] All fields are required" << std::endl;
    return 0;
  }

  std::ifstream f(file);
  if (!f.is_open())
  {
    std::cout << "[Error] The file does not exist" << std::endl;
    return 0;
  }

  std::string code;
  std::string line;
  int i = 0;
  while (std::getline(f, line))
  {
    if (ls != 0 && i < ls)
    {
      i++;
      continue;
    }
    if (le != 0 && i > le)
    {
      break;
    }
    code += line + "\n";
    i++;
  }
  //Get the file extension
  std::string ext = file.substr(file.find_last_of(".") + 1);
  std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);



  std::vector<std::string> params = {name, code, ext};
  int r = _db->executeQuery("INSERT INTO snippets (title,code,language) VALUES (?,?,?)", params, nullptr);
  if (r == SQLITE_DONE)
  {
    std::cout << "Snippet added successfully" << std::endl;
  }
  else if (r == 19)
  {
    std::cout << "[Error] The snippet already exists" << std::endl;
  }
  else
  {
    std::cout << "[Error] An error occurred while adding the snippet: " << r << std::endl;
  }
  
  return r;
}

int SnippetManager::insertSnippetInFile(const std::string &name, const std::string &file, int line){
  std::ifstream f(file);
  if (!f.is_open())
  {
    std::cout << "[Error] The file does not exist" << std::endl;
    return 0;
  }

  std::cout << line << std::endl;

  //get the code snippet from db
  std::vector<std::string> params = {name};
  std::vector<std::vector<std::string>> result;
  int r = _db->executeQuery("SELECT code FROM snippets WHERE title = ?", params, &result);
  if (r != SQLITE_DONE)
  {
    std::cout << "[Error] An error occurred while fetching the snippet: " << r << std::endl;
    return r;
  }
  if (result.size() == 0)
  {
    std::cout << "Snippet not found" << std::endl;
    return 0;
  }

  //



  f.close();
  return 1;
}
int SnippetManager::insertSnippetInFile(const int id, const std::string &file, int line){

  return 1;
}