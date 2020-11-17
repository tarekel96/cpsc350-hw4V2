#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <string>
#include <vector>
#include "GenQueue.h"
#include "Student.h"
class Window{
  private:
    Student* CurrentStudent;
    bool m_isHelping;
    int m_idleTime;
    int m_timeRemaining;
  public:
    Window();
    Window(int timeUntilFirstStudent);
    ~Window();

    void helpStudent(Student* S);
    void stopHelp();
    bool isHelping();
    int getIdleTime();

    void setHelping(bool helping);
    void incrementIdleTime();
    void decrementTimeRemaining();
    void updateWindow();
    void addToIdleTime(int timeAmount);
};
#endif
