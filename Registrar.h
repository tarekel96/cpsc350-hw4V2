#ifndef REGISTRAR_H
#define REGISTRAR_H
/*
  * @name Registrar - represents the Registrar Office
  * @author Tarek El-Hajjaoui
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "Student.h"
#include "GenQueue.h"
#include "Window.h"
using namespace std;
class Registrar{
  private:
    GenQueue<Student*>* Line; /* Queue of Students that represents Registrar Line */
    GenQueue<int>* waitTimes; /* Queue of Student wait times */
    int* waitTimesArray; /* pointer array of Student wait times */
    GenQueue<int>* idleTimes; /* Queue of Window idle times */
    int* idleTimesArray; /* pointer array of Window idle times */
    Window ** Windows; /* pointer array of Window pointers - represents the Windows at the Registrar Office */
    int m_numberOfWindows; /* number of Windows at the Registrar Office */
    int m_timeOfDay; /* current time of the day */
    int m_timeUntilFirstStudent; /* the time before first student arrives */
    string m_outputFile; /* name of output file */
    ofstream outFile; /* object that writes to output file */
    bool m_outToFile; /* whether or not to output to another file */
  public:
    Registrar(); /* Default Constructor */
    /*
      * Overloaded Constructor
      * @param numberOfWindows - the number of windows at Registrar Office
      * @param timeOfDay - the start time of the day
      * @param studentTimesNeeded - Queue of student times needed at window
    */
    Registrar(int numberOfWindows, int timeOfDay, GenQueue<int>*studentTimesNeeded);
    Registrar(int numberOfWindows, int timeOfDay, GenQueue<int>*studentTimesNeeded, string outputFile);
    ~Registrar(); /* Destructor */


    // int getNumberOfWindows();
    // int getNumOfWindows();
    /* ACCESSORS */

    /* MUTATORS */
    void setNumberOfWindows(int numberOfWindows);
    void addStudent(Student* S); /* adds a student to the Line Queue */

    void incrementTimeOfDay(); /* increments m_timeOfDay field */
    void incrementRemainingStudentsWait(); /* finds remaining students in line and increments their wait times */

    /* STATISTICS FUNCTIONS */
    void calcStats(); /* calculates all of the stats and displays them out to the console */
    float calcMedian(int* arr, int size);
    float calcMean(int* arr, int size);
    int findLongestTime(int* arr, int size);
    int calcOverMins(int* arr, int size, int min);

    /* main method for operating the class */
    void run();

    /* PRINT FUNCTIONS */
    void printFields();
    void printWaitTimes();
    void printIdleTimes();
};
#endif
