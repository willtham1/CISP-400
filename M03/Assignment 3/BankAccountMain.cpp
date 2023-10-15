#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BankAccount.h"

void fillVector(std::ifstream& input, std::vector<BankAccount>& accountsVector);
int largest(const std::vector<BankAccount>& accountsVector);
int smallest(const std::vector<BankAccount>& accountsVector);
void printVector(const std::vector<BankAccount>& accountsVector);
void checkDuplicates(std::vector<BankAccount>& accountsVector);

int main() {
    std::vector<BankAccount> accountsVector;
    std::ifstream input("BankData.txt");

    if (!input) {
        std::cout << "File Open Error";
    }
    else {
        fillVector(input, accountsVector);
        printVector(accountsVector);

        std::cout << "Largest Balance:" << std::endl;
        std::cout << accountsVector[largest(accountsVector)].toString() << std::endl;

        std::cout << "Smallest Balance:" << std::endl;
        std::cout << accountsVector[smallest(accountsVector)].toString() << std::endl;

        std::cout << "Using static count variable there are " << BankAccount::getCount() << " accounts." << std::endl;
        std::cout << "Using vector size method there are " << accountsVector.size() << " accounts." << std::endl;
        std::cout << std::endl;

        // Remove duplicates
        checkDuplicates(accountsVector);

        std::cout << "Using static count variable there are " << BankAccount::getCount() << " accounts." << std::endl;
        std::cout << "Using vector size method there are " << accountsVector.size() << " accounts." << std::endl;
        std::cout << std::endl;

        // Create the three new accounts
        BankAccount amyAccount("Amy Machado", 387623, 1244, 1023.67);
        BankAccount takAccount("Tak Phen", 981243, 1262, 6423.03);
        BankAccount celiaAccount("Celia Beatle", 465281, 1276, 3.56);

        // Insert the new accounts at positions 3, 5, and 7
        // 0 is the first position in the vector therefore 2, 4, and 6 are the correct positions to insert the new accounts
        // in order to insert the new accounts at positions 3, 5, and 7
        accountsVector.insert(accountsVector.begin() + 2, amyAccount);
        accountsVector.insert(accountsVector.begin() + 4, takAccount);
        accountsVector.insert(accountsVector.begin() + 6, celiaAccount);

        // Inserted Three New Accounts: Reprinting List
        std::cout << "Inserted Three New Accounts: Reprinting List" << std::endl << std::endl;
        printVector(accountsVector);

        std::cout << "Using static count variable there are " << BankAccount::getCount() << " accounts." << std::endl;
        std::cout << "Using vector size method there are " << accountsVector.size() << " accounts." << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

void fillVector(std::ifstream& input, std::vector<BankAccount>& accountsVector) {
    std::string firstName, lastName, accountName;
    int id, accountNumber;
    double accountBalance;

    while (input >> firstName >> lastName >> id >> accountNumber >> accountBalance) {
        accountName = firstName + " " + lastName;
        BankAccount temp(accountName, id, accountNumber, accountBalance);
        accountsVector.push_back(temp);
    }
}

int largest(const std::vector<BankAccount>& accountsVector) {
    double largest = 0;
    int index = -1;

    for (int i = 0; i < accountsVector.size(); i++) {
        if (accountsVector[i].getAccountBalance() > largest) {
            largest = accountsVector[i].getAccountBalance();
            index = i;
        }
    }

    return index;
}

int smallest(const std::vector<BankAccount>& accountsVector) {
    double smallest = std::numeric_limits<double>::max();
    int index = -1;

    for (int i = 0; i < accountsVector.size(); i++) {
        if (accountsVector[i].getAccountBalance() < smallest) {
            smallest = accountsVector[i].getAccountBalance();
            index = i;
        }
    }

    return index;
}

void printVector(const std::vector<BankAccount>& accountsVector) {
    std::cout << "FAVORITE BANK - CUSTOMER DETAILS" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    for (const BankAccount& account : accountsVector) {
        std::cout << account.toString() << std::endl;
    }
}


// Determine if there are duplicate accounts in the vector. If there are, then erase the account from the vector. 
// Note the difference in the method return value and the procedure to the equals method in Assignment 3. See how array deletion is different from vector deletion.
void checkDuplicates(std::vector<BankAccount>& accountsVector) {
    bool duplicate = false;

    for (int i = 0; i < accountsVector.size() - 1; i++) {
        for (int j = i + 1; j < accountsVector.size(); j++) {
            if (accountsVector[i].equals(accountsVector[j])) {
                duplicate = true;
                accountsVector.erase(accountsVector.begin() + j);
            }
        }
    }

    if (duplicate) {
        std::cout << "Duplicate Accounts Found: Reprinting List" << std::endl << std::endl;
        printVector(accountsVector);
    }
}