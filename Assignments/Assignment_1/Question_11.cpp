#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int age;
    string profession;
    double yearlySalary;
    string homeAddress;
    string panNumber;
    double tax;

public:
    Employee() {
        name = "Not provided";
        age = 0;
        profession = "Not provided";
        yearlySalary = 0.0;
        homeAddress = "Not provided";
        panNumber = "Not provided";
        tax = 0.0;
    }

    Employee(string n = "Not provided", int a = 0, string p = "Not provided", double salary = 0.0, string address = "Not provided", string pan = "Not provided") {
        name = n;
        age = a;
        profession = p;
        yearlySalary = salary;
        homeAddress = address;
        panNumber = pan;
        tax = 0.0;
    }

    void calculateTax() {
        if (yearlySalary <= 250000) {
            tax = 0.0;
        }
        else if (yearlySalary <= 500000) {
            tax = (yearlySalary - 250000) * 0.05;
        }
        else if (yearlySalary <= 1000000) {
            tax = 250000 * 0.05 + (yearlySalary - 500000) * 0.20;
        }
        else {
            tax = 250000 * 0.05 + 500000 * 0.20 + (yearlySalary - 1000000) * 0.30;
        }
    }

    void printTax() {
        cout << "\nEmployee Details and Tax Computation:" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Profession: " << profession << endl;
        cout << "Yearly Salary: ₹" << yearlySalary << endl;
        cout << "Home Address: " << homeAddress << endl;
        cout << "PAN Number: " << panNumber << endl;
        cout << "Annual Tax: ₹" << tax << endl;
        cout << "----------------------------------------" << endl;
    }
};

int main() {
    string name, profession, address, pan;
    int age;
    double salary;

    cout << "Enter Employee Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Profession: ";
    getline(cin, profession);
    cout << "Enter Yearly Salary: ₹";
    cin >> salary;
    cin.ignore();
    cout << "Enter Home Address: ";
    getline(cin, address);
    cout << "Enter PAN Number: ";
    getline(cin, pan);

    Employee emp(name, age, profession, salary, address, pan);

    emp.calculateTax();
    emp.printTax();

    return 0;
}