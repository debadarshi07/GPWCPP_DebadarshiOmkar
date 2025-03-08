#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A "; }
    ~A() { cout << "~A "; }
};
void func() {
    static A obj;
}

int main() {
    func();
    func();
    cout << "Main ";
    return 0;
}

/*
    O/P
    A Main ~A

    Constructor is invoked while object is created and Destructor is called once the object goes out of scope. 
    Here a static object has been created which has a lifetime until program completes execution.
*/