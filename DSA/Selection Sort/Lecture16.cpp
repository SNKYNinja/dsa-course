#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    // Write your code here.

    int i = 0;

    while (i < n)
    {
        // Store the minimum value's index of the selection array
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);

        i++;
    }
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
    // 1. https://www.naukri.com/code360/problems/selection-sort_981162
    // Solution:
    int arr[] = {29, 72, 98, 13, 87, 66, 52, 51, 36};
    int n = 9;
    selectionSort(arr, n);
    printArray(arr, n);

    // Homework

    // Stable or Unstable?
    // https://www.youtube.com/watch?v=60-rBUCMsFo

    // Stable
    /*
        Bubble
        Insertion
        Merge
        Count
    */

    // Unstable (By Nature)
    /*
        Quick
        Heap
        Selection
    */
}