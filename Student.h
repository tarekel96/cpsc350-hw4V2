#ifndef STUDENT_H
#define STUDENT_H
/*
  * @name Student - represents a Student going to Registrar office
  * @author Tarek El-Hajjaoui
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Student{
  private:
    int m_timeEntered; /* time student entered line */
    int m_timeLeft;    /* time student left line */
    int m_timeNeeded;  /* time student needs at Window */
    int m_timeWaited; /* time the student waited */
    bool m_isWaiting; /* whether or not student is in line */
  public:
    Student(); /* Default Constructor */
    /*
      * Overloaded Constructor
      @param timeEntered - time the student entered line
      @param timeNeeded - time the student needs at Window
    */
    Student(int timeEntered, int timeNeeded);
    ~Student(); /* Destructor */
    Student(Student& S); /* Copy Constructor */

    /* ACCESSORS */
    bool isWaiting();
    int getTimeNeeded();
    int getTimeWaited();
    int getTimeEntered();

    /* MUTATORS */
    void setNeeded(int timeNeeded);
    void setWaiting(bool waiting);
    void setTimeWaited(int waitTime);

    /* HELPER FUNCTIONS */
    void incrementWait(); /* increments student's m_timeWaited */
    /*
      * @name calculateWaitTime - calculates how long a student waited by subtracting time left from time entered
      * @param timeLeft - time the student left the line
    */
    void calculateWaitTime(int timeLeft);
    /*
      * @name getTimeWaited - overloaded method that invokes calculateWaitTime before returning wait time
      * @param timeLeft - time the student left the line
    */
    int getTimeWaited(int timeLeft);

    string toString(); /* neatly prints out fields of student */

};
#endif
