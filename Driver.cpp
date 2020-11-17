#include "Driver.h"

Driver::Driver(){}
Driver::Driver(string file){
  setFile(file);
  studentTimesNeeded = new GenQueue<int>(); /* init studentTimesNeeded Queue */
  processFile();  /* get info from file */
  RegistrarOffice = new Registrar(m_numberOfOpenWindows, m_startTime, studentTimesNeeded);
  RegistrarOffice->run(); /* simulate program */
}
Driver::~Driver(){
  if(studentTimesNeeded != NULL) delete studentTimesNeeded;
  delete RegistrarOffice;
}
void Driver::setFile(string file){
  m_file = file;
}
void Driver::processFile(){
  inFile.open(m_file);
  string currentLine;
  int counter = 0;
  while(getline(inFile, currentLine)){
    if(counter == 0) m_numberOfOpenWindows = stoi(currentLine); /* first - number of windows */
    else if(counter == 1) m_startTime = stoi(currentLine);  /* second - time first student arrives */
    else if(counter == 2) m_numberOfStudents = stoi(currentLine); /* third - number of students that arrive */
    else studentTimesNeeded->insert(stoi(currentLine)); /* rest - time student needs at window */
    counter++;
  }
}
void Driver::printFields(){
  cout << "Number of windows " << m_numberOfOpenWindows << endl;
  cout << "Time of day: " << m_startTime << endl;
  cout << "Number of students " << m_numberOfStudents << endl;
}
