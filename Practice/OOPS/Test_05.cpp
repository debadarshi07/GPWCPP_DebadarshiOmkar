#include <iostream>
#include <string>
using namespace std;

// Multilevel Inheritance
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
};

class GraduationStudent : public Student {
public:
    string researchField;
    GraduationStudent(string name, int age, string standard, int section, string researchField) : Student(name, age, standard, section) {
        this -> researchField = researchField;
    }

    
    void getStudentInformation() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Standard: " << standard << endl;
        cout << "Section: " << section << endl;
        cout << "Research Field: " << researchField << "\n" << endl;
    }
};

int main() {
    GraduationStudent student1("Debadarshi Omkar", 21, "Graduation", 41028, "Natural Language Processing");
    student1.getStudentInformation();

    GraduationStudent student2("Pat Cummins", 35, "Cricketer", 87659, "Crowd Silencing");
    student2.getStudentInformation();
}