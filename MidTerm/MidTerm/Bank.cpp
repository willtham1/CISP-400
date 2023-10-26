#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cstdlib>//for exit
#include "BankHeader.h"
#include <algorithm>

using namespace std;

//implement all the functions in the BankHeader file
Bank::Bank(std::string filename)
{
    // Constructor: Read bank database from the given file and populate accountsVector.
    ifstream input(filename);
    if (!input) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    // Fill the vector with the accounts
    fillVector(input, accountsVector);
    sort(accountsVector);
    printVector(accountsVector);
}

void Bank::withdraw()
{
    // Ask for the account name, number and amount to withdraw
    string firstName, lastName, accountName;
    int accountNumber;
    double amount;
    cout << "What is the Account First Name? ";
    cin >> firstName;
    cout << "What is the Account Last Name? ";
    cin >> lastName;
    accountName = firstName + " " + lastName;
    cout << "What is the Account Number? ";
    cin >> accountNumber;
    cout << "What is the dollar amount? ";
    cin >> amount;
    cout << endl;
    // Find the account and then withdraw the amount
    for (const auto& account : accountsVector) {
        if (account->getAccountNumber() == accountNumber && account->getAccountName() == accountName) {
            if (amount > 0) {
                // If the amount is negative say insufficient funds
                if (amount > account->getAccountBalance()) {
					cout << "Insufficient funds" << endl;
					return;
                }
                else {
				account->withdraw(amount);
				cout << "Amount widthdrawn from account" << endl;
                }
			}
			return;
		}
	};
}

void Bank::viewBalance()
{
    // Ask for the account name and number
    string firstName, lastName, accountName;
    int accountNumber;
    double accountBalance;
    cout << "What is the Account First Name? ";
    cin >> firstName;
    cout << "What is the Account Last Name? ";
    cin >> lastName;
    accountName = firstName + " " + lastName;
    cout << "What is the Account Number? ";
    cin >> accountNumber;
    // Find the account
    for (const auto& account : accountsVector) {
        if (account->getAccountNumber() == accountNumber && account->getAccountName() == accountName) {
            cout << "\n----------------------------------------\n";
            cout << "Account Name: " << account->getAccountName() << endl;
            cout << "Account Number: " << account->getAccountNumber() << endl;
            cout << "Account Balance: " << account->getAccountBalance() << endl;
            cout << "----------------------------------------\n";
            return;
        }
    };
}

void Bank::deposit()
{
    // Ask for the account name, number and amount to deposit
    string firstName, lastName, accountName;
    int accountNumber;
    double amount;
    cout << "What is the Account First Name? ";
    cin >> firstName;
    cout << "What is the Account Last Name? ";
    cin >> lastName;
    accountName = firstName + " " + lastName;
    cout << "What is the Account Number? ";
    cin >> accountNumber;
    cout << "What is the dollar amount? ";
    cin >> amount;
    cout << endl;
    // Find the account and then deposit the amount
    for (const auto& account : accountsVector) {
        if (account->getAccountNumber() == accountNumber && account->getAccountName() == accountName) {
            if (amount > 0) {
                account->deposit(amount);
                cout << "Amount deposited into account" << endl;
            }
            else {
				cout << "Invalid amount" << endl;
			}
        }
    }
}

void Bank::fillVector(std::ifstream& input, std::vector<std::shared_ptr<BankAccount>>& accountsVector)
{
    // Fill the vector with the accounts
    string accountName;string lastName;string firstName, inputLine;
    int id, accountNumber;
    double accountBalance;
    while (!input.eof()) {
        getline(input, inputLine);
        istringstream streamLine(inputLine);
        streamLine >> firstName >> lastName >> id >> accountNumber >> accountBalance;
        accountName = firstName + " " + lastName;
        shared_ptr<BankAccount> temp = make_shared<BankAccount>(accountName, id, accountNumber, accountBalance);
        accountsVector.push_back(temp);
    }
}

void Bank::printVector(std::vector<std::shared_ptr<BankAccount>>& accountsVector)
{
    // Print the vector
    auto iter = accountsVector.begin();
    for (iter = accountsVector.begin();iter < accountsVector.end();iter++)
        cout << (*iter)->toString() << endl;
}

void Bank::sort(std::vector<std::shared_ptr<BankAccount>>& accountsVector) {
    // Sort the vector
    if (accountsVector.size() > 1) {
        std::sort(accountsVector.begin(), accountsVector.end(), [](const std::shared_ptr<BankAccount>& a, const std::shared_ptr<BankAccount>& b) {
            return a->getAccountNumber() < b->getAccountNumber();
            });
    }
}
