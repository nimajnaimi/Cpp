#include <iostream>
#include <string>
#include <stack>
#include <array>

using namespace std;

template <typename T>
void printStack(stack <T> &words) {
    stack <T> temp;
    while (!words.empty()) {
        cout << words.top();
        temp.push(words.top());
        words.pop();
    }
    cout << endl;
    while (!temp.empty()) {
        words.push(temp.top());
        temp.pop();
    }
}

template <typename T>
void reverseStack(stack <T> &words) {
    stack <T> temp;
    while (!words.empty()) {
        temp.push(words.top());
        words.pop();
    }
    /*
    int sizeOfStack = words.size();
    for (int i{0}; i < sizeOfStack; ++i) {
        temp.push(words.top());
        words.pop();
    }
    */
    words.swap(temp);
}

int main() {
    stack <string> words;
    string letters[8] = {"d", "e", "s", "s", "e", "r", "t", "s"};
    for (string i : letters) {
        words.push(i);
    }
    cout << "Printing out stack: ";
    printStack(words);
    reverseStack(words);
    cout << "Printing out reversed stack: ";
    printStack(words);
    return 0;
}
