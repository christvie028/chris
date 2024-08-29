#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_ACCOUNTS = 100;

struct Account {
    string username;
    string password;
    double balance;
};

vector<Account> accounts;

void createAccount() {
    if (accounts.size() >= MAX_ACCOUNTS) {
        cout << "Maximum number of accounts reached." << endl;
        return;
    }

    Account newAccount;
    cout << "Please enter your username: ";
    cin >> newAccount.username;
    cout << "Please enter your password: ";
    cin >> newAccount.password;
    newAccount.balance = 0.0;

    accounts.push_back(newAccount);
    cout << "Account created successfully!" << endl;
}

int login() {
    string username, password;
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;

    for (int i = 0; i < accounts.size(); i++) {
        if (username == accounts[i].username && password == accounts[i].password) {
            return i; // Return the index of the logged-in account
        }
    }

    cout << "Login failed!" << endl;
    return -1;
}

void deposit(int accountIndex) {
    double amount;
    cout << "Enter the amount to deposit: ";
    cin >> amount;

    if (amount < 0) {
        cout << "Invalid amount." << endl;
        return;
    }

    accounts[accountIndex].balance += amount;
    cout << "Deposit successful!" << endl;
}

void withdraw(int accountIndex) {
    double amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    if (amount < 0 || amount > accounts[accountIndex].balance) {
        cout << "Invalid amount or insufficient funds." << endl;
        return;
    }

    accounts[accountIndex].balance -= amount;
    cout << "Withdrawal successful!" << endl;
}

void checkBalance(int accountIndex) {
    cout << "Your balance is: " << accounts[accountIndex].balance << endl;
}

int main() {
    while (true) {
        cout << "\nWelcome to the ATM\n";
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Quit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2: {
                int accountIndex = login();
                if (accountIndex != -1) {
                    while (true) {
                        cout << "\n1. Deposit\n";
                        cout << "2. Withdraw\n";
                        cout << "3. Check Balance\n";
                        cout << "4. Logout\n";

                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 1:
                                deposit(accountIndex);
                                break;
                            case 2:
                                withdraw(accountIndex);
                                break;
                            case 3:
                                checkBalance(accountIndex);
                                break;
                            case 4:
                                cout << "Logging out...\n";
                                break;
                            default:
                                cout << "Invalid choice.\n";
                        }

                        if (choice == 4) {
                            break; // Break out of the inner loop to return to the main menu
                        }
                    }
                }
                break;
            }
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
