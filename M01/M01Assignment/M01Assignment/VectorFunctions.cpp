#include "VectorHeader.h"

void initializeVector(std::vector<int> &numbers){ // populate the vector with VECTOR_SIZE number of random integers of value between 1 and 100
 // pass by ref ensures vector is returned with values to calling program
srand(time(0)); // seed the random number
// put this in a loop to populate the vector with VECTOR_SIZE (ie 10) number of values
for (int i=0;i<VECTOR_SIZE;i++){ 
 int randomNumber = rand()%MAX_VALUE +1;//returns random numbers between 1 and 100;
 numbers.push_back(randomNumber);
}
}

void sortVector(std::vector<int> &numbers){    // use sort on this vector database from the begining to the end. Use iterators
	std::sort(numbers.begin(), numbers.end());
}

void reverseVector(std::vector<int> &numbers){   //  reverse this vector database
	std::reverse(numbers.begin(), numbers.end());
}

void displayVector(std::vector<int>numbers){     // display the vector contents by iterating through the vector
for (auto iter = numbers.begin();iter<numbers.end();iter++)
std::cout<<*iter<<" ";
std::cout<<std::endl; // new line to make things easier to read
}

void removeLowest(std::vector<int> &numbers){    // remove the number with the least value
	if (!numbers.empty()) {
		auto iter = std::min_element(numbers.begin(), numbers.end());
		numbers.erase(iter);
	}
}

void displayResults(double value){       // display the calculated average of the values
	std::cout<<"The average is "<<std::fixed<<std::setprecision(2)<<value<<std::endl;
}

double calculateAverage(std::vector<int>numbers){ // calculate the average of the vector contents
	double sum=0;
	for (int num : numbers) {
		sum += num;
	}
	if (!numbers.empty()) {
		return sum / numbers.size();
	}
	//return the value
	return 0;
}
