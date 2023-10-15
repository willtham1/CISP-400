#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <sstream>

int BankAccount::count = 0;

BankAccount::BankAccount() : accountName(""), accountId(0), accountNumber(0), accountBalance(0) {
    count++;
}

BankAccount::BankAccount(std::string accountName, int id, int accountNumber, double accountBalance)
    : accountName(accountName), accountId(id), accountNumber(accountNumber), accountBalance(accountBalance) {
    count++;
}

double BankAccount::getAccountBalance() const {
    return accountBalance;
}

std::string BankAccount::getAccountName() const {
    return accountName;
}

int BankAccount::getAccountNumber() const {
    return accountNumber;
}

void BankAccount::setAccountBalance(double amount) {
    accountBalance = amount;
}

bool BankAccount::equals(const BankAccount& other) const {
    return (accountId == other.accountId);
}

int BankAccount::getCount() {
    return count;
}

bool BankAccount::withdraw(double amount) {
    if (accountBalance - amount >= 0) {
        accountBalance -= amount;
        return true;
    }
    return false;
}

void BankAccount::deposit(double amount) {
    accountBalance += amount;
}

void BankAccount::addReward(double amount) {
    const double rewardsRate = 0.1; // You may adjust this rate as needed
    accountBalance += rewardsRate * amount;
}

std::string BankAccount::toString() const {
    std::string accountInfo = "Account Name: " + accountName + "\n";
    accountInfo += "Account Number: " + std::to_string(accountNumber) + "\n";

    // Format the accountBalance with 2 decimal places
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << accountBalance;

    accountInfo += "Account Balance: " + stream.str() + "\n";
    return accountInfo;
}
