#include <iostream>
using namespace std;

int get_max(int num[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }

    return max;
}

int get_min(int num[], int n) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (num[i] < min) {
            min = num[i];
        }
    }

    return min;
}

int sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

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
    // Array Initialisation
    // int arr[3] = { 1, 2, 4 };
    
    // Initialize entire array with single value

    // int arr100[100] = { -1 };
    // fill_n(arr100, 100, -1);

    // for (int i = 0; i < 100; i++) {
    //     cout << arr100[i] << endl;
    // }

    int num[100];

    for (int i = 0; i < 5; i++) {
        cin >> num[i];
    }

    cout << "Maximum Value: " << get_max(num, 5) << endl;
    cout << "Minimum Value: " << get_min(num, 5) << endl;

    cout << "Sum: " << sum(num, 5) << endl;

    int arr[10] = { 5, 7, 9, -2, 0, -9, 12, 92, 1, -16 };

    // Linear Search

    // cout << search(arr, 10, 1);

    reverse(arr, 10);
    printArr(arr, 10);

}