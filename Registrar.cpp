#include "Registrar.h"

Registrar::Registrar(){}
Registrar::Registrar(int numberOfWindows, int timeOfDay, GenQueue<int>* studentTimesNeeded){
  waitTimes = new GenQueue<int>();
  idleTimes = new GenQueue<int>();
  m_numberOfWindows = numberOfWindows;
  Windows = new Window*[m_numberOfWindows];
  for(int i = 0; i < m_numberOfWindows; ++i){
    // Windows[i] = new Window();
    Windows[i] = new Window(timeOfDay);
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
    cout << "TIME " << m_timeOfDay << endl;
    for(int i = 0; i < m_numberOfWindows; ++i){
      if(Windows[i]->isHelping()) Windows[i]->updateWindow();
    }

    bool allWindowsAreFull = true;
    int temp;
    // iterate through Windows pointer array
    for(int i = 0; i < m_numberOfWindows; ++i){
      // if there is an available window - help next student
      if(Windows[i]->isHelping() == false && !Line->isEmpty()){
        allWindowsAreFull = false;
        // insert wait time to waitTime Queue before removing student from line Queue
        waitTimes->insert(Line->peek()->getTimeWaited(m_timeOfDay));
        //cout << "wait time " << Line->peek()->getTimeWaited(m_timeOfDay) << endl;
        if(Line->getSize() == 1){
          temp = Line->peek()->getTimeNeeded();
        }
        Windows[i]->helpStudent(Line->remove());
      }
    }
    // not all of the windows are full - increment each of those Window's idle time
    if(allWindowsAreFull == false){
      for(int i = 0; i < m_numberOfWindows; ++i){
        if(Windows[i]->isHelping() == false){
          if(Line->getSize() == 0){
            Windows[i]->addToIdleTime(temp);
          }
          else {
            // increments time idling
            Windows[i]->updateWindow();
          }
        }
      }
    }
    incrementTimeOfDay();
  }
  for(int i = 0; i < m_numberOfWindows; ++i){
    idleTimes->insert(Windows[i]->getIdleTime());
  }
  printWaitTimes();
  printIdleTimes();
}
void Registrar::printWaitTimes(){
  while(!waitTimes->isEmpty()){
    cout << waitTimes->remove() << " ";
  }
  cout << endl;
}
void Registrar::printIdleTimes(){
  while(!idleTimes->isEmpty()){
    cout << idleTimes->remove() << " ";
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
