#include <iostream>
using namespace std;

class BankAccount {
	private:
	string accountHolder;
	double balance;

	void deposit(double amount) {
		balance += amount;
	}

	void withdraw(double amount) {
		if (amount < balance) {
			cout << "Insufficient Balance." << endl;
			return;
		}
		balance -= amount;
	}

	public:
	void setAccountHolder(string name) {
		accountHolder = name;
	}
	string getAccountHolder() {
		return accountHolder;
	}
	
	void setBalance(double balance) {
		this -> balance = balance;
	}
	double getBalance() {
		return balance;
	}
	
	void depositMoney(double amount) {
		deposit(amount);
	}
	void withdrawMoney(double amount) {
		withdraw(amount);
	}
	
	void getDetails() {
		cout << "Account Holder: " << this -> getAccountHolder() << "\nBalance: " << this -> getBalance() << endl;
	}
};

int main() {
	BankAccount me;
	me.setAccountHolder("Debadarshi Omkar");
	me.setBalance(5000);

	me.depositMoney(5000);
	me.withdrawMoney(100);

	me.getDetails();
	return 0;
}