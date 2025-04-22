#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Priority Queue -> 
    max element will be popped O(log n)
    min element will be inserted O(log n)
    */

    priority_queue<int> maxi; // Max heap
    priority_queue<int, vector<int>, greater<int>> mini; // Mini heap

    maxi.push(1);
    maxi.push(3);
    maxi.push(9);
    maxi.push(5);

    int n = maxi.size(); // Size of priority queue
    for (int i = 0; i < n; i++) {
        cout << maxi.top() << " ";
        maxi.pop();
    } cout << endl;

    mini.push(1);
    mini.push(3);
    mini.push(9);
    mini.push(4);

    int m = mini.size();
    for (int i = 0; i < m; i++) {
        cout << mini.top() << " ";
        mini.pop();
    } cout << endl;
}