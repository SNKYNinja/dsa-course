#include <bits/stdc++.h>
using namespace std;

int main() {
    // List - for efficient insertion/deletion in the middle but at the cost of slower random access.

    list <int> l;

    list<int> n(l); // Copy list
    list<int> m(5, 100); // Initialize with default value

    l.push_back(1);
    l.push_front(2);

    for (int i: l) {
        cout << i << " ";
    } cout << endl;

    l.erase(l.begin());

    for (int i: l) {
        cout << i << " ";
    } cout << endl;
}
