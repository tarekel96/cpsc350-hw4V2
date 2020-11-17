#include "Registrar.h"

Registrar::Registrar(){}
Registrar::Registrar(int numberOfWindows, int timeOfDay, GenQueue<int>* studentTimesNeeded){
  /* init Queues */
  waitTimes = new GenQueue<int>();
  idleTimes = new GenQueue<int>();
  m_numberOfWindows = numberOfWindows;
  /* populate Windows double pointer array */
  Windows = new Window*[m_numberOfWindows];
  for(int i = 0; i < m_numberOfWindows; ++i){
    Windows[i] = new Window(timeOfDay);
  }
  m_timeOfDay = timeOfDay;
  /* init Student Queue */
  Line = new GenQueue<Student*>();
  /* populate Student Queue - order matters */
  while(!studentTimesNeeded->isEmpty()){
    Line->insert(new Student(m_timeOfDay, studentTimesNeeded->remove()));
  }
}
Registrar::~Registrar(){
  delete Windows;
  delete Line;
  delete waitTimes;
  delete waitTimesArray;
  delete idleTimesArray;
}
/* main method for operating the class */
void Registrar::run(){
  while(!Line->isEmpty()){
    for(int i = 0; i < m_numberOfWindows; ++i){
      if(Windows[i]->isHelping()) Windows[i]->updateWindow();
    }

    bool allWindowsAreFull = true;
    int temp;
    /* iterate through Windows double pointer array */
    for(int i = 0; i < m_numberOfWindows; ++i){
      /* if there is an available window - help next student */
      if(Windows[i]->isHelping() == false && !Line->isEmpty()){
        allWindowsAreFull = false;
        /* insert wait time to waitTime Queue before removing student from line Queue */
        waitTimes->insert(Line->peek()->getTimeWaited(m_timeOfDay));
        if(Line->getSize() == 1){
          /* use peek here to not remove the next student in Line */
          temp = Line->peek()->getTimeNeeded();
        }
        Windows[i]->helpStudent(Line->remove());
      }
    }
    /* not all of the windows are full - increment each of those Window's idle time */
    if(allWindowsAreFull == false){
      for(int i = 0; i < m_numberOfWindows; ++i){
        if(Windows[i]->isHelping() == false){
          if(Line->getSize() == 0){
            Windows[i]->addToIdleTime(temp);
          }
          else {
            /* increments time idling */
            Windows[i]->updateWindow();
          }
        }
      }
    }
    /* increment time of day for each iteriation */
    incrementTimeOfDay();
  }
  for(int i = 0; i < m_numberOfWindows; ++i){
    idleTimes->insert(Windows[i]->getIdleTime());
  }
  /* calculate and display all stats at the end */
  calcStats();
}
void Registrar::incrementRemainingStudentsWait(){
  /* temporarily holds new Line Queue */
  GenQueue<Student*>* tempQ;
  tempQ = new GenQueue<Student*>();
  while(!Line->isEmpty()){
    Student* tempStudent = Line->remove();
    tempStudent->incrementWait();
    tempQ->insert(tempStudent);
  }
  Line = tempQ;
  delete tempQ;
}
void Registrar::incrementTimeOfDay(){
  m_timeOfDay++;
}
void Registrar::calcStats(){
  int waitSize = waitTimes->getSize();
  waitTimesArray = new int[waitSize];
  for(int i = 0; i < waitSize; ++i){
    waitTimesArray[i] = waitTimes->remove();
  }
  sort(waitTimesArray, waitTimesArray + waitSize);
  int idleSize = idleTimes->getSize();
  idleTimesArray = new int[idleSize];
  for(int i = 0; i < idleSize; ++i){
    idleTimesArray[i] = idleTimes->remove();
  }
  sort(idleTimesArray, idleTimesArray + idleSize);
  cout << "The mean student wait time: " << calcMean(waitTimesArray, waitSize) << endl;
  cout << "The median student wait time: " << calcMedian(waitTimesArray, waitSize) << endl;
  cout << "The max student wait time: " << findLongestTime(waitTimesArray, waitSize) << endl;
  cout << "The number of students who waited over 10 minutes: " << calcOverMins(waitTimesArray, waitSize, 10) << endl;
  cout << "The mean window idle time: " << calcMean(idleTimesArray, idleSize) << endl;
  cout << "The max window idle time: " << findLongestTime(idleTimesArray, idleSize) << endl;
  cout << "The number of windows who were idled for more than 5 minutes: " << calcOverMins(idleTimesArray, idleSize, 5) << endl;
}
/*
  * @name calcMedian - calculates median, got help from GeekForGeeks
  * @param arr - pointer array
  * @param size - size of poiner array
*/
float Registrar::calcMedian(int* arr, int size){
  sort(arr, arr + size);
  if (size % 2 != 0) return (float)arr[size / 2];

  return (float)(arr[(size - 1) / 2] + arr[size/ 2]) / 2.0;
}
/*
  * @name calcMean - calculates mean
  * @param arr - pointer array
  * @param size - size of poiner array
*/
float Registrar::calcMean(int* arr, int size){
  float sum = 0;
  float mean = 0;
  int countOfWaited = 0;
  for(int i = 0; i < size; ++i){
    if(arr[i] != 0){
      sum += arr[i];
      countOfWaited++;
    }
  }
  if(sum == 0) return 0;
  return mean = sum / countOfWaited;
}
/*
  * @name findLongestTime - determines which time in arr is longest
  * @param arr - pointer array
  * @param size - size of poiner array
*/
int Registrar::findLongestTime(int* arr, int size){
  int max = 0;
  for(int i = 0; i < size; ++i){
    if(arr[i] > max) max = arr[i];
  }
  return max;
}
/*
  * @name calcOverMins - counts number of elements in arr that are greater than min
  * @param arr - pointer array
  * @param size - size of poiner array
  * @param min - cutoff value to compare against
*/
int Registrar::calcOverMins(int* arr, int size, int min){
  int count = 0;
  for(int i = 0; i < size; ++i){
    if(arr[i] > min && arr[i] != 0) count++;
  }
  return count;
}
void Registrar::printFields(){
  cout << "Number of Windows " << m_numberOfWindows << endl;
  cout << "Time of day: " << m_timeOfDay << endl;
  cout << "Number of students: " << Line->getSize() << endl;
}
void Registrar::printWaitTimes(){
  while(!waitTimes->isEmpty()){
    cout << waitTimes->remove() << " ";
  }
  cout << endl;
}
void Registrar::printIdleTimes(){
  while(!idleTimes->isEmpty()){
    cout << idleTimes->remove() << " ";
  }
  cout << endl;
}
