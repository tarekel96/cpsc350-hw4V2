#ifndef GENQUEUE_H
#define GENQUEUE_H
/*
  * @name GenQueue - represents a Queue that is implemented with a double linked list
  * @author Tarek El-Hajjaoui
*/
#include "GenDoublyLinkedList.h"
template<class T>
class GenQueue{
  private:
    unsigned int numElements; /* number of objects in Queue */
    GenDoublyLinkedList<T>* myQueue; /* double linked list where objects are stored in Queue */

  public:
    GenQueue(); /* Default Constructor */
    ~GenQueue(); /* Destructor */

    /* CORE FUNCTIONS */
    void insert(T d); // enqueue
    T remove(); // dequeue

    /* AUXILIARY FUNCTIONS */
    T peek();
    bool isEmpty();
    unsigned int getSize();

    void printQueue(); /* prints contents of Queue */
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
  return myQueue->getFront(); /* gets the front of double linked list but does not remove it */
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
  myQueue->insertBack(d); /* for Queues, objects are inserted to the back */
  numElements++;
}
template<class T>
T GenQueue<T>::remove(){
  if(isEmpty()) runtime_error("ERROR: QUEUE IS EMPTY");
  numElements--;
  return myQueue->removeFront(); /* for Queues, objects are removed from the front */
}
template<class T>
void GenQueue<T>::printQueue(){
  myQueue->printList();
}
#endif
