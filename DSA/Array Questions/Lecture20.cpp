#include <iostream>
#include <vector>
using namespace std;

// Move non zero to left
void moveZeroes(vector<int> &nums)
{
    // Initialize two pointers, i and j, both starting at the beginning of the array
    int i = 0; // Pointer i iterates through the array
    int j = 0; // Pointer j keeps track of the position to swap non-zero elements

    // Iterate through the array
    while (i < nums.size())
    {

        // If the current element is not zero
        if (nums[i] != 0)
        {

            // Swap the current element with the element at position j,
            // moving all non-zero elements towards the beginning of the array
            swap(nums[i], nums[j]);
            j++; // Increment j to keep track of the next position for non-zero elements
        }

        // Move to the next element in the array
        i++;
    }
}

int main()
{
    // 1. Reverse The Array
    // https://www.naukri.com/code360/problems/reverse-the-array_1262298

    // 2. Merge Sorted Array (Can be optimised)
    // https://leetcode.com/problems/merge-sorted-array/

    // 3. Move Zeros
    // https://leetcode.com/problems/move-zeroes/
}