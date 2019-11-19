//.....Name: Nima Naimi
//.....Date: January 14, 2018
//.....Assignment #2: Library
//.....Description: Stores a library of books. Can display a list of all books
//................. currently in the library and remove or add books.

#include "library.h"
#include <iostream>
#include <string>

using namespace std;

// Constructs a library class with the given library name
Library::Library(const string& libraryName) : libraryName{libraryName}
{
    cout << "Library " + libraryName + " created" << endl;
}

// Default destructor class
Library::~Library()
{
}

// Adds a book to the library with the given name. Returns true if the book
// is added, false if the book already exists in the library.
bool Library::addBook(const string& name)
{
    if (isInLibrary(name))
    {
        return false;
    }
    library[numOfBooks] = name;
    ++numOfBooks;
    return true;
}

// Removes the book within the library with the given name, returns true if
// removed, false if the book is not found
bool Library::removeBook(const string& name)
{
    for (int i{0}; i < numOfBooks; ++i)
    {
        if (library[i] == name)
        {
            library[i] = library[numOfBooks - 1];
            --numOfBooks;
            return true;
        }
    }
    return false;
}

// Lists all the books currently in the library by printing them to the screen
void Library::listAllBooks() const
{
    cout << libraryName + " books are:" << endl;;
    for (int i{0}; i < numOfBooks; ++i)
    {
        cout << library[i] << endl;
    }
}

// Returns true or false depending on if there is a book in the library
// with the given name
bool Library::isInLibrary(const string& name) const
{
    for (int i{0}; i < numOfBooks; ++i)
    {
        if (name == library[i])
        {
            return true;
        }
    }
    return false;
}
