#include <iostream>
#include <exception>
#include "Database.h"
#include "SnippetManager.h"

int main(int argc, char *argv[])
{
  try
  {
    Database db("DATABABSE.db");
    SnippetManager snpm(db);
    
  }
  catch (std::exception e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}