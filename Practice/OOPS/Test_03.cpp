#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    float* markPtr;  // This stores the address of a float value as mark, which is later passed to all the objects created by copy constructor. Hence, Shallow copy of mark will occur for all the objects.

    // Constructor
    Student(string name, float mark) {
        this -> name = name;
        markPtr = new float;
        *markPtr = mark;
    }

    // Copy Constructor
    Student(Student &other) {
        this -> name = other.name;
        this -> markPtr = other.markPtr;
    }

    void getStudentInformation() {
        cout << "Name: " << name << "\nCGPA: " << *markPtr << "\n" << endl;
    }

    // Destructor -- Deletes the dynamically allocated memory.
    ~Student() {
        delete markPtr;
    }
};

int main() {
    Student student1("Debadarshi Omkar", 6.8);
    student1.getStudentInformation();

    Student student2(student1);
    student2.getStudentInformation();

    student2.name = "Pat Cummins";
    *student2.markPtr = 9.5;

    student1.getStudentInformation();
    student2.getStudentInformation();
}