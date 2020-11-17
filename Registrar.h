#ifndef REGISTRAR_H
#define REGISTRAR_H
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "GenQueue.h"
#include "Window.h"

using namespace std;
class Registrar{
  private:
    GenQueue<Student*>* Line;
    GenQueue<int>* waitTimes;
    GenQueue<int>* idleTimes;
    Window ** Windows;
    int m_numberOfWindows;
    int m_timeOfDay;

  public:
    Registrar();
    Registrar(int numberOfWindows, int timeOfDay, GenQueue<int>*studentTimesNeeded);
    ~Registrar();

    void setNumberOfWindows(int numberOfWindows);
    int getNumberOfWindows();
    void step();
    void addStudent(Student* S);
    bool studentsInLine();
    bool studentsAtWindow();
    Window** getWindows();
    int getNumOfWindows();

    void run();
    void incrementTimeOfDay();
    void incrementRemainingStudentsWait();
    void printWaitTimes();
    void printFields();
};
#endif
