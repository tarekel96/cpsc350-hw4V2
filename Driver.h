#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Registrar.h"

using namespace std;
class Driver{
  private:
    Registrar* RegistrarOffice;
    GenQueue<int>* studentTimesNeeded;
    string m_file;
    ifstream inFile;
    int m_numberOfOpenWindows;
    int m_startTime;
    int m_numberOfStudents;
    //vector<int> studentTimesNeeded;


  public:
    Driver();
    Driver(string file);
    ~Driver();

    void setFile(string file);
    void processFile();
    void printFields();
};
#endif
