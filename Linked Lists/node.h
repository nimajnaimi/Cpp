// Name: Nima Naimi
// Course: CSS133
// Assignment #6: Linked Lists
// Date: February 17th, 2018
// Description: Stores an integer and a pointer to the next node

#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        explicit Node(int data);
        int getData() const;
        void setData(int data);
        Node* getNextPtr();
        void setNextPtr(Node* next);
    private:
        int data;
        Node* nextPtr {nullptr};
};

#endif // NODE_H
