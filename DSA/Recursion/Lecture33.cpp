#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    if (n == 0 || n == 1) return true;
    if (arr[0] > arr[1]) return false;
    return isSorted(arr + 1, n - 1);
}

int arraySum(int arr[], int n) {
    if (n == 1) return arr[0];
    return arr[0] + arraySum(arr + 1, n - 1);
}

bool linearSearch(int arr[], int n, int target) {
    if (n < 1) return false;
    if (arr[0] == target) return true;
    return linearSearch(arr + 1, n - 1, target);
}

int binarySearch(int arr[], int s, int e, int target) {
    if (s > e) return -1;

    int mid = s + (e - s) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return binarySearch(arr, s, mid - 1, target);
    else return binarySearch(arr, mid +  1, e, target);   
}

int main() {
    // Questions

    // 1. isSorted
    int arr[5] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << isSorted(arr, n) << endl;

    // Homework: Array sum using recursion
    cout << arraySum(arr, n) << endl;

    // 2. Linear Search
    cout << linearSearch(arr, n, 8) << endl;

    // 3. Binary Search
    cout << binarySearch(arr, 0, n - 1, 8) << endl;

}