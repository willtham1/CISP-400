#include <math.h>
#include "CircleHeader.h"


// default constructor
   Circle::Circle(){
      x=y=0;
      radius=1;  //creates unit circle with center at origin
   }

  // regular constructor
  
 Circle:: Circle(int xcoord,int ycoord, int r):x(xcoord),y(ycoord),radius(r){
      x=xcoord;
      y=ycoord;
      radius=r;  
      
   }
  
   int Circle::getX(){
      return x;
   }
   int Circle::getY(){
      return y;
   }
   int Circle::getRadius(){
       //return radius
       return radius;
   }
   double Circle::getArea(){
      return M_PI*radius*radius;
   }
   double Circle::getCircumference(){
      // return 2* M_PI times radius
       return 2 * M_PI * radius;
   }
   std::string Circle::toString() {
       //return "(" + to_string(x)+ "," + ....please complete
       return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(radius) + ")";
   }

   // Lab 3 methods
   // Return the distance between this circle and another cirlce
   double Circle::getDistance(Circle other)
   {
       // Distance is sqrt((x2 - x1)^2 + (y2 - y1)^2)
       return sqrt(pow(other.getX() - x, 2) + pow(other.getY() - y, 2));
   }

   // Move the center of the circle to a new coordinate
   void Circle::moveTo(int newX, int newY)
   {
       x = newX;
       y = newY;
   }

   // Returns true if the distance between the centers of the two circles is less than the sum of their radii
   bool Circle::intersects(Circle other)
   {
       if (getDistance(other) < radius + other.getRadius())
       {
		   return true;
	   }
       else
       {
		   return false;
	   }
   }

   // Multiply the radius by the scale
   void Circle::resize(double scale)
   {
       radius = radius * scale;
   }

   // Return a new circle with the same center as this circle, but radius multiplied by scale
   Circle Circle::resize(int scale)
   {
       Circle newCircle(x, y, radius * scale);
	   return newCircle;
   }



