//.....Name: Nima Naimi
//.....Date: January 14, 2018
//.....Assignment #2: Library
//.....Description: Stores the name of the library, number of books in the
//................. library, and the names of all the books currently stored.

#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>

using namespace std;

class Library
{
    public:
        // Constructs a library class with the given library name
        Library(const string& libraryName);
        virtual ~Library();
        // Add a new book, return true for success, false if book already in
        // library
        bool addBook(const string& name);
        // Remove a book, return true for success, false if book not in library
        bool removeBook(const string& name);
        // List all books in library
        void listAllBooks() const;
        // Return true if book in library, false otherwise
        bool isInLibrary(const string& name) const;
    private:
        int numOfBooks{0}; // Number of books currently in the library
        string libraryName; // Name of the library
        string library[100]; // Stores the names of up to 100 books
};

#endif // LIBRARY_H
