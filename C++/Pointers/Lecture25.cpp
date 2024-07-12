#include <iostream>
using namespace std;

int main() {
    int num = 5;

    // Prints the address of the variable num ('&' operator -> address of operator)
    // cout << &num << endl;

    // Pointer: Stores addresses
    int *ptr = &num;
    cout << ptr << endl;
}