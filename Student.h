#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Student{
  private:
    int m_timeEntered;
    int m_timeLeft;
    int m_timeNeeded;
    int m_timeWaited;
    bool m_isWaiting;
  public:
    Student();
    Student(int timeEntered, int timeNeeded);
    ~Student();
    Student(Student& S);

    bool isWaiting();

    int getTimeNeeded();
    int getTimeWaited();
    int getTimeWaited(int timeLeft);
    int getTimeEntered();

    void setNeeded(int timeNeeded);
    void setWaiting(bool waiting);
    void setTimeWaited(int waitTime);

    void incrementWait();
    void calculateWaitTime(int timeLeft);

};
#endif
