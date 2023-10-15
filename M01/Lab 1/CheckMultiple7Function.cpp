#include "CheckMultiple7Header.h"

// this function inputs an integer from the console and returns this number to the main program
// no input validation required
int inputNumber() {
	int number; //declare an integer variable
	cout << "Please enter an integer: "; // prompt user for integer input
	cin >> number; // read the input into the integer variable
	return number; // return the value
}
bool checkMultiple7(int number) {
	// check if number is a multiple of 7 by using formula (number %7 == 0)
	if (number % 7 == 0) {
		return true;
	}
	else {
		return false;
	}
}
void displayResults(string message, int number) {
	//output the messsage
	cout << number << " " << message << endl;
}
void runNumberCheck() {
	// call input Number function
	int number = inputNumber();
	//call check Multiple 7 function
	bool check = checkMultiple7(number);
	//call display message function
	if (check == true) {
		displayResults("is a multiple of 7", number);
	}
	else {
		displayResults("is not a multiple of 7", number);
	}
}
