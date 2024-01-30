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

}