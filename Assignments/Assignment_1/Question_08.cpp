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
*/