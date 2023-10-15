#include<string>
using namespace std;
#ifndef CIRCLE_H// this is optional
#define CIRCLE_H // works with or without it
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <fstream>
#include <sstream>

// Circle class declaration
class Circle{  
//private
   static int count; // static variable that keeps global count
//across all Circle objects
   int radius;
   int x,y;
public:
Circle();
Circle(int xcoord,int ycoord, int r);

// Return the circle as a string
string toString();

// Getters
int getY();
int getX();
int getRadius();
static int getCount();// get count method to report the current count

// Setters
void setX(int xcoord);
void setY(int xcoord);
void setRadius(int r);

// Return the area of the circle
double getArea();

// Return the circumference of the circle
double getCircumference();

// Return the distance between the center of this circle and the center of the other circle
double getDistance(Circle other);

// Return true if this circle intersects with the other circle
bool intersects(Circle other);

// Return true if this circle is greater than the other circle
void resize(double scale);//for self

// Return a new circle that is a scaled copy of this circle
Circle resize(int scale);//to copy self to other;


bool greaterThan(Circle * other);

// Destructor
~Circle();

// Read data from a file into a vector of circles
static void inputData(vector<Circle> &circleVector, string filename);


};

#endif
