//#include<string>
//#include <cstdlib>// no need for this as is in header
#include "Circle.h"
#include <cmath>
#include <iostream>

Circle::Circle(){
  //if you have regular constructor you must
  //define default constructor
  //C++ will not auto create for you
  x=0;
  y=0;
  radius=1;
  count++;
}
Circle::Circle(int xcoord,int ycoord, int r){
      x=xcoord;
      y=ycoord;
      radius=r;  
      count++;
   }
int Circle::getX(){
      return x;
   }
   int Circle::getY(){
      return y;
   }
   
   int Circle::getRadius(){
      return radius;
   }
   int Circle::getCount(){
     return count;
   }
  void Circle::setX(int xcoord){
       x=xcoord;
  }
  void Circle::setY(int xcoord){
       x=xcoord;
  }
  void Circle::setRadius(int r){
       radius=r;
  }
  double Circle::getArea(){
    return M_PI*pow(radius,2);
  }
  double Circle::getCircumference(){
    return M_PI*radius/2;
  }
  double Circle::getDistance(Circle other){
       return sqrt(pow(x-other.getX(),2)+pow((y-other.getY()),2));
  }
  bool Circle::intersects(Circle other){
    return (this->getDistance(other)<=radius);
  }
  void Circle::resize(double scale){
    radius = scale*radius;
  }
  Circle Circle::resize(int scale){
    Circle c(x,y,radius*scale);
    return c;
  }
  string Circle::toString() {
    return "(" +to_string(x)+","+to_string(y)+"):"+to_string(radius);
  }
  bool Circle::greaterThan(Circle * other){
    return radius>other->getRadius();
  }

    // Destructor
Circle::~Circle(){
    //cout << "Inside Destructor" << endl;
}

// Read data from a file into a vector of circles
void Circle::inputData(vector<Circle>& circleVector, string filename)
{
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("File Open Error");
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream instream(line);
            int x, y, radius;
            instream >> x >> y >> radius;
            Circle circle(x, y, radius);
            circleVector.push_back(circle);
        }

        file.close();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

int Circle::count=0; // initialize global variable count