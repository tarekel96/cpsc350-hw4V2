#include "Student.h"

Student::Student(){
  m_timeNeeded = 1;
  m_timeWaited = 0;
  m_isWaiting = false;
}
Student::Student(int timeNeeded){
  m_timeNeeded = timeNeeded;
  m_timeWaited = 0;
  m_isWaiting = false;
}
Student::Student(Student& S){
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
