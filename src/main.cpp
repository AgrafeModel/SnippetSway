#include <iostream>
#include <exception>
#include <iomanip>
#include <getopt.h>
#include "Database.h"
#include "SnippetManager.h"

void displayHelp();

int main(int argc, char *argv[])
{
  try
  {
    bool debug = false;
    if (argc > 1 && std::string(argv[1]) == "-d")
    {
      debug = true;
    }

    Database db("DATABASE.db", &debug);
    SnippetManager snpm(&db);

    int opt;
    while ((opt = getopt_long(argc, argv, "hln:r:", nullptr, nullptr)) != -1)
    {
      switch (opt)
      {
      case 'h':
        displayHelp();
        break;
      case 'l':
        snpm.listSnippets();
        break;
      case 'n':
        snpm.newSnippet(optarg, argv[optind], argv[optind + 1]);
        break;
      case 'r':

        /* USER CONFIRMATION */

        std::cout << "Are you sure you want to delete the snippet? [y/n]: ";
        char c;
        std::cin >> c;
        if (c != 'y' && c != 'Y')
        {
          std::cout << "Snippet not deleted" << std::endl;
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
  std::cout << std::setw(50) << std::left << "-l"
            << std::setw(50) << std::left << "List all snippets" << std::endl;
  std::cout << std::setw(50) << std::left << "-r [name] | [id]"
            << std::setw(50) << std::left << "Remove a snippet" << std::endl;
}