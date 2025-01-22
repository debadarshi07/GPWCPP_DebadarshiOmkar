#include <iostream>
using namespace std;

namespace MathCalculation {
    void add(int a, int b) {
        cout << "Addition of " << a << " and " << b << " is: " << a + b << endl;
    }

    void subtract(int a, int b) {
        cout << "Difference between " << a << " and " << b << " is: " << a - b << endl;
    }

    void multiply(int a, int b)  {
        cout << "Product of " << a << " and " << b << " is: " << a * b << endl;
    }

    void divide(int a, int b) {
        if (b != 0) {
            cout << "Quotient of " << a << " and " << b << " is: " << a / b << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    }
}

int main() {
    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    MathCalculation :: add(num1, num2);
    MathCalculation :: subtract(num1, num2);
    MathCalculation :: multiply(num1, num2);
    MathCalculation :: divide(num1, num2);

    return 0;
}