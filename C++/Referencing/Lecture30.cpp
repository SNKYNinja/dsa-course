#include <iostream> // preprocessor directive
using namespace std;

#define PI 3.14; // Macro

int val = 10; // Global Variable (bad practice)

// Inline function -> reduce function calls overhead
inline void f() {} // Improves performance for function call stack

// default arguments
void print(int x, int y, int z=10){
    cout <<  x + y + z;
}

int main() {
    /*
        Macros -> #define (preprocessor directive)
        Replaces all the macro names with the value defined
    */

   int radius = 10;
   double area = radius * radius * PI;
   cout << "Area: " << area << endl;

    print(10, 2);
}