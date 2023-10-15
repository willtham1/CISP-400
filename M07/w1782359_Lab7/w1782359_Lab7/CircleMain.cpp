#include<iostream>
#include "Circle.h"
#include <fstream>
#include <vector>
#include <memory>
#include<cstdlib>
#include <fstream>
#include <sstream>
#include "Painting.h"
using namespace std;


int main(){
   shared_ptr<Circle> circleOnePtr = make_shared<Circle>(0,0,15);
   shared_ptr<Circle> circleTwoPtr = make_shared<Circle>(0,0,7);
   
   // < is the overloaded less than operator
    if (!(*circleOnePtr < circleTwoPtr))
      cout<<" Circle One is bigger "<<endl;
   else 
      cout<<" Circle Two is bigger "<<endl;

      

    Painting p("dataLab7.txt");
    cout<<"Printing Painting p"<<endl;
    cout<<p.toString()<<endl;
    Painting q=p;
    cout<<"Printing Painting q"<<endl;
    cout<<q.toString()<<endl;
    cout<<"Changing Painting q"<<endl;
    q.setRadius(0,99);
    cout<<"Printing Painting p"<<endl;
    cout<<p.toString()<<endl;
    cout<<"Printing Painting q"<<endl;
    cout<<q.toString()<<endl;
    
   return 0;
   
}