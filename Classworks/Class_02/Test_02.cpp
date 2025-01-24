#include <iostream>
using namespace std;

struct BankAccount {
    string name;
    double balance;

    void account_details() {
        cout << "Account Holder: " << name << "\nBalance: " << balance << "\n\n";
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Amount must be positive.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            cout << amount << " has been withdrawn from account.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            cout << "Amount must be positive.\n";
        }
    }

    void update_name(string n) {
        name = n;
    }

    void update_balance(double amount) {
        balance = amount;
    }
};

int main() {
    BankAccount account = {"Debadarshi", 500000};
    BankAccount* acc = &account;

    acc -> account_details();

    acc -> deposit(5000);
    acc -> account_details();

    acc -> withdraw(10000);
    acc -> account_details();

    acc -> update_name("Debadarshi Omkar");
    acc -> account_details();

    acc -> update_balance(70000);
    acc -> account_details();
}