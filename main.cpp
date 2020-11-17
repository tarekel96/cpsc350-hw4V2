#include <iostream>
#include "GenQueue.h"
#include <string>
#include "FileError.h"
#include "Driver.h"
using namespace std;

int main(int argc, char ** argv){

  FileError* FE;
  if(argc > 1){
    FE = new FileError(argv[1]);

    if(FE->pass() == false){
      while(true){
        FE->setFile(FE->getFile());
        if(FE->pass()) break;
      }
    }
  }
  else {
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

  Driver* sim = new Driver(file);
  // sim->printFields();

  delete sim;

  return 0;
}
