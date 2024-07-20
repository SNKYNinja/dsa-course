#include <iostream>
using namespace std;

class Human {
    private:
        int age;
        int height;
        int weight;
    public:
    void setAge(int age) {
        this->age = age;
    }
    int getAge() {
        return age;
    }
};

class Male: public Human {
    private:
        string gender = "Male";
    public:
        void sleep() {
            cout << gender << " is sleeping!" << endl;
        }
        
};

int main() {
    // 4 Pillars of OOPS

    /*
        1. Encapsulation - Wrapping up data members and member functions
        (Information Hiding)
        Fully encapsulated class -> All data members are marked private
    */

    /*
        2. Inheritance - Inherting properties and methods from another class

        Human (parent class)
        --> Male (child class)

        Mode of Inheritance:
        https://www.geeksforgeeks.org/cpp-inheritance-access/
        Note: Private members cannot be INHERITED

        Private v/s Protected : Access Modifier (NOT Mode of Inheritance)
        1. Both members with this access modifier are not accessible outside the class
        2. But protected members can be accessed by another inherited class

        Types:
        1. Single Inheritance
        2. Multi-level Inheritance
        3. Multiple Inheritance
        4. Hierarchical Inheritance
        5. Hybrid Inheritance
    */

    /*
        Inheritance Ambiguity:
        In multiple inheritance, if there are properties and methods that are present
        in both the class A and class B, then class C can access such data using the 
        scope resolution operator

        C c;
        c.A::fn()
        c.B::fn()
    */
    
    Male someMale;

    // We are able to access both the parent and child's members
    // Parent members
    someMale.setAge(28);
    cout << someMale.getAge() << endl;
    // Its own members
    someMale.sleep();


    /*
        3. Polymorpherism - Existing in multiple forms

        I. Compile Time Polymorphism
            Function Overloading
            Operator Overloading
        II. Runtime Polymorphism
            Method Overriding
            Virtual Functions
    */

    /*
        4. Abstraction - Implmenetation hiding and showing only essentials
        (Implementation hiding)

        It is achieved using Access Specifiers and Modifiers
    */


    return 0;
}