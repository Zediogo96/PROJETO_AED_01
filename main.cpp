#include <iostream>

#include "Utility/Time.h"
#include "Utility/utility.h"

#include "Airline.h"
#include "Menus/Menu.h"

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
    Airline airline("Tap", 100);
    main_menu(airline);

    return 0;
}

