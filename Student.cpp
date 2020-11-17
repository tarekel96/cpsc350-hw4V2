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
int Student::getTimeEntered(){
  return m_timeEntered;
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
  m_timeLeft = timeLeft;
  setTimeWaited(abs(m_timeLeft - m_timeEntered)); /* abs ensures no negative times */
}
string Student::toString(){
  string ret = "";
  ret += "Time Entered: ";
  ret += to_string(getTimeEntered());
  ret += " \n";
  ret += "Time Left: ";
  ret += to_string(m_timeLeft);
  ret += " \n";
  ret += "Time Needed: ";
  ret += to_string(getTimeNeeded());
  ret += " \n";
  ret += "Time Waited: ";
  ret += to_string(getTimeWaited());
  ret += " \n";
  ret += "Is Waiting: ";
  ret += to_string(isWaiting());
  ret += " \n";
  return ret;
}
