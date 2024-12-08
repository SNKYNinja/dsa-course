#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Deque - for efficient insertion/deletion at both ends.

    // Insertion and Deletion at both ends is possible
    deque<int> d = {5, 6};

    d.push_back(1);
    d.push_front(2);

    for (int i : d) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Pop Front:" << endl;

    d.pop_front();
    for (int i : d) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Element at 1st Index -> " << d.at(1) << endl;

    cout << "Front -> " << d.front() << endl;
    cout << "Back -> " << d.back() << endl;

    cout << "Empty? -> " << d.empty() << endl;

    cout << "Before erase size -> " << d.size() << endl;
    d.erase(d.begin(), d.begin() + 1);
    cout << "After erase size -> " << d.size() << endl;
}