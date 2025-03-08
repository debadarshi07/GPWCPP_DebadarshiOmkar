#include <iostream>
using namespace std;

class MyClass {
public:
    ~MyClass() {
        cout << "My destructor" << endl;
    }
};

int main() {
    MyClass obj;
    obj.~MyClass();

    return 0;
}

/*
    O/P
    My destructor
    My destructor

    First the object itself has called the destructor and then the object got out of scope after execution hence destructor has been invoked once again by default.
*/