// Name: Nima Naimi
// Course: CSS133
// Assignment #6: Linked Lists
// Date: February 17th, 2018
// Description: Stores pointers to the beginning and end of the list

#ifndef LIST_H
#define LIST_H
#include "node.h"

class List
{
    public:
        List(); // empty constructor
        ~List(); // destructor, delete nodes created
        void print() const;  // prints the items in the list
        void insertAtFront(int value);
        void insertAtBack(int value);
        bool removeFromFront(int& value);  // value is set to the value removed
        bool removeFromBack(int& value);  // value is set to the value removed
        bool isEmpty() const;
        // insert a new value keeping the List sorted in increasing order
        void insertSorted(int value);
    private:
        Node* headPtr {nullptr};
        Node* tailPtr {nullptr};
        Node* makeNewNode(int data) const;
};

#endif // LIST_H
