#include <iostream>
#include <vector>
using namespace std;

void solve(string input, string output, int index, vector<string>& ans, string mapping[]) {
    // Base case for recursion
    if (index >= input.length()) {
        ans.push_back(output);
        return;
    }

    // Recursive case
    // Finds the index for the mapped values
    int num = input[index] - '0';
    string value = mapping[num];

    for (int i = 0; i < value.length(); i++) {
        // Add the value to the ouput vector
        output.push_back(value[i]);
        solve(input, output, index + 1, ans, mapping);
        // Remove the value from the output vector after all recursive calls for this value is completed
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0) return ans;

    string output = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    
    solve(digits, output, 0, ans, mapping);
    
    return ans;
}

int main() {
    // Phone Keypad Problem
    // https://leetcode.com/problems/letter-combinations-of-a-phone-number/

    string digits = "36";
    vector<string> ans = letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}