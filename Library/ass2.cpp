//.....Name: Nima Naimi
//.....Date: January 14, 2018
//.....Assignment #2: Library
//.....Description: Runs a series of tests on the library class to ensure it is
//................. working properly. Tests adding multiple books, removing
//................. a book in the beginning or end of the library's list,
//................. and removing a book twice, then displays the success/fail.

#include <iostream>
#include "library.h"

using namespace std;

void basicTests() {
    Library libs("UWB");
    libs.addBook("Don Quixote");
    libs.addBook("In Search of Lost Time");
    libs.addBook("Ulysses");
    libs.addBook("The Odyssey");
    libs.listAllBooks();

    // should return true
    bool result = libs.isInLibrary("The Odyssey");
    if (result)
        cout << "OK: Added book is in library" << endl;
    else
        cout << "ERR: Added book is not in library" << endl;

    // should return false, cannot add book twice
    result = libs.addBook("The Odyssey");
    if (result)
        cout << "ERR: Adding book already in library returns true" << endl;
    else
        cout << "OK: Adding book already in library returns false" << endl;

    // test remove
    libs.removeBook("The Odyssey");
    // should return false, book removed
    result = libs.isInLibrary("The Odyssey");
    if (result)
        cout << "ERR: Removed book is still in library" << endl;
    else
        cout << "OK: Removed book is not in library" << endl;

    // should return false, cannot remove book twice
    result = libs.removeBook("The Odyssey");
    if (result)
        cout << "ERR: Should not be able to remove book twice" << endl;
    else
        cout << "OK: Cannot remove book twice" << endl;
    result = libs.addBook("Ender's Game");
    if (result)
        cout << "OK: Added Ender's Game to the library" << endl;
    else
        cout << "ERR: Adding book in library returns false" << endl;
    result = libs.removeBook("Don Quixote");
    if (result)
        cout << "OK: Removed Don Quixote from the library" << endl;
    else
        cout << "ERR: Didn't remove book" << endl;
}

int main() {
    basicTests();
    return 0;
}
