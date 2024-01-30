#include <iostream>
using namespace std;

bool search(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void reverse(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {

    int arr[10] = { 5, 7, 9, -2, 0, -9, 12, 92, 1, -16 };

    // Linear Search

    // cout << search(arr, 10, 1);

    reverse(arr, 10);
    printArr(arr, 10);

}