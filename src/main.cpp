#include <iostream>
#include <exception>
#include <iomanip>
#include <getopt.h>
#include "Database.h"
#include "SnippetManager.h"

void displayHelp();
bool confirm(std::string what)
{
  std::cout << "Are you sure you want to " << what << "? [y/n]: ";
  char c;
  std::cin >> c;
  if (c != 'y' && c != 'Y')
  {
    std::cout << "Operation canceled" << std::endl;
    return false;
  }
  return true;
}

int main(int argc, char *argv[])
{
  try
  {
    bool debug = false;
    Database db("DATABASE.db", &debug);
    SnippetManager snpm(&db);

    int opt;
    while ((opt = getopt_long(argc, argv, "dhln:r:", nullptr, nullptr)) != -1)
    {
      switch (opt)
      {
      case 'd':
        debug = true;
        break;
      case 'h':
        displayHelp();
        break;
      case 'l':
        snpm.listSnippets();
        break;
      case 'n':

        if (std::string(optarg).find("--file") != std::string::npos)
        {
          if (argc < 7)
          {
            std::cerr << "Not enough arguments" << std::endl;
            return 1;
          }
          snpm.newSnippetFromFile(argv[optind], argv[optind + 1], std::stoi(argv[optind + 2]), std::stoi(argv[optind + 3]));
        }
        else
        {
          if (argc < 4)
          {
            std::cerr << "Not enough arguments" << std::endl;
            return 1;
          }
          snpm.newSnippet(argv[optind], argv[optind + 1], argv[optind + 2]);
        }
        break;
      case 'r':

        /* USER CONFIRMATION */

        if (confirm("delete the snippet") == false)
        {
          break;
        }

        if (std::string(optarg).find_first_not_of("0123456789") == std::string::npos)
        {
          snpm.deleteSnippet(std::stoi(optarg));
        }
        else
        {
          snpm.deleteSnippet(optarg);
        }

        break;
      default:
        std::cerr << "Unknown option: " << opt << std::endl;
        return 1;
      }
    }
  }
  catch (std::exception e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}

void displayHelp()
{
  std::cout << std::setw(50) << std::left << "Option"
            << std::setw(50) << std::left << "Description" << std::endl;
  std::cout << std::setw(50) << std::left << "-------"
            << std::setw(50) << std::left << "------------" << std::endl;
  std::cout << std::setw(50) << std::left << "-h"
            << std::setw(50) << std::left << "Display this help message" << std::endl;

  std::cout << std::setw(50) << std::left << "-n [name] [code] [language]"
            << std::setw(50) << std::left << "Create a new snippet" << std::endl;
  std::cout << std::setw(50) << std::left << "-n --file [name] [filepath] [start_line] [end_line]"
            << std::setw(50) << std::left << "Create a new snippet from a file" << std::endl;
  std::cout << std::setw(50) << std::left << "-l"
            << std::setw(50) << std::left << "List all snippets" << std::endl;
  std::cout << std::setw(50) << std::left << "-r [name] | [id]"
            << std::setw(50) << std::left << "Remove a snippet" << std::endl;
}