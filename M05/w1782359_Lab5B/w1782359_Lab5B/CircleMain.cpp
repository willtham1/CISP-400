#include<iostream>
#include "Circle.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

// Function to check if circleTwo is bigger than circleOne
void checkCircleSize(Circle* c1, Circle* c2) {
    if (c2->greaterThan(c1)) {
        cout << "circleTwo is bigger." << endl;
    }
    else {
        cout << "circleOne is bigger." << endl;
    }
}

// Function to swap two circle pointers
void swapCirclePointers(Circle*& c1, Circle*& c2) {
    Circle* temp = c1;
    c1 = c2;
    c2 = temp;
}

// Function to read data from a file into an array of pointers to circles
void inputData(vector<Circle*>& circlePointerArray, string filename) {
    ifstream inputFile(filename);
    istringstream instream;
    string data;
    int x, y, radius;
    try {
        if (inputFile) {
            while (getline(inputFile, data)) {
                instream.clear();
                instream.str(data);
                instream >> x >> y >> radius;
                Circle* circle = new Circle(x, y, radius);
                circlePointerArray.push_back(circle);
            }
        }
        else {
            throw string("File Open Error");
        }
    }
    catch (string message) {
        cout << message << endl;
        exit(0);
    }

    // Display the number of circles in the array
    cout << "The total number of circles is: " << circlePointerArray.size() << endl;

    // Display all the circles in the array of pointers using toString method
    cout << "They are:" << endl;
    for (Circle* circle : circlePointerArray) {
        cout << circle->toString() << endl;
    }

    // Calculate and display the sum of the areas of all the circles in the array
    double totalArea = 0.0;
    for (Circle* circle : circlePointerArray) {
        totalArea += circle->getArea();
    }
    cout << "The total sum of the areas is: " << totalArea << endl;

    // Swap the position of the second and fourth circles
    swapCirclePointers(circlePointerArray[1], circlePointerArray[3]);

    // Display the changed sequence of circles using toString method
    cout << "The modified array is:" << endl;
    for (Circle* circle : circlePointerArray) {
        cout << circle->toString() << endl;
    }
}

int main() {
    // Create a circle object circleOne at (0,0) with a radius of 5.
    Circle circleOne(0, 0, 5);

    // Create a pointer c1Ptr to circleOne
    Circle* c1Ptr = &circleOne;

    // Create a circle object circleTwo at (-2,-2) with a radius of 10.
    Circle circleTwo(-2, -2, 10);

    // Create a pointer c2Ptr to circleTwo
    Circle* c2Ptr = &circleTwo;

    // Use greaterThan to check if circleTwo is bigger than circleOne and display results
    checkCircleSize(c1Ptr, c2Ptr);

    // Declare an array of pointers to circles - circlePointerArray
    vector<Circle*> circlePointerArray;

    // Call the inputData function to read data from a file into the array
    inputData(circlePointerArray, "dataLab5B.txt");

    // Cleanup: Delete dynamically allocated circle objects
    for (Circle* circle : circlePointerArray) {
        delete circle;
    }

    return 0;
}
