#include <iostream>
using namespace std;

class MyBat {
private:
    int a, b, c, d;

public:
    void setData();
    void getData();
};

void MyBat::setData() {
    a = 10;
    b = 20;
    c = 30;
    d = 40;
}

void MyBat::getData() {
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
}

int main() {
    MyBat bat1, bat2, bat3, bat4;

    bat1.setData();
    bat1.getData();

    return 0;
}