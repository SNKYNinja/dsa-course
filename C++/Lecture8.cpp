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

int calc(int a, int b, char op) {
    int ans = 0;

    switch (op) {
        case '+': ans = a + b;
            cout << ans;
            break;
        case '-': ans = a - b;
            cout << ans;
            break;
        case '*': ans = a*b;
            cout << ans;
            break;
        case '/': ans = a/b;
            cout << ans;
            break;
        case '%': ans = a % b;
            cout << ans;
            break;;
        default: cout << "Unkown Operation" << endl;
    }
}

void printNotes(int amount) {
    int rs100 = 0, rs50 = 0, rs20 = 0, rs1 = 0;

    switch (1) {
        case 1: {
            rs100 = amount / 100;
            amount %= 100;
            cout << "100Rs Note: " << rs100 << endl;
        }
        case 2: {
            rs50 = amount / 50;
            amount %= 50;
            cout << "50Rs Note: " << rs50 << endl;
        }
        case 3: {
            rs20 = amount / 20;
            amount %= 20;
            cout << "20Rs Note: " << rs20 << endl;
        }
        case 4: {
            rs1 = amount;
            cout << "1Rs Cons: " << rs1 << endl;
        }
    }
}

int nthTerm(int n) {
    return 3*n + 7;
}

int calcBits(int a, int b) {
    int ans = 0;
    while (a != 0 || b != 0) {
        if (a&1) ans++;
        if (b&1) ans++;
        a = a >> 1;
        b = b >> 1;
    }
    return ans;
    }

    int nthFib(int n) {
    int prev = 0, curr = 1;

    if (n == 1) return 0;
    if (n == 2) return 1;

    for (int i = 3; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }

    return curr;
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

    // Calculator Program
    // int a, b;
    // char op;
    // cout << "First Input: ";
    // cin >> a;
    // cout << "Second Input: ";
    // cin >> b;
    // cout << "Operation: ";
    // cin >> op;

    // int ans = calc(a, b, op)

    // cout << "Answer: " << ans;

    // Notes Program

    // int amount;
    // cout << "Enter the amount: ";
    // cin >> amount;

    // printNotes(amount);

    // 3*n + 7 ---> print it's nth term
    // cout << nthTerm(a);

    // Set Bits
    // int aNum, bNum;
    // cin >> aNum >> bNum;

    // cout << "Total set bits: " << calcBits(aNum, bNum);

    // nth Fibonacci number
    // int f;
    // cin >> f;

    // cout << "Fibonacci: " << nthFib(f);

    return 0;
}