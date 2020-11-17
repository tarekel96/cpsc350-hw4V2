#include "Window.h"

Window::Window(){
  CurrentStudent = NULL;
  m_isHelping = false;
  m_idleTime = 0;
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
void Window::incrementIdleTime(){
  m_idleTime++;
}
void Window::decrementTimeRemaining(){
  cout << "inside decrementTimeRemaining " << endl;
  --m_timeRemaining;
  if(m_timeRemaining == 0) setHelping(false);
}
void Window::updateWindow(){
  if(m_isHelping) decrementTimeRemaining();
  else incrementIdleTime();
}
