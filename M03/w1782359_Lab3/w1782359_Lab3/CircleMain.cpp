#include<iostream>
#include<iomanip>
#include "CircleHeader.h"

int main(){
   Circle circleOne;
   //std::cout << "Created circleOne" << circleOne.toString() << std::endl;
   Circle circleTwo(0,0,4);
   //Circle circleThree(-2,-9,6);
   //std::cout<<"Created circleTwo" << circleTwo.toString() << std::endl;
   //std::cout<<"Created circleThree" << circleThree.toString()<<std::endl;
   // use the above starter to complete the rest of the lab to print the circle, circumference and area

   // Lab 2 code
   // Print the area and circumference of each circle rounded to 2 decimal places
   //std::cout<<std::fixed<<std::setprecision(2)<<"The area of circleOne is "<<std::round(circleOne.getArea()*100)/100<<" Its circumference is "<<std::round(circleOne.getCircumference()*100)/100<<std::endl;
   //std::cout<<std::fixed<<std::setprecision(2)<<"The area of circleTwo is "<<std::round(circleTwo.getArea()*100)/100<<" Its circumference is "<<std::round(circleTwo.getCircumference()*100)/100<<std::endl;
   //std::cout<<std::fixed<<std::setprecision(2)<<"The area of circleThree is "<<std::round(circleThree.getArea()*100)/100<<" Its circumference is "<<std::round(circleThree.getCircumference()*100)/100<<std::endl;
   // End of Lab 2 code

   // Lab 3 code
   std::cout << "First Circle: " << circleOne.toString() << std::endl;
   std::cout << "Second Circle: " << circleTwo.toString() << std::endl;
   std::cout << "The distance between the two circles is: " << circleOne.getDistance(circleTwo) << std::endl;

   // Check if circle one intersects with circle two
   if (circleOne.intersects(circleTwo))
   {
	  std::cout << "The circles do intersect" << std::endl;
   }
   else
   {
	  std::cout << "The circles do not intersect" << std::endl;
   }

   // Create circleThree using the resize method on circleTwo
   Circle circleThree = circleTwo.resize(10);

   // Display circleThree
   std::cout << "Third Circle created: " << circleThree.toString() << std::endl;

   // Move circleThree to (4,5)
   circleThree.moveTo(4, 5);

   // Display moved circleThree
   std::cout << "Moved Circle Three: " << circleThree.toString() << std::endl;
   
   // Check if circle two intersects with circle three
   if (circleTwo.intersects(circleThree))
   {
	   std::cout << "The circles Second and Three do intersect" << std::endl;
   }
   else {
	   std::cout << "The circles Second and Three do not intersect" << std::endl;
   }

   // Create a fourth circle
   Circle circleFour(4, 5, 1);
   std::cout << "Fourth Circle created: " << circleFour.toString() << std::endl;

   // Check if circle four intersects with circle one
   if (circleFour.intersects(circleOne))
   {
	   std::cout << "The circles Four and One do intersect" << std::endl;
   }
   else {
	   std::cout << "The circles Four and One do not intersect" << std::endl;
   }

   // Resize circle three
   circleThree.resize(9.5);
   std::cout << "Resized Circle Three: " << circleThree.toString() << std::endl;

   return 0;
}