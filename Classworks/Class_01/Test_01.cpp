#include <iostream> // for std::cout
using namespace std;    // for std::cout

void printName(string name) {
    cout << name << endl;
}

void printNickName(string name) {
    cout << name << endl;
}

int main() {
    cout << "Debadarshi Omkar" << endl;     // prints strings

    int num1;
    int num2;
    int sum = 0;

    cout << "Enter the first number: ";
    cin >> num1;      // Takes input
    cout << "Enter the second number: ";
    cin >> num2;

    sum = num1 + num2;
    cout << "The sum of " << num1 << " and " << num2 <<" is: "<< sum << endl;


    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of void*: " << sizeof(void*) << endl;
    cout << "Size of short int: " << sizeof(short int) << endl;
    cout << "Size of long int: " << sizeof(long int) << endl;


    printName("Debadarshi Omkar");
    printNickName("Guddu");

    return 0;
}