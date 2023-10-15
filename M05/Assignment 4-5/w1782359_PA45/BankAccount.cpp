#include <string>
#include <iostream>
#include "BankAccount.h"

     // BankAccount::BankAccount();

      BankAccount::BankAccount(std::string accountName, int id, int accountNumber, double accountBalance){
        this->id=id;
        this->accountNumber=accountNumber;
        this->accountName=accountName;
        this->accountBalance=accountBalance;

      }
       //getters
      
         std::string BankAccount::getAccountName(){
          return accountName;
        }
        int BankAccount::getAccountNumber(){
          return accountNumber;
        }
        double BankAccount::getAccountBalance(){
          return accountBalance;
        }
      // setters : cannot change number and accountName
      //setting balance may be needed by admin

      void BankAccount::setAccountBalance(double accountBalance){
        this->accountBalance=accountBalance;
      }
      //helper method
      std::string fixPoint(std::string number){
          int i= number.find('.');
          return number.substr(0,i+3);
      }
      std::string BankAccount::toString(){
        //std::cout<<fixPoint(std::to_string(accountBalance));
        return "Account Name: "+accountName+"\n"+
               "Account Number: "+std::to_string(accountNumber)+"\n"+
               "Account Balance: " +fixPoint(std::to_string(accountBalance))+"\n";
                
      }

      bool BankAccount::withdraw(double amount){

        if (accountBalance-amount>MIN_BALANCE){
             accountBalance-=amount;
             return true;
        }
        else 
          return false; // do nothing
      }
      
      void BankAccount::deposit(double amount){
        accountBalance+= amount;
        if (amount > MIN_REWARD_AMOUNT)
           addReward(amount);
      }
     
      void BankAccount::addReward(double amount){
          accountBalance +=accountBalance+REWARD_RATE*amount;
      }
      int BankAccount::getId(){
        return id;
      }
//TO DO fill in the code here.
// check if this account name is the same as the other account name
// and account ID  is the same as the other account ID
//if so return true, else return false
      bool BankAccount::equals(BankAccount other){
      //write the code here;
          if (this->accountName==other.accountName && this->id==other.id)
              return true;
		  else
        return false; //change this.
      }
  const double BankAccount::MIN_BALANCE=9.99;
  const double BankAccount::MIN_REWARD_AMOUNT=1000.0;
  const double BankAccount::REWARD_RATE=0.04;