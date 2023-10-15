#include <string>
#include "BankAccountHeader.h"
BankAccount::BankAccount() {
    accountName = "";
    accountNumber = 0;
    accountBalance = 0;
    MIN_BALANCE = 9.99;
    REWARD_RATE = 0.04;
    MIN_REWARD_AMOUNT = 1000.00;
};
BankAccount::BankAccount(std::string accountName, int accountNumber, double accountBalance) {
    this->accountNumber = accountNumber;
    this->accountName = accountName;
    this->accountBalance = accountBalance;
    MIN_BALANCE = 9.99;
    REWARD_RATE = 0.04;
    MIN_REWARD_AMOUNT = 1000.00;

}
std::string BankAccount::getAccountName() {
    // fill this 
    return accountName;
}
int BankAccount::getAccountNumber() {
    // fill this 
    return accountNumber;
}
double BankAccount::getAccountBalance() {
    //fill this;
    return accountBalance;
}
// setters : cannot change number and accountName
//setting balance may be needed by admin

void BankAccount::setAccountBalance(double accountBalance) {
    //fill this
    this->accountBalance = accountBalance;
}

std::string BankAccount::toString() {
    return "Account Name: " + accountName + "\n" +
        "Account Number: " + std::to_string(accountNumber) + "\n" +
        "Account Balance: " + std::to_string(accountBalance) + "\n";

}

bool BankAccount::withdraw(double amount) {
    // if there is enough balance in the account, deduct
    //and return true otherwise do NOT deduct and return false
    //use MIN_BALANCE to check
    if (accountBalance - amount >= MIN_BALANCE) {
        accountBalance -= amount;
        return true;
    }
    else {
        return false;
    }
}

void BankAccount::deposit(double amount) {
    //add the amount, check if eligible for rewards, if so
    //if so call addReward method
    //use MIN_REWARD to check
    accountBalance = accountBalance + amount;
    if (amount > MIN_REWARD_AMOUNT) {
        addReward(amount);
    }
}

void BankAccount::addReward(double amount) {
    accountBalance = accountBalance + REWARD_RATE * amount;
}
//getters


