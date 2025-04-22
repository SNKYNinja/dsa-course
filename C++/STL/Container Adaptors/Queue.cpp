#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<string> q;

    q.push("Ado");
    q.push("Netwing");
    q.push("Hasting");

    cout << "Front (First) Element -> " << q.front() << endl;
    q.pop();
    cout << "Front (First) Element -> " << q.front() << endl;

    cout << "Size of Queue -> " << q.size() << endl;
}