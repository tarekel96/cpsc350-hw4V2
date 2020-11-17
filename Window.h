#ifndef WINDOW_H
#define WINDOW_H
/*
  * @name Window - represents a Window of the registrar office
  * @author Tarek El-Hajjaoui
*/
#include <iostream>
#include <string>
#include "GenQueue.h"
#include "Student.h"
class Window{
  private:
    Student* CurrentStudent; /* current student the window is helping */
    bool m_isHelping; /* true if helping student and false otherwise */
    int m_idleTime; /* how long the window has been idle */
    int m_timeRemaining; /* time left for helping current student */
  public:
    Window(); /* Default Constructor */
    /*
      * Overloaded Constructor - takes in time until first student
    */
    Window(int timeUntilFirstStudent);
    ~Window(); /* Destructor */

    /* ACCESSORS */
    bool isHelping();
    int getIdleTime();

    /* MUTATORS */
    void setHelping(bool helping);

    /* HELPER FUNCTIONS */
    void helpStudent(Student* S);
    void stopHelp();
    void incrementIdleTime();
    void decrementTimeRemaining();
    void updateWindow(); /* updates idle time and decrements time remaining depending on if currently helping student */
    void addToIdleTime(int timeAmount);
};
#endif
