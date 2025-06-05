#include <cmath>
#include <iostream>
using namespace std;

int main() {
    // Decimal to Binary

    // long long int n;
    // unsigned long int ans = 0, i = 0;
    // cin >> n;

    // if (n < 0) {
    //     n = pow(2, 16) + n;
    // }

    // while (n != 0) {
    //     int bit = n & 1;
    //     n = n >> 1;

    //     ans += pow(10 , i) * bit;
    //     i++;
    // }

    // cout << "Binary: " << ans << endl;

    // Binary to Decimal

    // int32_t n;
    // cin >> n;

    // int digits = 0, i = 0;

    // while (n != 0) {
    //     int digit = (n % 10) * pow(2, i);
    //     digits += digit;
    //     n /= 10;
    //     i++;
    // }

    // cout << "Digit: " << digits;

    int n;
    cin >> n;

    long int bits = 0, i = 0;

    if (n == 0) return 1;

    while (n != 0) {
        int bit = n & 1;

        bit = bit ^ 1; // Complement

        bits += pow(10, i) * bit;

        n = n >> 1;
        i++;
    }

    cout << "Bits: " << bits << endl;

    int num = 0, j = 0;

    while (bits != 0) {
        int bit = bits % 10;

        num += pow(2, j) * bit;

        bits /= 10;
        j++;
    }

    cout << "Number: " << num << endl;
}
