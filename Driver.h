#ifndef DRIVER_H
#define DRIVER_H
/*
  * @name Driver - class responsible for running the program simulation
  * @author Tarek El-Hajjaoui
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Registrar.h"
using namespace std;
class Driver{
  private:
    Registrar* RegistrarOffice; /* instance of Registrar that represents the Registrar Office */
    GenQueue<int>* studentTimesNeeded; /* Queue of student times needed - populated from input file */
    string m_file; /* input file from user */
    ifstream inFile; /* used to open and read through m_file */
    int m_numberOfOpenWindows; /* the number of windows the Registrar Office has */
    int m_startTime; /* initial time of day - when first student arrives */
    int m_numberOfStudents; /* the number of students arriving to the registrar office */
  public:
    Driver(); /* Default Constructor */
    /*
      * Overloaded Constructor - takes in an input file
      * @param file - name of input file
    */
    Driver(string file);
    ~Driver(); /* Destructor */

    /* MUTATOR */
    void setFile(string file);
    void processFile(); /* reads through file and gets information */
    /* PRINT FUNCTION */
    void printFields();
};
#endif
