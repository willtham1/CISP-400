#include <math.h>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

class Circle{  
private:
   
   int x,y;
   int radius;

   // all the method headers for the class
public:
   Circle();
  // Circle(int xcoord,int ycoord, int r):x(xcoord),y(ycoord),radius(r){};
  // The commented constructor above  is another way of doing inline assignments
  // You do not need to use it.Its just for your information

   Circle(int xcoord,int ycoord, int r);
   int getX();
   
   
   int getY();
   
   int getRadius();
   double getArea();
   double getCircumference();
   // Added toString method for lab 2 to print the circle
   std::string toString();

   // Lab 3 methods
   // Return the distance between this circle and another cirlce
   double getDistance(Circle other);

   // Move the center of the circle to a new coordinate
   void moveTo(int newX, int newY);

   // Return true if the distance between the centers of the two circles is less
   // than the sum of their radi
   bool intersects(Circle other);

   // Multiply the radius by the scale
   void resize(double scale);

   // Return a new circle with the same center as this circle, but radius
   // multiplied by scale
   Circle resize(int scale);
   // End of Lab 3 methods
};