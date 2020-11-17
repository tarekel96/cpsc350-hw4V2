#ifndef GENODOUBLE_LINKED_LIST_H
#define GENODOUBLE_LINKED_LIST_H
/*
  * @name GenDoublyLinkedList - represents a DoublyLinkedList that is defined with template classes
  * @author Tarek El-Hajjaoui
  * @version 1.0
*/
#include <iostream>
#include "ListNode.h"
using namespace std;

template<class T>
class GenDoublyLinkedList {
    private:
        ListNode<T> *front;  /* Front of the List */
        ListNode<T> *back;  /* Back of the List */
        unsigned int size;  /* Number of Nodes in the List */

    public:
        GenDoublyLinkedList(); /* Default Constructor */
        ~GenDoublyLinkedList(); /* Destructor */

        unsigned int getSize(); /* the number of Nodes in the List */
        bool isEmpty(); /* whether or not the list is empty */

        void insertFront(T d); /* inserts a new Node at the front of the list */
        T getFront(); /* returns the front node of the List, but does not remove it */
        T removeFront(); /* removes the front node of the List and returns it */
        void insertBack(T d); /* inserts a New node to the back of the List */
        T getBack(); /* returns the back node of the List, but does not remove it */
        T removeBack(); /* removes the back node of the List and returns it */
        int find(T d); /* searches for the first instance of specified object and returns position number */
        T deletePos(int pos); /* removes and returns the node at the given position */

        T removeNode(T key); /* removes the first object in List that is the same as parameter */
        
        void printList(); /* prints list */

        void sort(); /* Sorting algorithm for sorting in ascending order - for number types only */
};

template<class T>
GenDoublyLinkedList<T>::GenDoublyLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}
template<class T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList(){
}
template<class T>
unsigned int GenDoublyLinkedList<T>::getSize(){
    return size;
}
template<class T>
bool GenDoublyLinkedList<T>::isEmpty(){
    return size == 0;
}
template<class T>
void GenDoublyLinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);
    /* set first node as front and back */
    if(size == 0){
        front = node;
        back = node;
    }
    /* set new node to point to front and set front to the new node */
    else{
        node->next = front;
        front->prev = node;
        front = node;
    }
    size++;
}
template<class T>
T GenDoublyLinkedList<T>::getFront(){
    if(size == 0) runtime_error("ERROR: LIST IS EMPTY. CANNOT GETFRONT.\n");
    return front->data;
}
template<class T>
T GenDoublyLinkedList<T>::removeFront(){
    if(size == 0) runtime_error("ERROR: LIST IS EMPTY. CANNOT REMOVEFRONT\n");
    T temp = front->data;
    ListNode<T> *ft = front;
    /* List only has one Node - NULL out front and back */
    if(size == 1){
        front = NULL;
        back = NULL;
    }
    /* List has more than 1 Node */
    else{
        front = front->next; /* assign new front */
        front->prev = NULL; /* NULL prev pointer to deleted front */
    }
    ft->next = NULL;
    delete ft;
    size--;

    return temp;
}
template<class T>
void GenDoublyLinkedList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);
    /* if first node, set it to front and back */
    if(size == 0){
        back = node;
        front = node;
    }
    else{
        node->prev = back; /* assign prev pointer to original back */
        back->next = node; /* assign next pointer to new back for the original back */
        back = node; /* assign new back */
    }

    size++;
}
template<class T>
T GenDoublyLinkedList<T>::getBack(){
    if(size == 0) runtime_error("ERROR: LIST IS EMPTY. CANNOT GETBACK\n");
    return back->data;
}
template<class T>
T GenDoublyLinkedList<T>::removeBack(){
    if(size == 0) runtime_error("ERROR: LIST IS EMPTY. CANNOT REMOVEBACK\n");

    T temp = back->data; /* temp var to hold back's data field */
    ListNode<T> *bt = back;
    /* if only one Node, NULL out back and front */
    if(size == 1){
      back = NULL;
      front = NULL;
    }
    else{
        back = back->prev; /* assigns the new back, which is original's back prev */
        back->next = NULL; /* NULL out next pointer for new back */
    }

    bt->prev = NULL; /* NULL out prev pointer to new back before deleting */
    delete bt;
    size--;

    return temp;
}
template<class T>
int GenDoublyLinkedList<T>::find(T d){
    if(size == 0) runtime_error("ERROR: LIST IS EMPTY. CANNOT FIND\n");
    ListNode<T> *curr = front;
    int index = -1;

    while(curr != NULL){
        index++;
        if(curr->data == d){
            break;
        }
        else{
            curr = curr->next;
        }
    }

    if(curr == NULL){
        index = -1; /* -1 represents the value was not found */
    }

    return index;
}
template<class T>
T GenDoublyLinkedList<T>::deletePos(int pos){
    if(size == 0) runtime_error("ERROR: LIST IS EMPTY. CANNOT DELETEPOS\n");
    if(pos == 0) return removeFront();
    else if(pos == size-1) return removeBack();
    else if(pos >=size || pos < 0) runtime_error("ERROR: INDEX IS OUT OF BOUNDS. CANNOT GETPOS\n");

    ListNode<T> *atPos = front;
    ListNode<T> *beforePos;
    ListNode<T> *afterPos;

    for(int i = 0; i < pos; i++){
        atPos = atPos->next;
        beforePos = atPos->prev;
        afterPos = atPos->next;
    }

    beforePos->next = afterPos;
    afterPos->prev = beforePos;

    T temp = atPos->data;
    atPos->next = NULL;
    atPos->prev = NULL;
    delete atPos;

    size--;

    return temp;

}
template<class T>
T GenDoublyLinkedList<T>::removeNode(T key){
  // make sure the list is not empty TODO
  ListNode<T>* curr = front;
  while(curr->data != key){
    curr = curr->next;
    if(curr == NULL){
      return -1;
    }
  }
  // we found the value, now lets delete it 3 scenarios - front, middle, back
  if(curr == front){
    front = curr->next;
    front->prev = NULL;
  }
  else if(curr == back){
    back = curr->prev;
    back->next = NULL;
  }
  else {
    // it is not the front or the back, somewhere in the middle
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
  }
  curr->next = NULL;
  curr->prev = NULL;
  T temp = curr->data;
  size--;
  delete curr;
  return temp;
}
template<class T>
void GenDoublyLinkedList<T>::printList(){
    ListNode<T> *curr = front;
    while(curr != NULL){
        if(curr == front) cout << "[" << curr->data  << ", ";
        if(curr->next == NULL) cout << curr->data << "]";
        else cout << curr->data << ", ";

        curr = curr->next;
    }
    cout << endl;
}

template<class T>
void GenDoublyLinkedList<T>::sort(){
    bool swap;
    /* bubble sort algorithm */
}



#endif //GENODOUBLE_LINKED_LIST_H
