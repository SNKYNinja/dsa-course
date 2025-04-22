#include <iostream>
using namespace std;

int main() {
    /* Way to taking a char as an input
    int c = cin.get();
    cout << c << endl;
    */

    // int a, b;
    // cin >> a >> b;
    
    // if (a > b) {
    //     cout << "Ans: A" << endl;
    // } else {
    //     cout << "Ans: B" << endl;
    // }

    // int n, i = 1, sum = 0;
    // cin >> n;

    // if (n < 10000) {
       
    //     while (i <= n) {
    //         if (i % 2 == 0) {
    //             sum+=i;
    //         }
    //         i++;
    //     }

    //     cout << "Value of i: " << i << endl;
    //     cout << "Sum: " << sum << endl;

    // } else cout << "NOPE" << endl;
    

    // while(true) {

    //     char a;
    //     cin >> a;

    //     if (a == 'Q' || a == 'q') {
    //         cout<<"Ending Simulation!"<<endl;
    //         break;
    //     } else if (a <= 'z' && a >= 'a') {
    //         cout<<"Lowercase"<<endl;
    //     } else if (a <= 'Z' && a >= 'A') {
    //         cout<<"Uppercase"<<endl;
    //     } else if (a <= '9' && a >= '0') {
    //         cout<<"Number"<<endl;
    //     } else {
    //         cout<<"Special Character"<<endl;
    //     }
    // }

    // int n, i = 2;
    // bool isPrime = true;
    // cin >> n;

    // while (i < n) {
    //     if (n % i == 0) {
    //         isPrime = false;
    //         break;
    //     } else {
    //         isPrime = true;
    //         i++;
    //         continue;
    //     }
    // }

    // if (isPrime) {
    //     cout << n << " is a prime number!\n";
    // } else {
    //     cout << n << " is not a prime number!\n";
    // }

    // Pattern 1
    // int n, i = 0;
    // cin >> n;
    // char star = '*';

    // while (i < n && i > 0) {
    //     int j = 0;
    //     while (j < n) {
    //         cout << '\t' << star;
    //         j++;
    //     };
    //     cout << endl;
    //     i++;
    // }; 

    // Pattern 2
    // int n, i = 1;
    // cin >> n;

    // while (i <= n && i > 0) {
    //     int j = 0;
    //     while (j < n) {
    //         cout << '\t' << i;
    //         j++;
    //     };
    //     cout << endl;
    //     i++;
    // };
}