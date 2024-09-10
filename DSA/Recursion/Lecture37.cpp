#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    } cout << endl;
}

void solve(vector<int> exclude, vector<int> include, int index, vector<vector<int>> &ans) {
    if (index >= exclude.size()) {
        ans.push_back(include);
        return;
    }

    solve(exclude, include, index + 1, ans);

    include.push_back(exclude[index]);
    solve(exclude, include, index + 1, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output = {};
    solve(nums, output, 0, ans);
    return ans;
}

void solve2(string exclude, string include, int index, vector<string> &ans) {
	   if (index >= exclude.length()) {
        if (include.length() > 0) {
			ans.push_back(include);
		}
		return;
    }

    solve2(exclude, include, index + 1, ans);
    include.push_back(exclude[index]);
    solve2(exclude, include, index + 1, ans);
}

vector<string> subsequences(string str){
	vector<string> ans;
	string output = "";
    solve2(str, output, 0, ans);
	return ans;
}

int main() {
    // 1. Subsets
    // https://leetcode.com/problems/subsets/

    // Power set -> 2^n elements

    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> subset = subsets(nums);

    // for (int i = 0; i < subset.size() - 1; i++) {
    //     for (int j = 0; j < subset[i].size(); j++) {
    //         cout << subset[i][j] << " ";
    //     } cout << endl;
    // }

    // 2. Subsequences
    // https://www.naukri.com/code360/problems/subsequences-of-string_985087

    string a = "abc";
    vector<string> subsq = subsequences(a);

    // for (int i = 0; i < subsq.size(); i++) {
    //     cout << subsq[i] << endl;
    // }

    return 0;
}