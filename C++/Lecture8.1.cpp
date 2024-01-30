#include <iostream>
#include <cmath>
using namespace std;

// To find a power of a number
int power(int a, int b) {
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a; 
    }
    return true;
}

int factorial(int a) {
    int fac = 1;
    for (int i = 2; i <= a; i++) {
        fac *= i;
    }
    return fac;
}

int nCr(int n, int r) {
    int nF = factorial(n);
    int rF = factorial(r);
    int nrF = factorial(n - r);
    return nF / (rF * nrF);
}

bool isPrime(int a) {
    if (a == 2) return 1;
    for (int i = 2; i < a; i++) {
        if (a % 2 == 0) return 0;
        else continue;
    }
    return 1;
}

int main() {
    // cout << "Loop Started" << endl;
    // while (true) {
    //     int num;
    //     cin >> num;
    //     switch (num) {
    //         case 1: {
    //             cout << "Correct" << endl;
    //             exit(0);
    //         }
    //         default: cout << num << " is Wrong" << endl;
    //     }
    //     cout << "Outside Switch" << endl;
    // }

    // cout << "Outside While" << endl;

    // Functions

    // int a, b;
    // cin >> a;
    // cin >> a >> b;

    // cout << power(a, b);

    // cout << nCr(a, b);
    
    // if (isPrime(a)) cout << a << " is a prime number!";
    // else cout << a << " is a not prime number!";

    return 0;
}