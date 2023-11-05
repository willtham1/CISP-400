#include <iostream>
#include "Plane.h"
#include "Car.h"
#include <memory>
#include<vector>
#include<typeinfo>

using namespace std;

int main() {
//create a shared pointer called car to a Car object and 
//construct the Car object using its custom constructor in dynamic memory
  std::shared_ptr<Car> car = std::make_shared<Car>(1992,20,"Car","Honda",40);
  std::cout<<"-----------------------------------"<<std::endl;
  std::cout<<"Making a Car "<< std::endl;
  std::cout<<"Model: "<<car->getModel()<<std::endl;
  std::cout<<"Year: "<<car->getYear()<<std::endl;
  std::cout<<"Speed: "<<car->getSpeed()<<std::endl;
  std::cout<<"WheelSize: "<<car->getWheelSize()<<std::endl;

//create a shared pointer called plane to a Plane object and 
//construct the Plane object using its custom constructor in dynamic memory

  std::shared_ptr<Plane> plane= make_shared<Plane>(2020,200,"Plane","Boeing",3000);
 
  std::cout<<"-----------------------------------"<<std::endl;
  std::cout<<"Making a Plane "<< std::endl;
  std::cout<<"Model: "<<plane->getModel()<<std::endl;
  std::cout<<"Year: "<<plane->getYear()<<std::endl;
  std::cout<<"Speed: "<<plane->getSpeed()<<std::endl;
  std::cout<<"Altitude: "<<plane->getAltitude()<<std::endl;
  std::cout<<"-----------------------------------"<<std::endl;

// call the getWheelSize() and toString() functions on the car  
 cout<<"I am a car and my wheelSize is "<<car->getWheelSize()<<endl;
  cout<<"Using the toString function: "<<car->toString();
  cout<<endl<<endl;;
  
// call the getAltitude() and toString() functions on the plane  
  cout<<"I am a plane and my altitude is "<<plane->getAltitude()<<endl;
   cout<<"Using the toString function: "<<plane->toString()<<endl<<endl;
   cout<<"-----------------------------------"<<endl;
//Observe the situations when overriding takes place and when it 
//does not in the following function calls
  cout<<"Creating a plane of Declared Type Plane and actual type Plane"<<endl;
  cout<<"Serve Drinks Function Overriden by Plane Class"<<endl;
  shared_ptr<Plane> plane2= make_shared<Plane>(2000,100,"Plane","Lockheed",5000);
  
  cout<<"Plane says :"<<plane2->serveDrinks()<<endl;
  

   cout<<"-----------------------------------"<<endl;
   cout<<"Creating a plane of Declared Type Vehicle and actual type Plane"<<endl;
   shared_ptr<Vehicle> plane3= make_shared<Plane>(1000,100,"Plane","Hughes",2000);
   cout<<"Serve Drinks Function Not Overriden by Plane Class, Vehicle Class prevails "<<endl;
   cout<<"Vehicle Says: "<<plane3->serveDrinks()<<endl;
  }
  
