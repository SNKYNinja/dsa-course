#include <iostream>
using namespace std;

// Pivot index
int Partition(int* arr, int s, int e) {
    int count = 0;

    for (int i = s + 1; i <= e; i++) {
        if (arr[i] < arr[s]) count++;
    }

    int pivot = s + count;
    swap(arr[s], arr[pivot]);

    int i = s, j = e;
    while (i < pivot && j > pivot) {
        while (arr[i] < arr[pivot]) {
            i++;
        }

        while (arr[j] > arr[pivot]) {
            j--;
        }

        if (i < pivot && j > pivot) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivot;
}

void QuickSort(int* arr, int s, int e) {
    if (s < e) {
        int p = Partition(arr, s , e);

        QuickSort(arr, s, p - 1);
        QuickSort(arr, p + 1, e);
    }
}

int main() {
    int arr[] = { 3, 5, 1, 8, 2, 4 };
    int n = 6;

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}