#include <iostream>
#include <string>
using namespace std;

class Professor {
    // There are total 3 access modifiers in C++. (public, private, protected)
    private:
        long int Id;
        double salary;
    public:
        string name;
        string department;
        string subject;

        void professorDetails() {
            cout << "Name: " << name << "\nId: " << Id << "\nDepartment: " << department << "\nSubject: " << subject << "\nSalary: " << salary << "\n\n";
        }
        void changeDepartment(string newDepartment) {
            department = newDepartment;
        }

        long getId() {
            return Id;
        }
        void setId(long newId) {
            Id = newId;
        }

        double getSalary() {
            return salary;
        }
        void setSalary(double newSalary) {
            salary = newSalary;
        }
};

int main() {
    Professor prof1;
    prof1.name = "Debadarshi Omkar";
    prof1.department = "Computer Science";
    prof1.subject = "Programming";
    prof1.setSalary(80000);
    prof1.setId(41015006);
    prof1.professorDetails();
}