#include <iostream>
#include "GenQueue.h"
#include <string>
#include "FileError.h"
#include "Driver.h"
using namespace std;

int main(int argc, char ** argv){

  FileError* FE = new FileError();
    while(true){
      FE->setFile(FE->getFile());
      if(FE->pass()) break;
      else{
        cerr << "ERROR: INVALID FILE INPUT" << endl;
        continue;
      }
    }
    string file = FE->getFileValue();
    delete FE;

    Driver* sim = new Driver(file);
    // sim->printFields();
    
    delete sim;

    return 0;
}

// DOUBLY LINKED LIST TEST
// GenDoublyLinkedList<char>* DLL = new GenDoublyLinkedList<char>();
//
// DLL->insertFront('a');
// DLL->insertBack('b');
// DLL->insertFront('c');
// DLL->printList();
//
// cout << "c position: " << DLL->find('c') << endl;
//
// DLL->removeFront();
// DLL->printList();
// cout << "c position: " << DLL->find('c') << endl;
//
// DLL->removeBack();
// DLL->printList();
//
// delete DLL;
//
// GenDoublyLinkedList<int>* DLL2 = new GenDoublyLinkedList<int>();
//
// DLL2->insertFront(1);
// DLL2->insertBack(2);
// DLL2->insertBack(2);
// DLL2->insertFront(3);
// DLL2->printList();
//
// cout << "3 position: " << DLL2->find(3) << endl;
//
// DLL2->removeFront();
// DLL2->printList();
// cout << "3 position: " << DLL2->find(3) << endl;
//
// DLL2->removeBack();
// DLL2->printList();
//
// cout << "Deleting position 0: " << DLL2->deletePos(0) << endl;
// DLL2->printList();
//
// delete DLL2;

// QUEUE TEST
// GenQueue<int>* Q = new GenQueue<int>();
// Q->insert(1);
// Q->insert(2);
// Q->insert(3);
// Q->printQueue();
// cout << "size: " <<  Q->getSize() << endl;
// cout << "is empty: " << Q->isEmpty() << endl;
//
// delete Q;
// QUEUE TEST
// GenQueue<int>* Q = new GenQueue<int>();
// Q->insert(1);
// Q->insert(2);
// Q->insert(3);
// Q->printQueue();
// cout << "size: " <<  Q->getSize() << endl;
// cout << "is empty: " << Q->isEmpty() << endl;
//
// delete Q;
