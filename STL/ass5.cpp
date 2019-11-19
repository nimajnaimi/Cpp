// Name: Nima Naimi
// Assignment: Homework #5: STL
// Date: February 11th, 2018
// Description: Performs various standard library functions on vector
// ............ and list containers. Fills, displays, searches, removes
// ............ and swaps, and sorts elements in the containers.
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

// Takes a reference to an integer vector and displays its contents
void displayIntVector(const vector<int> &container) {
    ostream_iterator<int> out (cout, ", ");
    copy (container.cbegin(), container.cend(), out);
    cout << endl;
}

// Takes a reference to an integer list and displays its contents
void displayIntList(const list<int> &container) {
    ostream_iterator<int> out (cout, ", ");
    copy (container.cbegin(), container.cend(), out);
    cout << endl;
}

// Searches a referenced integer vector for the given integer and displays
// whether or not it's found. Displays its position in the container if found.
void searchIntVector(vector<int> &container, const int item) {
    vector<int>::iterator it;
    it = find(container.begin(), container.end(), item);
    if (it == container.cend())
        cout << "Not found " << item << endl;
    else {
        int pos = distance(container.begin(), it);
        cout << "Found " << item << " at index " << pos << endl;
    }
}

// return a random value between 1 and 1000
int random1000() {
    return (rand() % 1000) + 1;
}

// returns factorial of n
// factorial(1) = 1
// factorial(n) = n * factorial(n - 1)
int factorial(int n) {
    if (n == 0 || n == 1)
        return n;
    return n * factorial(n - 1);
}

// create a vector of size 10
// use fill to set all the values to 5
// use ostream_iterator and copy to display them
// use generate to replace the values with ones from random1000
// use ostream_iterator and copy to display them
// sort the vector using sort algorithm
// use ostream_iterator and copy to display the sorted vector
void display10vector() {
    cout << "* display10vector" << endl;
    vector<int> containerTen (10);
    fill (containerTen.begin(), containerTen.end(), 5);
    cout << "Initial Fill:" << endl;
    displayIntVector(containerTen);
    generate (containerTen.begin(), containerTen.end(), random1000);
    cout << "Random:" << endl;
    displayIntVector(containerTen);
    sort (containerTen.begin(), containerTen.end());
    cout << "Sorted:" << endl;
    displayIntVector(containerTen);
}

// add 20 random numbers between 1 and 10 to a list
// use ostream_iterator and copy to display them
// sort the list using sort function from list
// use ostream_iterator and copy to display the sorted vector
// use a lambda expression to display the square of each item
// use a lambda expression to sum all the items
void display20list() {
    cout << "* display10list" << endl;
    list<int> containerTwenty (20);
    for (int &i : containerTwenty) {
        i = (rand() % 10) + 1;
    }
    ostream_iterator<int> out (cout, ", ");
    cout << "Random:" << endl;
    displayIntList(containerTwenty);
    containerTwenty.sort();
    cout << "Sorted:" << endl;
    displayIntList(containerTwenty);
    containerTwenty.unique();
    cout << "Sorted Unique:" << endl;
    displayIntList(containerTwenty);
    cout << "Square via lambda:" << endl;
    for_each(containerTwenty.cbegin(), containerTwenty.cend(), [](auto i)
              {cout << i * i << " ";});
    cout << endl;
    int sum{0};
    for_each(containerTwenty.cbegin(), containerTwenty.cend(), [&sum](auto i)
              {sum += i;});
    cout << "Sum is: " << sum << endl;
}

// create a vector v such that
// v[0] is 0
// v[1] is factorial(1)
// v[2] is factorial(2)
// ..
// v[10] is factorial(10)
// use ostream_iterator and copy to display the vector
// use find to search for the number 100 in v
// and display a message with location if found, or state not found
// use find to search for the number 120 in v
// and display a message with location if found, or state not found
// swap the first and last item of the vector
// use ostream_iterator and copy to display the vector
// remove 120 from vector using erase/remove
// use ostream_iterator and copy to display the vector
void search10() {
    cout << "* search10" << endl;
    vector<int> searchTen(11);
    for (unsigned int i{0}; i < searchTen.size(); ++i) {
        searchTen[i] = factorial(i);
    }
    cout << "Factorials:" << endl;
    displayIntVector(searchTen);
    searchIntVector(searchTen, 100);
    searchIntVector(searchTen, 120);
    swap(searchTen[0], searchTen[searchTen.size() - 1]);
    cout << "After swap:" << endl;
    displayIntVector(searchTen);
    searchTen.erase(remove(searchTen.begin(), searchTen.end(), 120));
    cout << "After remove 120:" << endl;
    displayIntVector(searchTen);
}

int main() {
    display10vector();
    display20list();
    search10();
    cout << endl;
    return 0;
}
