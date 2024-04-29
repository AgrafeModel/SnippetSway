#include <iostream>
#include <exception>
#include <iomanip>
#include <getopt.h>
#include "Database.h"
#include "SnippetManager.h"

void DHM();
bool confirm(std::string what);
void PHL(std::string option, std::string description);


int main(int argc, char *argv[])
{
  try
  {
    bool debug = false;
    Database db("DATABASE.db", &debug);
    SnippetManager snpm(&db);

    int opt;
    while ((opt = getopt_long(argc, argv, "dhli:n:r:", nullptr, nullptr)) != -1)
    {
      switch (opt)
      {
      case 'd':
        debug = true;
        break;
      case 'h':
        DHM();
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
          snpm.newSnippet(optarg, argv[optind], argv[optind + 1]);
        }
        break;
      case 'r':
        if (std::string(optarg).find("--all") != std::string::npos)
        {
          if (confirm("delete all snippets") == false)
          {
            break;
          }
          snpm.deleteAllSnippets();
          break;
        }
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

      case 'i':
        if (argc < 4)
        {
          std::cerr << "Not enough arguments" << std::endl;
          return 1;
        }
        if (std::string(optarg).find_first_not_of("0123456789") == std::string::npos)
        {
          snpm.insertSnippetInFile(std::stoi(optarg), argv[optind], std::stoi(argv[optind + 1])-1);
        }
        else
        {
          snpm.insertSnippetInFile(optarg, argv[optind], std::stoi(argv[optind + 1])-1);
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

/**
 * @brief Print Help Line
*/
void PHL(std::string option, std::string description)
{
  std::cout << std::setw(100) << std::left << option
            << std::setw(100) << std::left << description << std::endl;
}


/**
 * @brief Display Help Message
*/ 
void DHM()
{
  PHL("-h", "Display this help message");
  PHL("-n [name] [code] [language]", "Create a new snippet");
  PHL("-n --file [name] [filepath] [start_line] [end_line]", "Create a new snippet from a file");
  PHL("-l", "List all snippets");
  PHL("-r [name] | [id]", "Remove a snippet");
  PHL("-r --all", "Remove all snippets");
  PHL("-i [name] | [id] [filepath] [line]", "Insert a snippet into a file at the specified line");
}

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