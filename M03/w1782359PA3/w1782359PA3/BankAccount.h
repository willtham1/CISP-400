#ifndef BANKACCOUNTHEADER_H
#define BANKACCOUNTHEADER_H

#include <string>
#include <vector>

class BankAccount {
private:
    std::string accountName;
    int accountId;
    int accountNumber;
    double accountBalance;
    static int count;

public:
    BankAccount();
    BankAccount(std::string accountName, int id, int accountNumber, double accountBalance);
    double getAccountBalance() const;
    std::string getAccountName() const;
    int getAccountNumber() const;
    void setAccountBalance(double amount);
    bool equals(const BankAccount& other) const;
    static int getCount();
    bool withdraw(double amount);
    void deposit(double amount);
    void addReward(double amount);
    std::string toString() const;
};

#endif
