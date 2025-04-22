#include <iostream>
using namespace std;

int main() {
    int num = 5;

    // Prints the address of the variable num ('&' operator -> address of operator)
    // cout << &num << endl;

    // Pointer: Stores addresses
    int *ptr = &num;
    cout << ptr << endl;

    // * -> deference operator

    // Null Pointer
    // int *q = 0;
    // int *q = NULL;

    // Pointer value access
    // int i = 5;
    // int *p = &i;
    // (*p)++;
    // cout << i << endl;

    // Copying Pointers
    int *ptr2 = ptr;
    cout << "Pointer 1: " << ptr << endl;
    cout << "Pointer 2: " << ptr2 << endl;
    
    // Double pointer
    int j = 10;
    int *p1 = &j;
    int **p2 = &p1;
    // j = *p1 = **p2

    // Dangling Pointer
    // pointer who is pointing to a location that has been freed (deleted)

    // Pointer Arithmetic
    ptr = ptr + 1;
    /*
        IF ptr = 100;
        ptr++ -> ptr = 104
        Adding 1 to the pointer will result in going to the next integer
        1 integer stores 4 bytes therefore it went from 100 to 104
    */

    // Arrays and Pointers
    int a[] = {1, 2, 3, 4};
    // a = &a[0]

    cout << *(a) << " " << *(a+1) << endl;
    // *(a) -> a[0]
    // *(a + 1) -> a[1]
    // arr[i] = *(arr + i)
    // i[arr] = *(i + arr)
    // arr[i] = i[arr] = *(arr + i) = *(i + arr)

    char ch[6] = "abcde";
    char *c = &ch[0];
    // when printing char* it prints the string starting from the pointer until it encounters the null terminator.
    cout << c << endl;

   // Practice Questions
   // https://www.naukri.com/code360/guided-paths/pointers
}