// Name: Nima Naimi
// Date: January 20, 2018
// Assignment #3: Library Expanded
// Description: Allows the user to create a library with a given name, add and
// ............ remove books from it, display a list of all the books stored,
// ............ search for a book within the library, and sorts the library in
// ............ alphabetical order.

#include "library.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// Constructs a library class with the given library name
Library::Library(const string& name) : name{name}
{
    cout << "Library " + name + " created" << endl;
}

// Default destructor class
Library::~Library()
{

}

// Adds a book to the library with the given name. Returns true if the book
// is added, false if the book already exists in the library.
bool Library::addBook(const string& name)
{
    if (searchBook(name))
        return false;
    library.push_back(name);
    sorted = false;
    return true;
}

// Removes the book within the library with the given name
void Library::removeBook(const string& name)
{
    library.erase(remove(library.begin(), library.end(), name), library.end());
}

// Lists all the books currently in the library by printing them to the screen
void Library::listAllBooks() const
{
    cout << name + " books are:" << endl;;
    for (string i : library)
        cout << i << endl;
}

// Sorts the library in alphabetical order
void Library::sortBooks()
{
    sort(library.begin(), library.end());
    sorted = true;
}

// Returns whether or not the library is sorted
bool Library::isSorted() const
{
    return sorted;
}

// Searches the library for a book of the given name and returns whether or not
// it is found
bool Library::searchBook(const string& book) const
{
    return binary_search(library.begin(), library.end(), book);
}
