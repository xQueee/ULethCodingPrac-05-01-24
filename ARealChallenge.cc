// This program takes in the area in square meters of Old MacDonald's pasture, and outputs the total length of the fence needed for the pasture in meters.
#include <iostream>
#include <cmath>

using namespace std;

// Function protoype
double perimeter(double);

int main(){
    double area = 0;
    cin >> area;

    cout.precision(21);
    cout << perimeter(area) << endl;

    return 0;
}

// Function Definition
double perimeter(double area){
    double side = sqrt(area);
    double perimeter = 4 * side;
    return perimeter;
}