#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap_alt(int arr[], int size) {
    for (int i = 0; i < size; i+=2) {
        if (i + 1 < size) {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int findDuplicate(int arr[], int size) 
{
    int ans = 0, n = size;
    
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }

    for (int i = 1; i < n; i++) {
        ans = ans ^ i;
    }

    return ans;
}
 
int main() {
    // 1. Swap Alternative
    // { 1, 2, 3, 4, 5, 6 } ---> { 2, 1, 4, 3, 6, 5 }
    // int arr[6] = { 1, 2, 3, 4, 5, 6 };
    // int arr2[7] = { 7, 6, 5, 4, 3, 2, 1 };

    // swap_alt(arr, 6);
    // printArr(arr, 6);

    // swap_alt(arr2, 7);
    // printArr(arr2, 7);

    // 2. Find unique elements
    // https://www.codingninjas.com/studio/problems/find-unique_625159

    // 3. Duplicate Elements
    // https://www.codingninjas.com/studio/problems/duplicate-in-array_893397

    // int arr[7] = { 1, 2, 3, 4, 5, 3, 6 };
    // int duplicate = findDuplicate(arr, 7);

    // cout << "Duplicate Integer: " << duplicate;

    // 4. Array Intersection
    // https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149

    // Two Pointer Approach

    // 5. Pair Sum
    // https://www.codingninjas.com/studio/problems/pair-sum_697295

    // for (int i = 0; i < n; i++) {
    //   for (int j = i + 1; j < n; j++) {
    //     if (arr[i] + arr[j] == s) {
    //         vector<int> temp;
    //         temp.push_back(min(arr[i], arr[j]));
    //         temp.push_back(max(arr[i], arr[j]));
    //         ans.push_back(temp);
    //     }
    //   }
    // }

}

