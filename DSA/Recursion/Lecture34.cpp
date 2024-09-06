#include <iostream>
using namespace std;

string reverseString(string &str, int p) {
    int n = str.length();
    if (p >= n / 2) {
        return str;
    }

    swap(str[p], str[n - p - 1]);
    p++;
    return reverseString(str, p);
}

bool checkPalindrone(string str, int i, int j) {
    if (i >= j) return true;
    if (str[i] != str[j]) return false;
    return checkPalindrone(str, i + 1, j - 1);
}

int pow(int a, int b) {
    if (b == 0) return 1;
    return a * pow(a, b  - 1);
}

int betterPow(int a, int b) {
    if (b == 0) return 1;
    int temp = betterPow(a, b / 2);
    if (b & 1)  return a * temp * temp;
    else return temp * temp;
}

void bubbleSort(int * arr, int n) {
    if (n == 0 || n == 1) return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    bubbleSort(arr, n - 1);
}

void selectionSort(int * arr, int n) {
    if (n == 0 || n == 1) return;

    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    swap(arr[minIndex], arr[0]);

    selectionSort(arr + 1, n - 1);
}

void insertionSort(int* arr, int n, int i) {
    if (n == 0 || n ==  1) return;
    
    int key = arr[i];
    // for (int j = i - 1; j >= 0; j--) {
    //     if (arr[j] > key) {
    //         arr[j + 1] = arr[j];
    //         arr[j] = key;
    //     } else break;
    // }
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        --j;
    }

    arr[j + 1] = key;

    insertionSort(arr, n - 1, i + 1);
}
  
int main() {
    // 1. Reverse a string
    string str = "1234567";
    // cout << reverseString(str, 0) << endl;

    // 2. Binary Palindrone
    // https://www.naukri.com/code360/problems/check-palindrome_920555

    // Power using Recursion
    // cout << pow(2, 3) << endl;
    // cout << betterPow(2, 23) << endl;

    // Bubble Sort
    // int arr[] = {3, 10, 1, 7, 3 , 5, 6};
    // bubbleSort(arr, 7);
    // for (int i = 0; i < 7; i++) {
    //     cout << arr[i] << " ";
    // }

    // Selection Sort
    // int arr2[] = {4, 1, 3, 2, 6, 9, 10, 5};
    // selectionSort(arr2, 8);
    // for (int i = 0; i < 8; i++) {
    //     cout << arr2[i] << " ";
    // }

    // Insertion Sort
    // int arr3[] = { 10, 34, 12, 65, 32, 12, 9 };
    // insertionSort(arr3, 7, 1);
    // for (int i = 0; i < 7; i++) {
    //     cout << arr3[i] << " ";
    // }
}