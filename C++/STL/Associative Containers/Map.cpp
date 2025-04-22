#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Map - key (unique) value pair (sorted + slower)
    All operations -> O(log n) Red-Black Tree Implementation

    unordered_map (unsorted + faster)
    All operations -> O(1) Hash Table Implementation
    */

    map<int, string> m;

    m[1] = "kumar";
    m[2] = "saanu";

    m.insert({ 5, "hit" });

    for (auto i: m) {
        cout << i.first << " -> " << i.second << endl;
    }

    cout << "Count of Key 5 -> " <<  m.count(5) << endl;

    m.erase(2);
    for (auto i: m) {
        cout << i.first << " -> " << i.second << endl;
    }

    auto it = m.find(5);
    for (auto i = it; i != m.end(); i++) { // Iterating using map iterator
        cout << (*i).first << " -> " << (*i).second << endl;
    }
}