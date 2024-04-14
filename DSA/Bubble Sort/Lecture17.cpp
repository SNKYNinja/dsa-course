#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    // The first loop will only be used for starting rounds
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;

        // The second loop will be used for swapping neighbour elements if the condition is fulfilled
        // Here we did "n - i" in place of "n - 1" because after every round one more element at the end is sorted our sort space is decreased by one every round and thus we don't need to go to the element just before the sorted element.
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // We check if the prev loop did any swapping, if not then the array is already sorted and thus do not require us to go to the next round so we break out of the loop
        if (!swapped)
            break;
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
    // 1. https://www.naukri.com/code360/problems/bubble-sort_980524
    // Solution:
    int arr[] = {6, 2, 8, 4, 10};
    int n = 5;
    bubbleSort(arr, n);
    printArray(arr, n);

    // Quiz: https://www.geeksforgeeks.org/top-mcqs-on-bubblesort-algorithm-with-answers/
}