#include "CheckingAccount.h"

#include "UserAccount.h"

using std::string;

CheckingAccount::CheckingAccount() { UserAccount(); }

CheckingAccount::CheckingAccount(std::string accountName, int id,
                                 int accountNumber, double accountBalance)
    // Using this t make sure the parameters are correctly passed
    : UserAccount(accountName, id, accountNumber, accountBalance) {
  // Do nothing here, just let inheritance do its thing
}

string CheckingAccount::toString() {
  return "Account Name: " + getAccountName() + "\n" +
         "Account Number: " + std::to_string(getAccountNumber()) + "\n" +
         "Account Balance: " + fixPoint(std::to_string(getAccountBalance())) +
         "\n" + "Account Type: Checking \n";
}

bool CheckingAccount::withdraw(double amount) {
  // Check if withdraw will go below minimum balance first
  if ((getAccountBalance() - amount) < MIN_BALANCE_CHECKING) {
    // If withdraw goes below minimum balance, deny withdraw and return false
    return false;
  }
  // Else, allow the withdraw, return true
  setAccountBalance(getAccountBalance() - amount);
  return true;
}

void CheckingAccount::deposit(double amount) {
  setAccountBalance(getAccountBalance() + amount);
}

const double CheckingAccount::MIN_BALANCE_CHECKING = 99.99;
