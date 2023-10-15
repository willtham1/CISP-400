#include "Circle.h"
#include <fstream>
#include <sstream>

class Painting{
   vector<shared_ptr<Circle>> paintingVector;
   
 public:
   Painting();
   //regular constructor
   Painting(string filename);
   //ifstream inputFile(filename);
  
public:
//try to remove const and see what happens
shared_ptr<Circle> getCircle(int index) const;
//try to remove const and see what happens
int getSize()const;

//copy constructor for the Painting class
 Painting(const Painting &other);
  
//-----------------------> } extra } here
//return a string of the painting
string toString();

void setRadius(int index,int radius );
//destructor
~Painting();

};