#ifndef SNIPPETMANAGER_H
#define SNIPPETMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Database.h"

class SnippetManager
{
public:
  SnippetManager(Database *db);

  /**
   * @brief Create a new snippet
   *
   * @param name The name of the snippet
   * @param code The code of the snippet
   * @param language The language of the snippet
   *
   * @return int The return code of the query. SQLITE_DONE if the query was successful or an error code
   */
  int newSnippet(const std::string &name, const std::string &code, const std::string &language);

  /**
   * @brief Create a new snippet from a file
   *
   * @param name The name of the snippet
   * @param file The file path of the file
   * @param ls The line start. If 0, it will read from the beginning of the file
   * @param le The line end. If 0, it will read until the end of the file
   *
   * @return int The return code of the query. SQLITE_DONE if the query was successful or an error code
   */
  int newSnippetFromFile(const std::string &name, const std::string &file, int ls = 0, int le = 0);

  /**
   * @brief Delete a snippet
   *
   * @param name The name of the snippet
   *
   * @return int The return code of the query. SQLITE_DONE if the query was successful or an error code
   */
  int deleteSnippet(const std::string &name);

  /**
   * @brief Delete a snippet
   *
   * @param id The id of the snippet
   *
   * @return int The return code of the query. SQLITE_DONE if the query was successful or an error code
   */
  int deleteSnippet(const int id);

  /**
   * @brief Delete all snippets
   *
   * @return int The return code of the query. SQLITE_DONE if the query was successful or an error code
   */
  int deleteAllSnippets();

  /**
   * @brief List all snippets
   *
   * @return void
   */
  void listSnippets();

  int insertSnippetInFile(const std::string &name, const std::string &file, int line = 0);
  int insertSnippetInFile(const int id, const std::string &file, int line = 0);


private:
  Database *_db;
};

#endif // SNIPPETMANAGER_H
