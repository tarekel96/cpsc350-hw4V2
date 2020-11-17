#ifndef LIST_H
#define LIST_H
/*
  * @name List - intereface (pure virtual class) of a List
  * @author Tarek El-Hajjaoui
*/
template<class T>
class List{
  public:
    List(){} /* Default Constructor */
    virtual ~List(){} /* Destructor */

    virtual unsigned int getSize() = 0; /* the number of Nodes in the List */
    virtual bool isEmpty() = 0; /* whether or not the list is empty */

    virtual void insertFront(T d) = 0; /* inserts a new element at the front of the list */
    virtual T getFront() = 0; /* returns the front element of the List, but does not remove it */
    virtual T removeFront() = 0; /* removes the front element of the List and returns it */
    virtual void insertBack(T d) = 0; /* inserts a New element to the back of the List */
    virtual T getBack() = 0; /* returns the back node of the List, but does not remove it */
    virtual T removeBack() = 0; /* removes the back element of the List and returns it */
    virtual int find(T d) = 0; /* searches for the first instance of specified object and returns position number */
    virtual T deletePos(int pos) = 0; /* removes and returns the node at the given position */

    virtual void printList() = 0; /* prints contents of the list - array format */
};
#endif
