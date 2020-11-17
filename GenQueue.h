#ifndef GENQUEUE_H
#define GENQUEUE_H
#include "GenDoublyLinkedList.h"

template<class T>
class GenQueue{
  private:
    unsigned int mSize;
    unsigned int numElements;

    GenDoublyLinkedList<T>* myQueue; // pointer to a char - array

  public:
    GenQueue();
    ~GenQueue();

    // core functions
    void insert(T d); // enqueue
    T remove(); // dequeue

    // aux functions
    T peek();
    bool isEmpty();
    unsigned int getSize(); // unsigned - cannot be negative
    void printQueue();
};

template<class T>
GenQueue<T>::GenQueue(){
  myQueue = new GenDoublyLinkedList<T>();
  numElements = 0;
}

template<class T>
GenQueue<T>::~GenQueue(){
  delete myQueue;
}

template<class T>
T GenQueue<T>::peek(){
  if(isEmpty()) runtime_error("ERROR: QUEUE IS EMPTY");
  return myQueue->getFront();
}

template<class T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}

template<class T>
unsigned int GenQueue<T>::getSize(){
  return numElements;
}

template<class T>
void GenQueue<T>::insert(T d){
  myQueue->insertBack(d);
  numElements++;
}

template<class T>
T GenQueue<T>::remove(){
  if(isEmpty()) runtime_error("ERROR: QUEUE IS EMPTY");

  numElements--;
  return myQueue->removeFront();
}

template<class T>
void GenQueue<T>::printQueue(){
  myQueue->printList();
}
#endif
