// BANK USER MENU

#include <iostream>
using namespace std;

class Bank {
private:
    long int acc_no;
    long int balance;

public:
    void createAccount();
    void deposit();
    void withdraw();
    void displayBalance();
};

void Bank::createAccount() {
    cout << "Enter account number: ";
    cin >> acc_no;

    cout << "Enter initial balance: ";
    cin >> balance;
}

void Bank::deposit() {
    long int money;
    cout << "Enter amount to deposit: ";
    cin >> money;

    balance += money;
    cout << "Deposit successful.\n";
}

void Bank::withdraw() {
    long int money;
    cout << "Enter amount to withdraw: ";
    cin >> money;

    if (money > balance) {
        cout << "Insufficient balance.\n";
    } else {
        balance -= money;
        cout << "Withdrawal successful.\n";
    }
}

void Bank::displayBalance() {
    cout << "Current balance: " << balance << endl;
}

int main() {
    Bank a;
    int choice;

    a.createAccount();

    while (true) {
        cout << "\n=== User Menu ===\n" << "1. Deposit\n" << "2. Withdraw\n" << "3. Display Balance\n" << "4. Exit\n" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                a.deposit();
                break;

            case 2:
                a.withdraw();
                break;

            case 3:
                a.displayBalance();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
