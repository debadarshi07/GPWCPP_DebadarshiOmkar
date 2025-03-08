#include <iostream>
using namespace std;

class Test {
public:
    Test() {
        cout << "Constructor called";
    }
};

int main() {
    Test *t = new Test();
    return 0;
}

/*
    O/P
    Constructor called

    new keyword dynamically allocates memory for a Test Object and the constructor is called.
*/