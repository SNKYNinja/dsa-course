#include <bits/stdc++.h>
using namespace std;

int main() {
    // Stack (LIFO) - push and pop both from head

    stack<string> s;

    s.push("Hello");
    s.push("World");

    cout << "Top Element -> " << s.top() << endl;

    s.pop(); // Removes top element
    cout << "Top Element -> " << s.top() << endl;

    cout << "Size of Stack -> " << s.size() << endl; 

    cout << "Empty -> " << (s.empty() ? "Yes" : "No") << endl;

}