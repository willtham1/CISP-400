#include <iostream>
#include <fstream>
#include <string>
#include "BankAccount.h"  //bad practice to include cpp files

// size of the array - this is a constant
const int SIZE = 8;
//fill the array by passing an empty array and the file variable
void fillArray ( std::ifstream &input,BankAccount accountsArray[]);
//find the account with the largest balance and return its index
int largest(BankAccount accountsArray[]);
//find the account with the smallest balance and return its index
int smallest(BankAccount accountsArray[]);
//display all the bankaccounts in the array
void printArray(BankAccount accountsArray[]);
//check for duplicates in the array
//this sets the duplicate accounts to XXXX
void checkDuplicates(BankAccount accountsArray[]);

int main() {
  //create the array
  BankAccount accountsArray[SIZE];
  // open the file
  std::ifstream input("BankData.txt");
  //if open fails
  if (!input)
     std::cout<<"File Open Error";
  else {
    //call the fillArray method to populate array from the file
    fillArray(input,accountsArray);
    //call the printArray method to display the array
    printArray(accountsArray);
    //find and display the account with the largest balance
    std::cout<<"Largest Balance: "<<std::endl;
    std::cout<<accountsArray[largest(accountsArray)].toString()<<std::endl;
    //find and display the account with the largest balance
    std::cout<<"Smallest Balance :"<<std::endl;
    std::cout<<accountsArray[smallest(accountsArray)].toString()<<std::endl;
    //check duplicates and modify array
    checkDuplicates(accountsArray);
  

  }
}
void checkDuplicates(BankAccount accountsArray[]){
  bool duplicate=false;
  //nested loop
  //for each item in the bankaccount array, check it against every other account
  for (int i=0;i<SIZE-1;i++)// the second last compares with the last item
    for (int j=i+1;j<SIZE;j++){
    //if duplicate account is found, 
    // set duplicate to true 
    // then create a dummy BankAccount with XXXX and overwrite this in the array onto the duplicate copy
      // TODO
      //fill in 3-4 lines of code here to complete the function
        if (accountsArray[i].equals(accountsArray[j])) {
		duplicate=true;
		BankAccount temp("XXXX",0,0,0);
		accountsArray[j]=temp;
      }
      }
    
    if (duplicate) {
      std::cout<<"Duplicate Accounts Found : Reprinting List "<< std::endl<< std::endl;
     printArray(accountsArray);
    }
}

void fillArray ( std::ifstream &input,BankAccount accountsArray[]){
    std::string accountName; std::string lastName; std::string firstName;
  int id,accountNumber;
  double accountBalance;
  
  for (int i=0;i<SIZE;i++){
 //read all the fields from the file, token by token
  //one Bank Account at time
    input>>firstName>>lastName>>id>>accountNumber>>accountBalance;
      //accountBalance=accountBalance*100/100;
      accountName=firstName+" " + lastName;
    //create a Bank Account
      BankAccount 
      temp(accountName,id,accountNumber,accountBalance);
      //store the account in the BankAccount Array
      accountsArray[i]=temp;
  
    }

}
//presumes that negative balances will not be there
 //traverse the array to find a bank account with the largest account balance. Return the index of the corresponding bank account
int largest(BankAccount accountsArray[]){
  double largest =0; int index =0; // 0 is just an initialization
  //traverse the array using a for loop to find a bank account with the largest account balance. Return the index of the corresponding bank account
  // TO DO 
  //fill in the code here
  for (int i=0;i<SIZE;i++)
      if (accountsArray[i].getAccountBalance() > largest) {
	  largest=accountsArray[i].getAccountBalance();
	  index=i;
	}
  
  return index;
}
 //traverse the array to find a bank account with the smalles account balance. Return the index of the corresponding bank account
int smallest(BankAccount accountsArray[]){
  double smallest =0; int index =0; // 0 is just an initialization
 // TO DO fill in the code here
  for (int i=0;i<SIZE;i++)
      if (accountsArray[i].getAccountBalance() < smallest) {
	  smallest=accountsArray[i].getAccountBalance();
	  index=i;
      }
  return index;

}

void printArray(BankAccount accountsArray[]){
    std::cout<<"FAVORITE BANK - CUSTOMER DETAILS "<< std::endl;
    std::cout<<"--------------------------------"<< std::endl;
   for (int i=0;i<SIZE;i++)
     std::cout<<accountsArray[i].toString()<< std::endl;

}