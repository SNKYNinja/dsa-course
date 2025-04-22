#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end) {
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main() {
    int even[6] = { 2, 4, 6, 8, 12, 18 };
    int odd[5] = { 3, 6, 9, 12, 15 };

    int index1 = binarySearch(even, 6, 12);
    int index2 = binarySearch(odd, 5, 12);
    cout << "Index of 12 in even array: " <<  index1 << endl;
    cout << "Index of 12 in odd array: " <<  index2 << endl;
}