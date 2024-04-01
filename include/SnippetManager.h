#ifndef SNIPPETMANAGER_H
#define SNIPPETMANAGER_H

#include <string>
#include <vector>
#include "Database.h"


class SnippetManager {
public:
  SnippetManager(Database db);
  void newSnippet(const std::string &name, const std::string &code);
  void listSnippets();

private:
  Database _db;

};

#endif // SNIPPETMANAGER_H
