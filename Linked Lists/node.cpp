// Name: Nima Naimi
// Course: CSS133
// Assignment #6: Linked Lists
// Date: February 17th, 2018
// Description: Allows the user to retrieve and set the node's data and pointer

#include "node.h"

// Constructor: initializes the node's data to the value passed
Node::Node(int data) : data{data} {};

// Returns the integer contained in the data of the node
int Node::getData() const {
    return data;
}

// Sets the integer contained in the data of the node
void Node::setData(int data) {
    this->data = data;
}

// Returns a node pointer to the node that the node is pointing to
Node* Node::getNextPtr() {
    return nextPtr;
}

// Sets the pointer of the current node to the passed node pointer
void Node::setNextPtr(Node* next) {
    nextPtr = next;
}
