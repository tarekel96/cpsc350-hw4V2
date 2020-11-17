#include "Student.h"

Student::Student(){
  m_timeEntered = 0;
  m_timeLeft = 0;
  m_timeNeeded = 1;
  m_timeWaited = 0;
  m_isWaiting = false;
}
Student::Student(int timeEntered, int timeNeeded){
  m_timeEntered = timeEntered;
  m_timeNeeded = timeNeeded;
  m_timeWaited = 0;
  m_isWaiting = false;
}
Student::Student(Student& S){
  m_timeEntered = S.m_timeEntered;
  m_timeNeeded = S.m_timeNeeded;
  m_timeWaited = S.m_timeWaited;
  m_isWaiting = S.m_isWaiting;
}
Student::~Student(){}
bool Student::isWaiting(){
  return (m_isWaiting == true);
}

int Student::getTimeNeeded(){
  return m_timeNeeded;
}
int Student::getTimeWaited(){
  return m_timeWaited;
}
int Student::getTimeWaited(int timeLeft){
  calculateWaitTime(timeLeft);
  return m_timeWaited;
}
void Student::setNeeded(int timeNeeded){
  m_timeNeeded = timeNeeded;
}
void Student::setWaiting(bool waiting){
  m_isWaiting = waiting;
}
void Student::setTimeWaited(int timeWaited){
  m_timeWaited = timeWaited;
}

void Student::incrementWait(){
  m_timeWaited++;
}
void Student::calculateWaitTime(int timeLeft){
  cout << "calulating wait time..." << endl;
  cout << "Time Enter: " << m_timeEntered << endl;
  cout << "Time Left: " << timeLeft << endl;
  cout << "WAIT TIME: " << abs(timeLeft - m_timeEntered) << endl;
  m_timeLeft = timeLeft;
  setTimeWaited(abs(m_timeLeft - m_timeEntered));
}
