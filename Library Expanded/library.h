// Name: Nima Naimi
// Date: January 20, 2018
// Assignment #3: Library Expanded
// Description: Stores the name of a library, the names of the books it
// ............ contains, and whether or not it is sorted.

#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <vector>

using namespace std;

class Library
{
    public:
        // Constructs a library class with the given library name
        Library(const string& name);
        // Class destructor
        virtual ~Library();
        // Add a new book, return true for success, false if book already in
        // library
        bool addBook(const string& name);
        // Remove a book, return true for success, false if book not in library
        void removeBook(const string& name);
        // List all books in library
        void listAllBooks() const;
        // Sorts the books in the library in alphabetical order
        void sortBooks();
        // Returns if the books in the library are sorted or not
        bool isSorted() const;
        // Searches the library for a book--returns true if found, false if not
        bool searchBook(const string& book) const;

    private:
        string name{"Library"}; // Name of the library (default is "Library")
        vector<string> library; // Stores the names of books
        bool sorted{true}; // Keeps track of if the library is sorted or not
};

#endif // LIBRARY_H
