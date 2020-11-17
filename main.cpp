#include <iostream>
#include "GenQueue.h"
#include <string>
#include "FileError.h"
#include "Driver.h"
#include "Student.h"
using namespace std;

int main(int argc, char ** argv){
  FileError* FE; /* used to check file input */
  if(argc > 1){  /* if console argument provided */
    FE = new FileError(argv[1]);

    if(FE->pass() == false){
      while(true){
        FE->setFile(FE->getFile());
        if(FE->pass()) break;
      }
    }
  }
  else { /* if no console argument provided - get file name */
    FE = new FileError();

    if(FE->pass() == false){
      while(true){
        FE->setFile(FE->getFile());
        if(FE->pass()) break;
      }
    }
  }
  string file = FE->getFileValue();
  delete FE;
  /* run program with file */
  Driver* sim = new Driver(file);
  delete sim;

  return 0;
}
