#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums)
{
    // There are threee cases:
    // 1. Sorted
    // 2. Sorted + Rotated
    // 3. Not Sorted
    // 4. All elements are same (count will be 0)

    int n = nums.size();
    int count = 0;
    // We will do a cyclic check whether the array is sorted or not
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }

    if (nums[n - 1] > nums[0])
        count++;

    // if the array is sorted, then obviously the count will be "one" since atleast one element will be greater than its next element due to cyclic check
    return count <= 1;
}

int main()
{
    // 1. Rotate array
    // https://leetcode.com/problems/rotate-array/

    // 2. Check if Array Is Sorted and Rotated
    // https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

    // 3. Add arrays (IMPORTANT)
    // https://www.naukri.com/code360/problems/sum-of-two-arrays_893186
}
