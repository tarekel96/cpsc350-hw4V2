#ifndef LIST_NODE_H
#define LIST_NODE_H
/*
  * @name ListNode - represents a Doubly Linked List Node
  * @author Tarek El-Hajjaoui
  * @version 1.0
*/
template<class T>
class ListNode{
    public:
        ListNode(); /* Default Constructor */
        ListNode(T d); /* Overloaded Constructor */
        ~ListNode(); /* Destructor */

        T data;

        ListNode *next; /* Next Pointer */
        ListNode *prev; /* Previous Pointer */
};
/* Default Constructor - NULL out fields */
template<class T>
ListNode<T>::ListNode(){
    data = NULL;
    next = NULL;
    prev = NULL;
}
/* Default Constructor - set data and NULL out other fields */
template<class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL;
    prev = NULL;
}
/* Destructor - delete next or prev if exits and NULL out fields */
template<class T>
ListNode<T>::~ListNode(){
    if(next != NULL) delete next;
    if(prev != NULL) delete prev;
    next = NULL;
    prev = NULL;
}

#endif
