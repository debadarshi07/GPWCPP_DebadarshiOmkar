#include <iostream>
using namespace std;

class Sample {
public:
    Sample(int x = 10) {
        cout << "Value: " << x << endl;
    }
};

int main() {
    Sample obj;
    return 0;
}

/*
    O/P
    Value: 10
    Constructor is called during object creation and the constructor has a default argument x.
*/