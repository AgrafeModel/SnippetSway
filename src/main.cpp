#include <iostream>
#include <exception>
#include "Database.h"
#include "SnippetManager.h"

int main(int argc, char *argv[])
{
  try
  {
    bool debug = false;

    for (int i = 0; i < argc; i++)
    {
      if (std::string(argv[i]) == "-d")
      {
        debug = true;
        break;
      }
    }



    Database db("DATABASE.db",&debug);
    SnippetManager snpm(&db);

    snpm.newSnippet("Test","print('Helloworld')","py");
    
  }
  catch (std::exception e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}