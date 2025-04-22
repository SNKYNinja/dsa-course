#include <iostream>
using namespace std;

// Recursive factorial function
int factorialRec(int n) {
    if (n == 1) return 1;
    return n * factorialRec(n-1);
}

int countDistinctWays(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    return countDistinctWays(n - 1) + countDistinctWays(n - 2);
}

void sayDigits(int n) {
    string nums[10] = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
    };
    if (n == 0) return;
    sayDigits(n / 10);
    cout << nums[n % 10] << " ";
}

int main() {
    // int n;
    // cin >> n;
    // cout << "Factorial of " << n << ": " << factorialRec(n) << endl;

    // Questions
    // 1. https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650
    // Will show TLE (Problem requires more faster approach using DP)
    int n;
    cin >> n;
    cout << countDistinctWays(n) << endl;

    // 2. SayDigits
    // i/p -> 412
    // o/p -> Four One Two

    sayDigits(106236);
}