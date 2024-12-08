#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Vector - for dynamic arrays with fast random access.

    // Here 5 -> size of array and 1 -> The fill number
    vector<int> a(5, 1); // { 1, 1, 1, 1, 1 }

    // vector b will be the duplicate of a
    vector<int> b(a);

    cout << "Printing a " << endl;

    for (int i : a) {
        cout << i << endl;
    }

    vector<int> v;
    // Capcity of a vector doubles as the vector reaches its current max capacity
    // The previous vector gets disposed and a new vector is created with the doubled capacity
    // 0 -> 1 -> 2 -> 4 -> 8 -> 16

    cout << "Capacity -> " << v.capacity() << endl;

    v.push_back(1);
    cout << "Capacity -> " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity -> " << v.capacity() << endl;

    v.push_back(3);
    cout << "Capacity -> " << v.capacity() << endl;
    cout << "Size -> " << v.size() << endl;

    cout << "Element at 2nd index -> " << v.at(2) << endl;

    cout << "Front -> " << v.front() << endl;
    cout << "Back -> " << v.back() << endl;

    cout << "Before pop: " << endl;
    for (int i : v) {
        cout << i << endl;
    }
    
    v.pop_back();
    cout << "After pop: " << endl;
    for (int i : v) {
        cout << i << " ";
    }
}