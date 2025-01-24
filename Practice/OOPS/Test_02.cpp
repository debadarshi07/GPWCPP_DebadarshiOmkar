#include <iostream>
#include <string>
using namespace std;

class Professor {
    private:
        long int Id;
        double salary;
    public:
        // Non-parametrized Constructor
        Professor() {
            department = "Computer Science";
        }

        // Parametrized Constructor
        Professor(string name, string department, string subject, double salary) {
            this -> name = name;
            this -> department = department;
            this -> subject = subject;
            this -> salary = salary;
        }

        // Copy Constructor
        // Professor(Professor& other) {
        //     this -> name = other.name;
        //     this -> department = other.department;
        //     this -> subject = other.subject;
        //     this -> salary = other.salary;
        // }

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
    Professor prof1("Debadarshi Omkar", "Computer Science", "Programming", 85000);
    prof1.professorDetails();

    Professor prof2(prof1);
    prof2.professorDetails();
}