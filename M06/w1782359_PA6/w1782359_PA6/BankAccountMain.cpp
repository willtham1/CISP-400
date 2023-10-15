#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include<memory>
#include <cstdlib>//for exit
#include "BankAccount.h"  //bad practice to include cpp files

using namespace std;

void fillArray (ifstream &input,vector<shared_ptr<BankAccount>> &accountsVector);
int largest(vector<shared_ptr<BankAccount>> &accountsVector);
int smallest(vector<shared_ptr<BankAccount>> &accountsVector);
void printArray(vector<shared_ptr<BankAccount>>&accountsVector);
void checkDuplicates(vector<shared_ptr<BankAccount>> &accountsVector);
void insertAccounts(vector<shared_ptr<BankAccount>> &accountVector);
int main() {
  vector<shared_ptr<BankAccount>> accountsVector;
  try{
  ifstream input("BankData.txt");
  if (input){  
    //cout<<" FIle Open "<<endl;
    
    fillArray(input,accountsVector);
    //getCount using static variable getCount
    //getCount using vector size
    printArray(accountsVector);
    
    cout<<"Largest Balance: "<<endl;
    cout<<accountsVector[largest(accountsVector)]->toString()<<endl;
    cout<<"Smallest Balance :"<<endl;
    cout<<accountsVector[smallest(accountsVector)]->toString()<<endl;
    cout<<"Using the static count, there are "<<BankAccount::count<< " accounts"<<endl;
    cout<<"Using vector size, there are "<<accountsVector.size()<< " accounts"<<endl;
    
    checkDuplicates(accountsVector);
    cout<<"Using the static count, there are "<<BankAccount::count<< " accounts"<<endl;
     cout<<"Using vector size, there are "<<accountsVector.size()<< " accounts"<<endl;
     insertAccounts(accountsVector);
     cout<<"\nInserted Three New Accounts: Reprinting List \n" <<endl;
     printArray(accountsVector);
      cout<<"Using the static count, there are "<<BankAccount::count<< " accounts"<<endl;
     cout<<"Using vector size, there are "<<accountsVector.size()<< " accounts"<<endl;
    
    
  }
  else 
     throw string("File Open Error");
}
catch (string message){
   cout<<message<<endl;
   exit(0);
}
}
void checkDuplicates(vector<shared_ptr<BankAccount>>  &accountsVector){
  // *** Write this method
    bool duplicates = false;
    int length = accountsVector.size();

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            // Check if the account id is equal to the other account id
            if (accountsVector[i]->equals(accountsVector[j]))
            {
				// Remove the duplicate account
                accountsVector.erase(accountsVector.begin() + j);
                length = accountsVector.size();
                duplicates = true;
			}
        }
    }
    if (duplicates) cout << "Duplicates Accounts Found: Reprinting list\n" << endl;
    // Print the list of accounts
    printArray(accountsVector);
    }
  
   
void fillArray (ifstream &input,vector<shared_ptr<BankAccount>>  &accountsVector){
   string accountName;string lastName;string firstName,inputLine;
  int id,accountNumber;
  double accountBalance;
  while (!input.eof()){
    getline(input,inputLine);
    istringstream streamLine(inputLine);
    streamLine>>firstName>>lastName>>id>>accountNumber>>accountBalance;
      accountName=firstName+" " + lastName;
      shared_ptr<BankAccount> temp=make_shared<BankAccount>(accountName,id,accountNumber,accountBalance);
      accountsVector.push_back(temp);
    }

}
//presumes that negative balances will not be there
int largest(vector<shared_ptr<BankAccount>>  &accountsVector){
 // ****write this method
    vector<shared_ptr<BankAccount>>::iterator iter = accountsVector.begin();
    int largest = 0;
    for (iter = accountsVector.begin(); iter < accountsVector.end(); iter++)
    {
        if ((*iter)->getAccountBalance() > accountsVector[largest]->getAccountBalance())
        {
			largest = iter - accountsVector.begin();
		}
	}
    return largest;
}
int smallest(vector<shared_ptr<BankAccount>>  &accountsVector){
// *** write this method
    vector<shared_ptr<BankAccount>>::iterator iter = accountsVector.begin();
	int smallest = 0;
    for (iter = accountsVector.begin(); iter < accountsVector.end(); iter++)
    {
        if ((*iter)->getAccountBalance() < accountsVector[smallest]->getAccountBalance())
        {
			smallest = iter - accountsVector.begin();
		}
	}
	return smallest;
}
bool removeDuplicate(shared_ptr<BankAccount> account1, shared_ptr<BankAccount> account2)
{
  // write this method
    if (account1->equals(account2))
    {
		return true;
	}
    else
    {
		return false;
	}
}
void printArray(vector<shared_ptr<BankAccount>>  &accountsVector){
   cout<<"FAVORITE BANK - CUSTOMER DETAILS "<<endl;
   cout<<"--------------------------------"<<endl;
   auto iter = accountsVector.begin();
   for (iter = accountsVector.begin();iter<accountsVector.end();iter++)
   
       cout<<(*iter)->toString()<<endl;
//use iterator
}   
void insertAccounts(vector<shared_ptr<BankAccount>>  & accountsVector){
  //****write this method
    // Create three new accounts
    // Insert three new accounts at position 3, 5 and 7 of the vector.
	shared_ptr<BankAccount> temp1 = make_shared<BankAccount>("Amy Machado", 387623, 1244, 1023.67);
	shared_ptr<BankAccount> temp2 = make_shared<BankAccount>("Tak Phen", 981243, 1262, 6423.03);
	shared_ptr<BankAccount> temp3 = make_shared<BankAccount>("Celia Beatle", 465281, 1276, 3.56);
    // Insert the new accounts
    // 2, 4, 6 are the positions in the vector where the new accounts will be inserted
    // The new accounts are inserted in the order of temp1, temp2, temp3
    accountsVector.insert(accountsVector.begin() + 2, temp1);
	accountsVector.insert(accountsVector.begin() + 4, temp2);
	accountsVector.insert(accountsVector.begin() + 6, temp3);
  
}