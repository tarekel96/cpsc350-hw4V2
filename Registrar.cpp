#include "Registrar.h"

Registrar::Registrar(){}
Registrar::Registrar(int numberOfWindows, int timeOfDay, GenQueue<int>* studentTimesNeeded){
  waitTimes = new GenQueue<int>();
  idleTimes = new GenQueue<int>();
  m_numberOfWindows = numberOfWindows;
  Windows = new Window*[m_numberOfWindows];
  for(int i = 0; i < m_numberOfWindows; ++i){
    Windows[i] = new Window();
  }
  m_timeOfDay = timeOfDay;
  Line = new GenQueue<Student*>();
  while(!studentTimesNeeded->isEmpty()){
    Line->insert(new Student(m_timeOfDay, studentTimesNeeded->remove()));
  }
}
Registrar::~Registrar(){
  delete Windows;
  delete Line;
  delete waitTimes;
}
void Registrar::printFields(){
  cout << "Number of Windows " << m_numberOfWindows << endl;
  cout << "Time of day: " << m_timeOfDay << endl;
  cout << "Number of students: " << Line->getSize() << endl;
}
void Registrar::run(){
  while(!Line->isEmpty()){
    bool allWindowsAreFull = true;
    // iterate through Windows pointer array
    for(int i = 0; i < m_numberOfWindows; ++i){
      // if there is an available window - help next student
      if(Windows[i]->isHelping() == false && !Line->isEmpty()){
        allWindowsAreFull = false;
        // insert wait time to waitTime Queue before removing student from line Queue
        waitTimes->insert(Line->peek()->getTimeWaited(m_timeOfDay));
      //  cout << "Before remove Size: " << Line->getSize() << endl;
        Windows[i]->helpStudent(Line->remove());
      //  cout << "Removed from Line...new Size: " << Line->getSize() << endl;
      }
      // no available windows
      else {
        // decrements Time Remaining of helping student
      //  cout << "Decrement time remaining " << endl;
        Windows[i]->updateWindow();
      }
    }
    // all the windows are full and there are still students in line
    // if(allWindowsAreFull && !Line->isEmpty()){
    //   incrementRemainingStudentsWait();
    // }
    // not all of the windows are full - increment each of those Window's idle time
    if(allWindowsAreFull == false){
    //  cout << "Increment idle time " << endl;
      for(int i = 0; i < m_numberOfWindows; ++i){
        if(Windows[i]->isHelping() == false){
          // increments time idling
          Windows[i]->updateWindow();
        }
      }
    }
  //  cout << "while" << endl;
    m_timeOfDay++;
  }
//  cout << "here" << endl;
  printWaitTimes();
}
void Registrar::printWaitTimes(){
  while(!waitTimes->isEmpty()){
    cout << waitTimes->remove() << " ";
  }
  cout << endl;
}
void Registrar::incrementRemainingStudentsWait(){
  GenQueue<Student*>* tempQ;
  tempQ = new GenQueue<Student*>();
  while(!Line->isEmpty()){
  //  cout << "while 2" << endl;
    Student* tempStudent = Line->remove();
    tempStudent->incrementWait();
    tempQ->insert(tempStudent);
  }
  Line = tempQ;
  delete tempQ;
}
