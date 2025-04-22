#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(14);
    v.push_back(19);

    // Binary Search
    cout << "5 Present? " <<  binary_search(v.begin(), v.end(), 5) << endl;

    // Lower Bound
    auto lowerIt = lower_bound(v.begin(), v.end(), 5); // Iterator
    cout << "Lower Bound -> " << lowerIt - v.end() << endl; // Index

    // Upper Bound
    auto upperIt = upper_bound(v.begin(), v.end(), 5);
    cout << "Upper Bound -> " << upperIt - v.end() << endl;

    // Max/Min
    int a = 5, b = 8;
    cout << "Max -> " << max(a, b) << endl;
    cout << "Min -> " << min(a, b) << endl;

    // Swap
    swap(a, b);
    cout << "Swapped A -> " << a << endl;
    cout << "Swapped B -> " << b << endl;

    // Reverse
    string s = "abcd";
    reverse(s.begin(), s.end());
    cout << "Reversed String -> " << s << endl;

    // Rotate
    cout << "Rotated Vector: "; // 2 5 14 19 ->  5 14 19 2
    for (auto num: v) {
        cout << num << " ";
    } cout << "-> ";
    rotate(v.begin(), v.begin() + 1, v.end());
    for (auto num: v) {
        cout << num << " ";
    } cout << endl;

    // Sort -> IntoSort (Quick + Heap + Insertion)
    sort(v.begin(), v.end()); 
    cout << "Sorted Vector: ";
    for (auto num: v) {
        cout << num << " ";
    } cout << endl;
}