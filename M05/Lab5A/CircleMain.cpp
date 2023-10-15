#include<iostream>
#include "Circle.h"
#include <fstream>
#include <vector>
#include<cstdlib>
#include <fstream>
#include <sstream>

//note that vectors have to be passed by reference
//opens the file using try catch
//if open fails, throw an exception and exit the program
//other wise populate read the data line by line from the data file
//create a new Circle with this data
//push this circle back onto the vector
void inputData(vector<Circle> &circleVector, string filename){
  ifstream inputFile(filename);
  istringstream instream;
  string data;
  int x,y,radius;
  try{
  if (inputFile){
    while (!inputFile.eof()){
      getline(inputFile,data);
       istringstream instream(data);
       instream>>x;
       instream>>y;
       instream>>radius;
       Circle circle(x,y,radius);
       circleVector.push_back(circle);    
  
    }

  }
  else throw string("File Not Found");
  }
  catch (string message){
    cout<<message<<endl;
    exit(0);
  }

}

int main(){
   //create a vector of circles
   vector<Circle> circleVector;

  //open the data file and populate the vector
   inputData(circleVector, "dataLab5B.txt");

  //create an iterator to traverse the vector and print each Circle inside it
  
   vector<Circle>::iterator iter;
   cout<<"The circles created are :"<<endl;
   
   for ( iter =circleVector.begin();iter!=circleVector.end();iter++) {

    cout<<iter->toString()<<endl;
    //cout<<circleVector[i].toString();
   }

  // print the number of circles ever created using getCount on any element of the vector
    cout << "The number of circles ever created is " << circleVector[0].getCount() << endl;
  // print the number of circles currently in the vector
    cout << "The number of circles currently in the vector is " << circleVector.size() << endl;

    // open the data file and populate the vector from the file
    //inputData(circleVector, "dataLab5B.txt");

    // Erase any elements with a radius greater than 8
    circleVector.erase(
        std::remove_if(circleVector.begin(), circleVector.end(),
            [](Circle& circle) { return circle.getRadius() > 8; }),
        circleVector.end()
    );


    // Display the numbers of circles remaining using the vector size method
    cout << "The number of circles currently in the vector is " << circleVector.size() << endl;

    // Display remaining circles
    cout<<"The circles remaining are :"<<endl;
    for (iter = circleVector.begin();iter != circleVector.end();iter++) {
		cout << iter->toString() << endl;
	}

    // Create two new circles objects
    cout<<"Creating two new circles"<<endl;
    Circle circle1(3, 4, 7);
    Circle circle2(-2, -4, 4);

    // Insert the circles at position 2 and 3
    cout<<"Inserting the two new circles at position 2 and 3"<<endl;
    circleVector.insert(circleVector.begin() + 2, circle1);
    circleVector.insert(circleVector.begin() + 3, circle2);

    // Display the vector if circles
    cout<<"The circles in the vector are :"<<endl;
    for (iter = circleVector.begin();iter != circleVector.end();iter++) {
        cout << iter->toString() << endl;
    }



//  // erase all circles in the vector
//   cout<<"Erasing the Vector of Circles"<<endl;
//   circleVector.erase(circleVector.begin(),circleVector.end());
//  //create another new circle using default constructor
//   cout<<"Creating a new Circle"<<endl;
//   Circle circle;
////push this new circle onto the vector
//circleVector.push_back(circle);
//  //print the number of circles using get count 
//  cout << "The number of circles ever created is " << circleVector[0].getCount() << endl;
//  //print the number of circles using vector size
//  cout << "The number of circles currently in the vector is " << circleVector.size() << endl;
   return 0;
}