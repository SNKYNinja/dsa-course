#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>>& ans) {
    // Base Case
    if (index >= nums.size() - 1) {
        ans.push_back(nums);
        return;
    }

    // Recursive Case
    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
}

int main() {
    // Permutations
    // https://leetcode.com/problems/permutations/description/
}