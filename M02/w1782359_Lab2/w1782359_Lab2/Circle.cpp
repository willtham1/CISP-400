#include <cmath>

#include <string>
#include "CircleHeader.h"

#define _USE_MATH_DEFINES
#include <math.h>

using std::string;
using std::to_string;
using std::pow;

// Getter
int Circle::getX() { return x; }
int Circle::getY() { return y; }
int Circle::getRadius() { return radius; }

// Setter
void Circle::setX(int xcoord) { x = xcoord; }
void Circle::setY(int ycoord) { y = ycoord; }
void Circle::setRadius(int r) { radius = r; }

// Return the area of the circle using pi*r^2 rounded to 2 decimal places
double Circle::getArea() {
    return round(M_PI * pow(radius, 2) * 100) / 100.0;
}

// Return the circumference using 2*pi*r rounded to 2 decimal places
double Circle::getCircumference() {
    return round(2.0 * M_PI * radius * 100) / 100.0;
}

// Return the circle as a string in the form (x,y):radius
string Circle::toString() {
    return "(" + to_string(x) + "," + to_string(y) + "):" + to_string(radius) +
        '\n';
}
