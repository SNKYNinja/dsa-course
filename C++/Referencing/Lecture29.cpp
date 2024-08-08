#include <iostream>
using namespace std;

void printArray(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void releaseMemory(int** arr, int row) {
    for (int i = 0; i < row; i++) {
        // Deletes row pointer (row array)
        delete[] arr[i];
    }

    // Deletes the 2D array pointer that held the row pointer
    delete[] arr;
}

void printJaggeredArray(int** arr, int* rowSizes, int r) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < rowSizes[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 2D Array Dynamic Allocation
    // int row, col;
    // cout << "Row & Column" << endl;
    // cin >> row >> col;
    
    // int** arr = new int*[col];
    // for (int i = 0; i < row; i++) {
    //     arr[i] = new int[col];
    //     for (int j = 0; j < col; j++) {
    //         int n;
    //         cin >> n;
    //         arr[i][j] = n;
    //     }
    // }

    // printArray(arr, row, col);

    // releaseMemory(arr, row);

    // Homework - Jaggered Array

    int r;
    cout << "Rows: ";
    cin >> r;
    int** arr = new int*[r];
    int* rowSizes = new int[r];

    for (int i = 0; i < r; i++) {
        cout << endl << "Row " << i + 1 << " size: ";
        int size;
        cin >> size;
        rowSizes[i] = size;

        arr[i] = new int[size];
        
        cout << "Enter row " << i + 1 << " elements:" << endl;
        for (int j = 0; j < size; j++) {
            int el;
            cin >> el;
            arr[i][j] = el;
        }
    }

    cout << endl;

    printJaggeredArray(arr, rowSizes, r);

}