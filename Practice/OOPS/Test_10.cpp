#include <iostream>
#include <string>
using namespace std;

class Shape {   // Abstract class
    virtual void draw() = 0;  // Pure virtual function
};

class Square : public Shape {
    public:
    void draw() override {
        cout << "Drawing a Square." << endl;
    }
};

int main() {
    Square square;
    square.draw();

    return 0;
}