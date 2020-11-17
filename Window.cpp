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
    /* time remaining is how much time current student needs */
    m_timeRemaining = S->getTimeNeeded();
    /* update current student waiting status */
    CurrentStudent->setWaiting(false);
    /* update window helping status */
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
  m_idleTime++;
}
void Window::decrementTimeRemaining(){
  --m_timeRemaining;
  /* if no more time remaining for current student - make the Window available */
  if(m_timeRemaining == 0) setHelping(false);
}
void Window::updateWindow(){
  /* if currently helping student, decrement time remaining */
  if(m_isHelping) decrementTimeRemaining();
  /* else increment window's idle time */
  else incrementIdleTime();
}
void Window::addToIdleTime(int timeAmount){
  m_idleTime += timeAmount;
}
