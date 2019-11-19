#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool isPalindrome(const array<int, 7>& arr) {
    stack<int> x;
    for (unsigned int i{0}; i < arr.size() / 2; ++i) {
        x.push(arr[i]);
    }
    for (unsigned int i{arr.size() / 2}; i < arr.size(); ++i) {
        if (x.top() != arr[i]) {
            return false;
        }
        x.pop();
    }
    return true;
}

bool equalStackQueue(stack<int>& s, queue<int>& q) {
    while (!s.empty() && !q.empty()) {
        if (s.top() != q.front()) {
            return false;
        }
        s.pop();
        q.pop();
    }
    if ((s.empty() && !q.empty()) || (!s.empty() && q.empty())) {
        return false;
    }
    return true;
}


int main()
{
    vector<int> v{0, 1, 2, 3};
    stack<int> s;
    for (int i: v) {
        s.push(i);
    }
    for (int i{0}; i < s.size(); ++i) {
        v[i] = s.top();
        s.pop();
    }
    return 0;
}
