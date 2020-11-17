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
    cout << "Time Of Day: " << m_timeOfDay << endl;
    for(int i = 0; i < m_numberOfWindows; ++i){
      if(Windows[i]->isHelping()) Windows[i]->updateWindow();
    }

    bool allWindowsAreFull = true;
    // iterate through Windows pointer array
    for(int i = 0; i < m_numberOfWindows; ++i){
      // if there is an available window - help next student
      if(Windows[i]->isHelping() == false && !Line->isEmpty()){
        allWindowsAreFull = false;
        // insert wait time to waitTime Queue before removing student from line Queue
        waitTimes->insert(Line->peek()->getTimeWaited(m_timeOfDay));
        //cout << "wait time " << Line->peek()->getTimeWaited(m_timeOfDay) << endl;
        Windows[i]->helpStudent(Line->remove());
      }
    }
    // not all of the windows are full - increment each of those Window's idle time
    if(allWindowsAreFull == false){
      for(int i = 0; i < m_numberOfWindows; ++i){
        if(Windows[i]->isHelping() == false){
          // increments time idling
          Windows[i]->updateWindow();
        }
      }
    }
    incrementTimeOfDay();
  }
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
    Student* tempStudent = Line->remove();
    tempStudent->incrementWait();
    tempQ->insert(tempStudent);
  }
  Line = tempQ;
  delete tempQ;
}
void Registrar::incrementTimeOfDay(){
  m_timeOfDay++;
}
