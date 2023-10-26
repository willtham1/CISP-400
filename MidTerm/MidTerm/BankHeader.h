#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cstdlib>//for exit
#include "BankAccountHeader.h"
using namespace std;

//Bank Class Header file
// This class simulates a Bank by storing Bank Accounts in a vector
// It provides an API for customer interaction via ATM like functions 
class Bank{
private:
  std::shared_ptr<BankAccount> bptr;
  std::vector<std::shared_ptr<BankAccount>> accountsVector;
public:
//constructor that reads bank database from file
//it calls the fillVector method to populate the database
Bank(std::string filename);
//withdraw amount
void withdraw();
//check balance
void viewBalance();
//deposit amount
void deposit();
//helper function
void fillVector (std::ifstream &input,std::vector<std::shared_ptr<BankAccount>> &accountsVector);
//admin function print all accounts
void printVector(std::vector<std::shared_ptr<BankAccount>> &accountsVector);
//sort accounts
void sort(std::vector<shared_ptr<BankAccount>> &accountsVector);


};