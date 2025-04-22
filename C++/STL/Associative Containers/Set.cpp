#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Set - only stores unique elements (sorted + slower)
    no modification allowed, only insert or delete
    insert, find, erase, find -> O (log n)

    unorederd_set (unsorted + faster)
    All operations - O(1)
    */

    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(2);

    for (auto i: s) {
        cout << i << " ";
    } cout << endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it); // Deletes second element (it = s.begin() + 1)

    for (auto i: s) {
        cout << i << " ";
    } cout << endl;

    cout << "Count of 5 -> " << s.count(5) << endl; // To check if element exists or not

    set<int>::iterator itr = s.find(5); // Iterator of 5
    cout << "Vaue present At itr -> " << *itr << endl;

    // Using iterator to iterate through the set
    for (auto it = itr; it != s.end(); it++) {
        cout << *it << " ";
    } cout << endl;

}