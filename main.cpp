#include <iostream>

#include "Utility/Time.h"
#include "Utility/utility.h"

#include "Airline.h"


void testAddPlane() {
    Airline airline("TAP", 100);
    airline.addPlane();
    airline.printPlanes();
    airline.sortPlanes();
    airline.printPlanes();
}

void testAddFlight() {

    Plane plane = Plane();
    plane.addFlight();
}

int main() {

    /*testAddPlane();*/
    testAddFlight();
    return 0;
}

