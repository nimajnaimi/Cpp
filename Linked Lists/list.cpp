// Name: Nima Naimi
// Course: CSS133
// Assignment #6: Linked Lists
// Date: February 17th, 2018
// Description: Allows the user to add to or remove the beginning or end of
// ............ the list, or add to the list in an increasing sorted order.
// ............ Also can print out the list's contents.

#include "list.h"
#include "node.h"
#include <iostream>

using namespace std;

// Default empty constructor
List::List() {}

// Destructor: deletes all nodes within the list
List::~List() {
    Node* curr = headPtr;
    while (curr != nullptr) {
        Node * tmpPtr = curr;
        curr = curr->getNextPtr();
        delete tmpPtr;
    }
}

// Creates a new node
Node* List::makeNewNode(int data) const {
    return new Node(data);
}

// Returns if the list is empty or not
bool List::isEmpty() const {
    return headPtr == nullptr;
}

// Prints all the contents of the list on a single line
void List::print() const {
    Node* curr = headPtr;
    while (curr != nullptr) {
        cout << curr->getData() << " ";
        curr = curr->getNextPtr();
    }
}

// Inserts a node at the front of the list
void List::insertAtFront(int value) {
    Node* n = makeNewNode(value);
    if (!isEmpty()) {
        n->setNextPtr(headPtr);
        headPtr = n;
    } else {
        headPtr = n;
        tailPtr = n;
    }
}

// Inserts a node at the end of the list
void List::insertAtBack(int value) {
    Node* n = makeNewNode(value);
    if (!isEmpty()) {
        tailPtr->setNextPtr(n);
        tailPtr = n;
    } else {
        headPtr = n;
        tailPtr = n;
    }
}

// Removes a node at the front of the list. Returns true
// if successful, false if not.
bool List::removeFromFront(int& value) {
    if (!isEmpty()) {
        Node* tmpPtr = headPtr;
        value = headPtr->getData();
        headPtr = headPtr->getNextPtr();
        delete tmpPtr;
        // Successfully removed a node from the list
        return true;
    }
    // Cannot remove a node from an empty list
    return false;
}

// Removes a node at the back of the list. Returns true
// if successful, false if not. Sets value to the deleted node's data
bool List::removeFromBack(int& value) {
    if (!isEmpty()) {
        // If there is only one node in the list:
        if (headPtr->getNextPtr() != nullptr) {
            Node* prevPtr = headPtr;
            Node* currPtr = headPtr->getNextPtr();
            value = tailPtr->getData();
            while (currPtr->getNextPtr() != nullptr) {
                currPtr = currPtr->getNextPtr();
                prevPtr = prevPtr->getNextPtr();
            }
            delete currPtr;
            // Forces the last element of the list to point to null,
            // not the memory location of the deleted node.
            prevPtr->setNextPtr(nullptr);
            tailPtr = prevPtr;
        // If there are multiple nodes within the list:
        } else {
            value = headPtr->getData();
            delete headPtr;
            headPtr = nullptr;
            tailPtr = nullptr;
        }
        // Successfully removed a node from the list
        return true;
    }
    // Cannot remove a node from an empty list
    return false;
}

// Inserts a node into the list at its corresponding position to
// keep the list sorted. List is sorted in increasing order.
void List::insertSorted(int value) {
    if (!isEmpty()) {
        if (value <= headPtr->getData()) {
            insertAtFront(value);
        } else if (value >= tailPtr->getData()) {
            insertAtBack(value);
        // If the value belongs in the middle of the list:
        } else {
            Node* prevPtr = headPtr;
            Node* currPtr = headPtr->getNextPtr();
            while (value >= currPtr->getData()) {
                currPtr = currPtr->getNextPtr();
                prevPtr = prevPtr->getNextPtr();
            }
            Node* n = makeNewNode(value);
            prevPtr->setNextPtr(n);
            n->setNextPtr(currPtr);
        }
    } else {
        Node* n = makeNewNode(value);
        headPtr = n;
        tailPtr = n;
    }
}
