//BankMain.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cstdlib>
#include "BankHeader.h" 

//print the ATM menu
char printMenu(Bank myBank){
   char menuOp;
   string toFind;
   int number;
   
   std::cout <<endl<< "MENU" << endl;
   std::cout << "v - View Account Balance" << endl;
   std::cout << "w - Withdraw from Account" << endl;
   std::cout << "d - Deposit into Account" << endl;
   std::cout << "a - Add an Account" << endl;
   std::cout << "r - Remove an Account" << endl;
   
   std::cout << "q - Quit" << endl << endl;
   
   menuOp = ' ';
   
   while (menuOp != 'd' && menuOp != 'a' && menuOp != 'v' &&
         menuOp != 'r' && menuOp != 'w' 
          && menuOp != 'q') {
      std::cout << "Choose an option: ";
      string s;
      getline(cin,s,'\n');
      cin.clear();
      menuOp=s[0];
      menuOp= tolower(menuOp);
   }
   
  //remove and delete account - admin
   
   if (menuOp == 'r') {
      std::cout<<"Remove Account: Coming Soon" <<endl;
        
      menuOp = ' ';
       cin.clear();
   }
   //deposit amount
   else if (menuOp == 'd') {
      myBank.deposit();
      menuOp = ' ';
      cin.ignore(9999,'\n');
   }
   //view account balance
   else if (menuOp == 'v') {
      myBank.viewBalance(); //write this method in Bank.cpp
      menuOp = ' ';
       cin.ignore(9999,'\n');
   }
   // withdraw money provided min balance is maintained
   else if (menuOp == 'w') { //
      //withdraw if funds are sufficient
      myBank.withdraw();      //write this method in Bank.cpp
      menuOp = ' ';
      cin.ignore(9999,'\n');
      
      
   }
   
   else if (menuOp == ' ') {  
      menuOp = ' ';
       cin.ignore(9999,'\n');
   }
 // add an account - admin  
   else if (menuOp == 'a') {
      std::cout<<"Add Account: Coming Soon"<<endl;
      menuOp = ' ';
       cin.clear();
   }
  //quit the ATM application
   else if (menuOp =='q'){
     std::cout<< "Good Bye!"<<endl;
   }
   return menuOp;
}

//run the bank application
int main() {
//populate the bank with accounts
  Bank myBank("BankData.txt");  
    char option  = printMenu(myBank); 
// repeatedly offer ATM like options until customer quits
    while (option != 'q')  
       option = printMenu(myBank);
  }
  