#include <iostream>
#include <string>
using namespace std;

// Multiple Inheritance
class Student {
public:
    string name;
    long rollNo;

    Student(string name, long rollNo) {
        this -> name = name;
        this -> rollNo = rollNo;
    }
};

class Teacher {
public:
    string subject;
    double salary;

    Teacher(string subject, double salary) {
        this -> subject = subject;
        this -> salary = salary;
    }
};

class TeachingAssistant : public Student, public Teacher {
public:
    TeachingAssistant(string name, long rollNo, string subject, double salary) : Student(name, rollNo), Teacher(subject, salary) {}

    void getTAInformation() {
        cout << "Name: " << name << endl;
        cout << "Roll no: " << rollNo << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << "\n" << endl;
    }
};

int main() {
    TeachingAssistant assitant_1("Debadarshi Omkar", 41015006, "Python Programming", 50000);
    assitant_1.getTAInformation();

    TeachingAssistant assistant_2("Patrick Cummins", 41000001, "Crowd Management", 800000);
    assistant_2.getTAInformation();
}