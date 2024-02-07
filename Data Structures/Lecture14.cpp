#include <iostream>
#include <vector>
using namespace std;

int sqrt(int n) {
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;

    float ans = -1;

    while (s <= e) {
        long long int sqr = mid * mid;
        if (sqr == n) {
            return mid;
        } 
        if (sqr < n) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

double morePrecision(int n, int precision, int sqrt) {
    double factor = 1;
    double ans = sqrt;
    for (int i = 0; i < precision; i++) {
        factor /= 10;
        for (double j = ans; j*j < n; j+=factor ) {
            ans = j;
        }
    }

    return ans;
}

int main() {
    // 1. Search in a rotated sorted array
    // https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2

    // 2. Peak Index in a mountain array
    // https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

    // 3. Square root of a number
    // https://www.codingninjas.com/studio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2

    // Square Root
    int n;
    cin >> n;
    cout << "Square Root of " << n << ": " << sqrt(n) << endl;
    cout << "Square Root of " << n << "(Precise): " << morePrecision(n, 4, sqrt(n)) << endl;

    // Search in a rotated array (leetcode)
    // https://leetcode.com/problems/search-in-rotated-sorted-array/solutions/4515706/100-binary-search-solution-s-optimal-solution-s/

    // Alternate Solution
    // vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };
    // int target = 0;
    // int s = 0;
    // int e = arr.size();
    // int mid = s + (e - s) / 2;

    // while (s <= e) {
    //     if (arr[mid] == target) {
    //         cout << mid;
    //     }

    //     if (arr[s] <= arr[mid]) {
    //         if (arr[s] <= target && arr[mid] >= target) {
    //             e = mid - 1;
    //         } else {
    //             s = mid + 1;
    //         }
    //     } else {
    //         if (arr[mid] <= target && arr[e] >= target) {
    //             s = mid + 1;
    //         } else {
    //             e = mid - 1;
    //         }
    //     }

    //     mid = s + (e - s) / 2;
    // }
}