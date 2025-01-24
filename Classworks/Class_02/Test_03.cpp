#include <iostream>
using namespace std;

class BankAccount {
	private:
		string name;
		double balance;
	public:
        void account_details() {
            cout << "Account Holder: " << name << "\nBalance: " << balance << "\n\n";
        }

		void update_name(string name) {
			this -> name = name;
		}

		void update_balance(double balance) {
			this -> balance = balance;
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
				this -> balance -= amount;
           	 	cout << amount << " has been withdrawn from account.\n\n";
        	} else if (amount > balance) {
            	cout << "Insufficient balance.\n";
        	} else {
            	cout << "Amount must be positive.\n";
        	}
    	}
};

int main () {
    BankAccount account;
    account.update_balance(50000);
    account.update_name("Debadarshi Omkar");
    account.account_details();

	account.deposit(80000);
	account.account_details();

	account.withdraw(3000);
	account.account_details();
}