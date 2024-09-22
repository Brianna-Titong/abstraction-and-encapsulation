#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account() : balance(0.0) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " (Base Account)" << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << " (Base Account)" << endl;
        }
    }

    virtual void checkBalance() {
        cout << "Current balance: " << balance << " (Base Account)" << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " (Savings Account)" << endl;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient balance in Savings Account!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << " (Savings Account)" << endl;
        }
    }

    void checkBalance() override {
        cout << "Current balance: " << balance << " (Savings Account)" << endl;
    }

    void menu() {
        int choice;
        double amount;
        do {
            cout << "\nSavings Account Menu\n";
            cout << "1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Check Balance\n";
            cout << "4. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                withdraw(amount);
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                cout << "Returning to main menu.\n";
                break;
            default:
                cout << "Invalid, Try again.\n";
            }
        } while (choice != 4);
    }
};

class CurrentAccount : public Account {
public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " (Current Account)" << endl;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient balance in Current Account!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << " (Current Account)" << endl;
        }
    }

    void checkBalance() override {
        cout << "Current balance: " << balance << " (Current Account)" << endl;
    }

    void menu() {
        int choice;
        double amount;
        do {
            cout << "\nCurrent Account Menu\n";
            cout << "1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Check Balance\n";
            cout << "4. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                withdraw(amount);
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                cout << "Returning to main menu.\n";
                break;
            default:
                cout << "Invalid, Try again.\n";
            }
        } while (choice != 4);
    }
};

void mainMenu() {
    SavingsAccount savings;
    CurrentAccount current;

    int choice;
    do {
        cout << "\nMain Menu\n";
        cout << "1. Savings Account\n";
        cout << "2. Current Account\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            savings.menu();
            break;
        case 2:
            current.menu();
            break;
        case 3:
            break;
        default:
            cout << "Invalid, Try again.\n";
        }
    } while (choice != 3);
}

int main() {
    mainMenu();
    return 0;
}
