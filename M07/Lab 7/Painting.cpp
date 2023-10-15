#include "Circle.h"
#include <fstream>
#include <sstream>
#include "Painting.h"

   Painting::Painting(){
    
   }
 
   //regular constructor
   Painting::Painting(string filename){
     ifstream inputFile(filename);
  istringstream instream;
  string data;
  int count =0;
  int x,y,radius;
  try{
  if (inputFile){
    while (!inputFile.eof()){
      getline(inputFile,data);
       istringstream instream(data);
       instream>>x;
       instream>>y;
       instream>>radius;
       shared_ptr<Circle> circle = make_shared<Circle>(x,y,radius);
       paintingVector.push_back(circle); 
       count++;    
  
    }
    
   }
    else throw string("File Not Found");
  }
  catch (string message){
    cout<<message<<endl;
    exit(0);
  }
}
 

//returns a circle at the given index in the painting vector
shared_ptr<Circle> Painting::getCircle(int index) const{
  return paintingVector[index];
}
//gets the size of the painting vector
int Painting::getSize()const{
  return paintingVector.size();
}
//copy constructor for the Painting Class
 Painting::Painting(const Painting &other) {

   // copy individual circles from other to this painting
   // note that deep copy for these circles will need to be done since
   // the painting vector contains pointers to circles

   //this code will involves a for loop to traverse "other"
   // make temporary pointer to circle which contains a copy of the current "other" circle
   //push this pointer onto the "this" painting vector

     for (const auto& circle : other.paintingVector) {
         shared_ptr<Circle> newCircle = make_shared<Circle>(*circle);  // Deep copy of the circle
         paintingVector.push_back(newCircle);
     }
  }
 

  
//returns a string containing the painting vector
string Painting::toString(){
  //concatenate the strings of individual circle objects of the painting Vector
    string result = "[ ";
    for (const auto& circle : paintingVector) {
        result += circle->toString() + " ";
    }
    result += "]";
    return result;
}


void Painting::setRadius(int index,int radius ){
  paintingVector[index]->setRadius(radius);
}
Painting::~Painting(){
    //delete paintingVector;
}
