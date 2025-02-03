#include <iostream>
#include <string>
using namespace std;

class Parent {
    public:
    void getInfo() {
        cout << "Parent Class" << endl;
    }

    virtual void hello() {
        cout << "Hello from Parent." << endl;
    }
};

class Child : public Parent {
    public:
    void hello() override {
        cout << "Hello from Child." << endl;
    }
};

int main() {
    Child child;
    child.hello();

    Parent *child1 = new Child();
    child1 -> hello();
}