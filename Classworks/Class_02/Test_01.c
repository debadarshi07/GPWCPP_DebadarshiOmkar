#include <stdio.h>
#include <string.h>

typedef struct BankAccount {
    char name[30];
    double balance;

    void(*update_name)(BA* acc, char name[30]);
    void(*update_balance)(BA* acc, double balance);
} BA;

void account_details(BA* account) {
    printf("Account Holder: %s\nBalance: %.2lf\n\n", account -> name, account -> balance);
}

void deposit(BA* account, double amount) {
    if (amount > 0) {
        account -> balance += amount;
    } else {
        printf("Amount must be positive.\n");
    }
}

void withdraw(BA* account, double amount) {
    if (amount > 0 && amount <= account -> balance) {
        printf("%lf has been withdrawn from account.\n", amount);
    } else if (amount > account -> balance) {
        printf("Insufficient balance.\n");
    } else {
        printf("Amount must be positive.\n");
    }
}

void update_name(BA* account, char name[30]) {
    strcpy(account -> name, name);
}

void update_balance(BA* account, double amount) {
    account -> balance = amount;
}

int main() {
    BA account_1 = {"Debadarshi", 50000};
    BA* acc_1 = &account_1;

    account_details(acc_1);

    deposit(acc_1, 5000);
    account_details(acc_1);

    deposit(acc_1, 2000);
    account_details(acc_1);

    account_1.update_name(&account_1, "Deba R");
    account_details(&account_1);

    account_1.update_balance(&account_1, 25000.50);
    account_details(&account_1);
}