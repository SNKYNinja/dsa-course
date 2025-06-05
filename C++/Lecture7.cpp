#include <bits/stdc++.h>
using namespace std;

int main() {
    // Leetcode Questions

    // Q1. https://leetcode.com/problems/reverse-integer/

    // Q2. https://leetcode.com/problems/complement-of-base-10-integer/description/
    int n;
    cin >> n;

    int m = n, mask = 0;

    if (n == 0) return 1;

    while (m != 0) {
        m = m >> 1;
        mask = (mask << 1) | 1;
    }

    int ans = (~n) & mask;

    cout << "Answer: " << ans << endl;

    // Q3. https://leetcode.com/problems/power-of-two/solutions/
}
