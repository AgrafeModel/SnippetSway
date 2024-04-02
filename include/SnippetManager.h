#ifndef SNIPPETMANAGER_H
#define SNIPPETMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Database.h"


class SnippetManager {
public:
  SnippetManager(Database *db);

  /**
   * @brief Create a new snippet
   * 
   * @param name The name of the snippet
   * @param code The code of the snippet
   * @param language The language of the snippet
   * 
   * @return void
  */
  void newSnippet(const std::string &name, const std::string &code,const std::string &language);

  /**
   * @brief Delete a snippet
   * 
   * @param name The name of the snippet
   * 
   * @return void
  */
  void deleteSnippet(const std::string &name);

  /**
   * @brief Delete a snippet
   * 
   * @param id The id of the snippet
   * 
   * @return void
  */
  void deleteSnippet(const int id);


  /**
   * @brief List all snippets
   * 
   * @return void
  */
  void listSnippets();

private:
  Database *_db;

};

#endif // SNIPPETMANAGER_H
