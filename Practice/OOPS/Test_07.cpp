#include <iostream>
#include <string>
using namespace std;

// Compile time polymorphism
class Print {
public:
    void print(string name) {
        cout << "Printing string: " << name << endl;
    }

    void print(int number) {
        cout << "Printing integer: " << number << endl;
    }

    void print(char character) {
        cout << "Printing character: " << character << endl;
    }
};

int main() {
    Print printer;
    printer.print("Debadarshi Omkar");
    printer.print(5006);
    printer.print('G');

    return 0;
}