// Name: Nima Naimi
// Course: CSS133
// Assignment #6: Linked Lists
// Date: February 17th, 2018
// Description: Tests the list class functions

#include "list.h"
#include <iostream>

using namespace std;

void testInsertSorted(List& test) {
    for (int i = 0; i < 10; ++i) {
        int r = rand() % 100;
        test.insertSorted(r);
        cout << "Added " << r << " to the list." << endl;
    }
}

void testInsertFront(List& test) {
    cout << "Testing insertAtFront()" << endl;
    for (int i = 0; i < 10; ++i) {
        int r = rand() % 100;
        test.insertAtFront(r);
        cout << "Added " << r << " to the list." << endl;
    }
    cout << "The list now contains: ";
    test.print();
    cout << endl << endl;
}

void testInsertBack(List& test) {
    cout << "Testing insertAtBack()" << endl;
    for (int i = 0; i < 10; ++i) {
        int r = rand() % 100;
        test.insertAtBack(r);
        cout << "Added " << r << " to the list." << endl;
    }
    cout << "The list now contains: ";
    test.print();
    cout << endl << endl;
}

void testRemoveFront(List& test) {
    int value;
    cout << "Testing removeFromFront()" << endl;
    cout << "The list contains the values: ";
    test.print();
    cout << endl;
    while (!test.isEmpty()) {
        test.removeFromFront(value);
        cout << "Removed " << value << " from the list." << endl;
    }
    cout << endl;
}

void testRemoveBack(List& test) {
    int value;
    cout << "Testing removeFromBack()" << endl;
    cout << "The list contains the values: ";
    test.print();
    cout << endl;
    while (!test.isEmpty()) {
        test.removeFromBack(value);
        cout << "Removed " << value << " from the list." << endl;
    }
    cout << endl;
}

void testRemoveFromEmpty(List& test) {
    cout << "Testing removing from empty list:" << endl;
    int value;
    while (!test.isEmpty()) {
        test.removeFromFront(value);
    }
    bool emptyRemove = test.removeFromFront(value);
    cout << "removeFromFront() returned ";
    if (emptyRemove)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    emptyRemove = test.removeFromBack(value);
    cout << "removeFromBack() returned ";
    if (emptyRemove)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

int main()
{
    List test;
    testInsertBack(test);
    testRemoveBack(test);
    testInsertFront(test);
    testRemoveFront(test);
    testRemoveFromEmpty(test);
    return 0;
}
