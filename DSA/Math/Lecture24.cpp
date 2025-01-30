#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// Sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);

            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (auto p : primes) {
        cout << p << " ";
    }

    cout << endl;
    return primes;
}

// Segmented Sieve
void segSieve(int l, int h) {
    if (l < 2)
        l = 2;
    vector<int> prime = sieve(floor(sqrt(h)));
    // Adds all the prime numbers b/w 0 and sqrt(h)

    // Prime bool vector
    vector<int> isPrime(h - l + 1, true);

    // Iterate over the primes we got earlier
    for (int p : prime) {
        // sm is the smallest multiple of p in the range
        // We need sm so that we can start falsing the multiple of p in isPrime
        int sm = (l / p) * p;
        if (sm < l) {
            // This will bring sm in range if its not in already
            sm += p;                               // INITIAL
            sm += max(p * p, (l + p - 1) / p * p); // DID NOT UNDERSTAND
        }

        // We iterate over all the multiples and mark them false
        for (int m = sm; m <= h; m += p) {
            isPrime[m - l] = false;
        }
    }

    // Now we will create an array with the prime numbers required
    for (int i = l; i <= h; i++) {
        if (isPrime[i - l]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int countPrimes(int n) {
    int count = 0;
    // Since we are using the index of the vector for the numbers which are all
    // set as prime for now, we will put n+1 for the number of elements
    // therefore making the vector ranging from 0 to n
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            count++;

            // Here j = 2 * i because we need to go the second element of i's
            // table i.e i x 2 Incrementing j by i is done as the table of a
            // number progresses by adding the number itself
            for (int j = 2 * i; j < n; j += i) {
                // We set this number as non prime since it comes in the table
                // of i
                prime[j] = false;
            }
        }
    }

    return count;
}

// Greatest Common Divisor
int gcd(int a, int b) {
    // Iterative Method
    // if (a == 0)
    //     return b;
    // if (b == 0)
    //     return a;

    // while (a != b)
    // {
    //     if (a > b)
    //     {
    //         a = a - b;
    //     }
    //     else
    //     {
    //         b = b - a;
    //     }
    // }

    // return a;

    // Recursive Method
    // 1. Using modulus operator
    if (b == 0)
        return a;
    return gcd(b, a % b);

    // 2. Using arithmetic operator
    // if (a == 0 || b == 0)
    //     return a + b;
    // return a > b ? gcd(a - b, b) : gcd(a, b - a);
}

// Fast Exponentiation
int exponentiation(long long a, int b) {
    const int MOD = 1e9 + 7; // IMPORTANT

    if (b == 0)
        return 1;

    // Iterative Method
    int result = 1;
    //
    while (b > 0) {
        // Check if the least significant bit of b is 1 (i.e., b is odd)
        if (b & 1)
            result = result * a; // Multiply the current result by a

        // Square the base a for the next iteration
        a = a * a;

        // Right shift b by 1 bit (equivalent to dividing b by 2 and discarding
        // the remainder) This effectively reduces the power we are raising a to
        // in the next iteration
        b = b >> 1;
    }

    // Recursive Method

    // Right shift by 1 is same as dividing the number by 2
    // (b >> 1) === (b / 2)
    // int tmp = exponentiation(a, b >> 1);
    // int result = tmp * tmp;

    // (b & 1) will be true if b is odd
    // if (b & 1)
    // {
    //     result *= a;
    // }

    return result;
}

// Recursive Factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    // Sieve of Eratosthenes
    // https://leetcode.com/problems/count-primes/description/
    // Solution: countPrimes() -> Line 5

    // Segmented Sieve (Homework)
    // auto primes = segSieve(7, 29);
    // for (auto p : primes)
    // {
    //     cout << p << " ";
    // }

    // Euclid Algorithm
    // cout << gcd(24, 72) << endl;

    // Fast Exponentiation
    // https://www.naukri.com/code360/problems/modular-exponentiation_1082146

    // Pigeonhole Prinicpe
    // https://www.geeksforgeeks.org/pigeonhole-principle-for-competitive-programming/

    cout << gcd(24, 70);
}
