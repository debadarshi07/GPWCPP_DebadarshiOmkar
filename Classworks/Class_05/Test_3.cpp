#include <iostream>
using namespace std;

class Box {
public:
    double width, height, length;
    Box(double w, double h, double l) : width(w), height(h), length(l) {}

    void printVolume() const {
        cout << "Volume: " << width * height * length << endl;
    }

    void changeDimensions(double width, double height, double length) {
        this -> width = width;
        this -> height = height;
        this -> length = length;
    }
};

void modifyBoxByValue(Box box) {
    box.changeDimensions(10, 5, 4);
}

void modifyBoxByReference(Box &box) {
    box.changeDimensions(10, 5, 4);
}

void modifyBoxByPointer(Box *box) {
    box->changeDimensions(1, 50, 40);
}

int main() {
    Box box1(5, 3, 2);

    cout << "Before modifyBoxByValue function: " << endl;
    box1.printVolume();
    modifyBoxByValue(box1);
    cout << "After modifyBoxByValue function: " << endl;
    box1.printVolume();

    cout << "\nBefore modifyBoxByReference function: " << endl;
    box1.printVolume();
    modifyBoxByReference(box1);
    cout << "After modifyBoxByReference function: " << endl;
    box1.printVolume();

    cout << "\nBefore modifyBoxByPointer function:" << endl;
    box1.printVolume();
    modifyBoxByPointer(&box1);
    cout << "After modifyBoxByPointer function: " << endl;
    box1.printVolume();

    return 0;
}