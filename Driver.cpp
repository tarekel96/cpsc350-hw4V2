#include "Driver.h"

Driver::Driver(){}
Driver::Driver(string file){
  m_choice = getChoice();
  if(m_choice == 1){
    m_outputFile = getOutputFileName();
  }
  setFile(file);
  studentTimesNeeded = new GenQueue<int>(); /* init studentTimesNeeded Queue */
  processFile();  /* get info from file */
  if(m_choice == 0){
    RegistrarOffice = new Registrar(m_numberOfOpenWindows, m_startTime, studentTimesNeeded);
  }
  else{
    RegistrarOffice = new Registrar(m_numberOfOpenWindows, m_startTime, studentTimesNeeded, m_outputFile);
  }
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
int Driver::getChoice(){
  int response = -1;
  while(true){
    cout << "ENTER 0 TO OUTPUT TO CONSOLE OR 1 TO OUTPUT TO ANOTHER FILE" << endl;
    cin >> response;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    else{
      if(response == 0 || response == 1)
        break;
      else{
        cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
        continue;
      }
    }
  }
  return response;
}
string Driver::getOutputFileName(){
  string file;
  while(true){
    cout << "PLEASE ENTER THE NAME OF THE OUTPUT FILE" << endl;
    cin >> file;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    else
      break;
  }
  return file;
}
