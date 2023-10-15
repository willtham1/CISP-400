#include<iostream>
#include "Circle.h"
#include <fstream>
#include <vector>
#include <memory>
#include<cstdlib>
#include <fstream>
#include <sstream>


//const int SIZE = 10; we do not need this now. Its for arrays which have fixed size
//vectors can grow dynamically
// pay attention to this parameter list
int inputData(vector<shared_ptr<Circle>> &circlePointerVector, string filename)

{
  ifstream inputFile(filename);
  istringstream instream;
  string data; // line of data from the file
  int count =0;
  int x,y,radius;
  try{
  if (inputFile){ //try to open the file
  //while there is data 
  //in this lab since we are using vectors, we do not need
  //to worry about size
    while (!inputFile.eof()){
      getline(inputFile,data);
       istringstream instream(data);
       instream>>x;
       instream>>y;
       instream>>radius;
       //create a pointer to new Circle object and push it into
       //the vector
       //note that make_shared uses memory from the heap to
       //construct the Circle. The custom constructor of the Circle
       //class gets called here to initialize x,y and radius
       shared_ptr<Circle> circle = make_shared<Circle>(x,y,radius);
       
       circlePointerVector.push_back(circle);
  
       count++;    
  
    }

  }
  else throw string("File Not Found");
  }
  catch (string message){
    cout<<message<<endl;
    exit(0);
  }
 return count;
}

int main() {
shared_ptr<Circle> circleOnePtr = make_shared<Circle>(0, 0, 5);

// create a new shared pointer to a Circle Object
shared_ptr<Circle> circleTwoPtr = make_shared<Circle>(0, 0, 7); // Create circleTwoPtr

if (circleOnePtr->greaterThan(circleTwoPtr))
    cout << "Circle One is bigger " << endl;
else
    cout << "Circle Two is bigger " << endl;

// declare a vector of shared pointers to Circle objects
std::vector<shared_ptr<Circle>> circlePointerVector;

// populate the vector by reading the data from the file and
// creating shared pointers to circles.
int count = inputData(circlePointerVector, "dataLab6.txt");

cout << "The total number of circles is " << count << endl;

cout << "They are :" << endl;

// you can use an iterator here instead of indexing.
// Go ahead and try it
for (int i = 0; i < count; i++)
    cout << circlePointerVector[i]->toString() << endl;

// accumulator to store the sum of the areas of all the circles
// in the vector
double sumOfAreas = 0;
for (int i = 0; i < count; i++)
    sumOfAreas += circlePointerVector[i]->getArea();

cout << "The total sum of the areas is " << sumOfAreas << endl;

// swap the vectors in position 2 and 4 i.e., index 1 and 3
// create a temporary circle pointer 
// and copy the address of the first circle into it
shared_ptr<Circle> tmpPtr = circlePointerVector[1];
circlePointerVector[1] = circlePointerVector[3];
circlePointerVector[3] = tmpPtr; // Complete the swap

cout << "The modified vector is " << endl;
for (int i = 0; i < count; i++)
    cout << circlePointerVector[i]->toString() << endl;

return 0;
}