#include "SnippetManager.h"
#include "Database.h"

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

void SnippetManager::newSnippet(const std::string &name, const std::string &code, const std::string &language)
{ 
  if (name.empty() || code.empty() || language.empty())
  {
    std::cout << "[Error] All fields are required" << std::endl;
    return;
  }

  std::vector<std::string> params = {name, code, language};
  int r = _db->executeQuery("INSERT INTO snippets (title,code,language) VALUES (?,?,?)", params);
  if (r == SQLITE_OK)
  {
    std::cout << "Snippet added successfully" << std::endl;
  }
  else if(r==19)
  {
    std::cout << "[Error] The snippet already exists" << std::endl;
  }
  else
  {
    std::cout << "[Error] An error occurred while adding the snippet" << std::endl;
  }
}

void SnippetManager::listSnippets()
{
}
