#include "SnippetManager.h"
#include "Database.h"

SnippetManager::SnippetManager(Database db)
{
  _db = db;
  db.executeQuery("CREATE TABLE if not exists snippets ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "title TEXT NOT NULL,"
                  "code TEXT NOT NULL,"
                  "language TEXT NOT NULL,"
                  "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
                  ");");
};

void SnippetManager::newSnippet(const std::string &name, const std::string &code)
{
}

void SnippetManager::listSnippets()
{
}
