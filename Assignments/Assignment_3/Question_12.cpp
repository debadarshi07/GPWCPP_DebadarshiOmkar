#include <iostream>
using namespace std;

enum colour {
    blue, red, yellow
};

int main() {
    enum colour c;
    c = yellow;
    cout << c << endl;
}

/*
    O/P
    2
*/