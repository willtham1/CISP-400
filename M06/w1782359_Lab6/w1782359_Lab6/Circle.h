#include<string>
#include <vector>
#include <memory>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using std::cout;
using std::string;
using std::vector;
using std::ifstream;
using std::to_string;
using std::istringstream;
using std::shared_ptr;
using std::make_shared;
using std::endl;
#ifndef CIRCLE_H// this is optional
#define CIRCLE_H // works with or without it
class Circle{  
//private
   static int count;
   int radius;
   int x,y;
public:
Circle();
Circle(int xcoord,int ycoord, int r);
int getY();
int getX();
int getRadius();
static int getCount();
double getArea();
double getCircumference();
double getDistance(Circle other);
bool intersects(Circle other);
Circle resize(int scale);//to copy self to other;
void resize(double scale);//for self

void setX(int xcoord);
void setY(int xcoord);
void setRadius(int r);
bool greaterThan(shared_ptr<Circle> other);
string toString();
~Circle();
//regular functions
//void inputData(vector<Circle>);
};

#endif
