#include <iostream>
using namespace std;

class Hero {
    public:
    int health;
    int level;
    
    // Static data members belong to the CLASS not the OBJECT created
    static int timeLeft;
    static int getTimeLeft() {
        return timeLeft;
    }

    // Default constructor
    Hero() {
        cout << "Object created!" << endl;
    }

    // Paramtrized Constructor
    Hero(int health) {
        // health = health;
        this->health = health;
    }

    Hero(int health, int level) {
        this -> health = health;
        this -> level = level;
    }

    // Shallow copy constructor
    // Hero (Hero &temp) {}

    // Deep copy constructor
    // Hero (Hero &temp) {}

    // Destructor -> Called automaticlly for static allocation (manually for dynamic)
    ~Hero() {}

    Hero setHealth(int health) {
        this -> health = health;
        return *this;
    }
 
    void setLevel(int level) {
        this -> level = level;
    }
};

// :: is the scope resolution operator
int Hero::timeLeft = 1000;

int main() {
    /*
    Object --> Entity that can have:
        1. State/Properies
        2. Behaviour   
    */

    // h1 -> "Hello" type
	// Static Allocation
    Hero ramesh;

	// Dynamic Allocation
	Hero *a = new Hero;
    a->setHealth(89);
    // cout << a->health << endl; 

    /*
    Access Modifiers:
        Public -> Accessible both outside and inside of class
        Private (default) -> Accessible only inside of class
        Protected -> 
    */
    
	ramesh.setHealth(100);
	ramesh.setLevel(20);

    // Accessing properties
    // cout << ramesh.health << endl;
    // cout << ramesh.level << endl;

    // Copy Constructor (auto defined)
    // All the properties from "suresh" will be copied to "ramesh"
    Hero suresh(ramesh); 
    // Shallow copy: Changing values of "ramesh" will also change values of "suresh" automatically

    // Copy Assignment Operator
    // Hero a, b;
    // a = b;
    // Hero c = a;

    // Static
    // cout << Hero::timeLeft << endl;
    // cout << Hero::getTimeLeft() << endl;

}