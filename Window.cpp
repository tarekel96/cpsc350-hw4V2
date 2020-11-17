#include "Window.h"

Window::Window(){
  CurrentStudent = NULL;
  m_isHelping = false;
  m_idleTime = 0;
  m_timeRemaining = 0;
}
Window::Window(int timeUntilFirstStudent){
  CurrentStudent = NULL;
  m_isHelping = false;
  m_idleTime = timeUntilFirstStudent;
  m_timeRemaining = 0;
}
Window::~Window(){
  CurrentStudent = NULL;
}
void Window::helpStudent(Student* S){
	if(S == NULL) CurrentStudent = NULL;
	else{
		CurrentStudent = S;
    m_timeRemaining = S->getTimeNeeded();
    CurrentStudent->setWaiting(false);
    setHelping(true);
	}
}
void Window::setHelping(bool helping){
  m_isHelping = helping;
}
bool Window::isHelping(){
  return m_isHelping;
}
int Window::getIdleTime(){
  return m_idleTime;
}
void Window::incrementIdleTime(){
  cout << "in incrementIdleTime " << endl;
  m_idleTime++;
}
void Window::decrementTimeRemaining(){
  --m_timeRemaining;
  if(m_timeRemaining == 0) setHelping(false);
}
void Window::updateWindow(){
  if(m_isHelping) decrementTimeRemaining();
  else incrementIdleTime();
}
void Window::addToIdleTime(int timeAmount){
  m_idleTime += timeAmount;
}
