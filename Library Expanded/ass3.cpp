// Name: Nima Naimi
// Date: January 20, 2018
// Assignment #3: Library Expanded
// Description: Tests the library class with function calls and displays the results

#include <iostream>

#include "library.h"

using namespace std;

void basicTests() {
    Library libs("UWB");
    libs.addBook("Ulysses");
    libs.addBook("Don Quixote");
    libs.addBook("In Search of Lost Time");
    libs.addBook("The Odyssey");
    libs.listAllBooks();
    cout << (libs.isSorted() ? "ERR" : "OK") << ": Library after add is not sorted" << endl;
    libs.sortBooks();
    libs.listAllBooks();
    cout << (libs.isSorted() ? "OK" : "ERR") << ": Library now sorted" << endl;

    bool result = libs.searchBook("The Odyssey");
    if (result)
        cout << "OK: Added book is in library" << endl;
    else
        cout << "ERR: Added book is not in library" << endl;

    // test remove
    libs.removeBook("The Odyssey");
    result = libs.searchBook("The Odyssey");
    if (result)
        cout << "ERR: Removed book is still in library" << endl;
    else
        cout << "OK: Removed book is not in library" << endl;
    libs.listAllBooks();
    cout << (libs.isSorted() ? "OK" : "ERR") << ": Library still sorted" << endl;
}

int main() {
    basicTests();
    return 0;
}
