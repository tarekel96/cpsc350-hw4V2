#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;
class Student{
  private:
    int m_timeNeeded;
    int m_timeWaited;
    bool m_isWaiting;;
  public:
    Student();
    Student(int timeNeeded);
    ~Student();
    Student(Student& S);

    bool isWaiting();

    int getTimeNeeded();
    int getTimeWaited();

    void setNeeded(int timeNeeded);
    void setWaiting(bool waiting);
    void setTimeWaited(int waitTime);

    void incrementWait();

};
#endif
