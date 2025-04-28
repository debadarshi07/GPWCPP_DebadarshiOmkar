#include <iostream>
using namespace std;

class MyBat {
private:
    int a, b, c, d;

public:
    void setData();
    void getData();
};

void MyBat :: setData() {
    a = 10;
    b = 20;
    c = 30;
    d = 40;
}

void MyBat :: getData() {
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
}