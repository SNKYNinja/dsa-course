#include <iostream>
using namespace std;

int main() {
    // Reference variable
    // One memory block being referenced by more than one variable
    int a = 5;
    int &b = a; // Ref var

    int c = 10;
    b = c;

    cout << a << endl; // 10
    cout << c << endl; // 10
    cout << b << endl; // 10

    // Usage: Pass by reference 
    // Example: Function parameters

    /*
        Memory Allocation:

        1. Static Allocation (Stack memory)
        2. Dynamic Alloication (Heap memory)
    */

    // "new" keyword -> Dynamic memory allocation
    // Always use pointers with it (always returns address)
    char* i = new char; // 9 bnytes (8 pointer + 1 char)
    int* j = new int; // 12 bytes (8 pointer + 4 int)

    int* k = new int[5]; // Creates memory in heap
    
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Void Pointer:
    // special pointer that can point to objects of any data type

}