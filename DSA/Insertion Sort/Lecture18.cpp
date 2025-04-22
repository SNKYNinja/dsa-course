#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    // We start from the 1st index element
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            // We compare the value of prev elements with "temp" not "arr[i]" because the value of "arr[i]" will change every iteration of the nested loop
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            else
            {
                break;
            }
        }
    }

    // Optimised Code:
    // To traverse all the elements.
    // for(int i = 1; i < n; ++i) {

    //     // To store the current element.
    //     int curr = arr[i];

    //     // To traverse previous elements.
    //     int idx = i - 1;

    //     while(idx >= 0 && arr[idx] > curr) {

    //         // Change elements position.
    //         arr[idx + 1] = arr[idx];

    //         --idx;
    //     }

    //     // Change current element.
    //     arr[idx + 1] = curr;
    // }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {7, 2, 9, 0, 12, 1};
    int n = 6;
    insertionSort(arr, n);
    printArray(arr, n);
}