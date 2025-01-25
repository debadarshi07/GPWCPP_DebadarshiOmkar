#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this -> name = name;
        this -> age = age;
    }
};

class Student : public Person {
public:
    string standard;
    int section;

    Student(string name, int age, string standard, int section) : Person(name, age) {
        this -> standard = standard;
        this -> section = section;
    }

    void getStudentInformation() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Standard: " << standard << endl;
        cout << "Section: " << section << "\n" << endl;
    }
};

int main() {
    Student student1("Debadarshi Omkar", 21, "Graduation", 41028);
    student1.getStudentInformation();

    Student student2("Pat Cummins", 35, "Cricketer", 87659);
    student2.getStudentInformation();
}