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
    Plane plane = Plane("123123", "A340", 200, 1);
    plane.addFlight();
    plane.addFlight();

    plane.deleteFlight();
    plane.printFlights();
}

void testSavePlanes() {
    Airline airline("TAP", 100);
    airline.addPlane();
    airline.addPlane();
    airline.SavePlanes();
}

void testLoadPlanes() {
    Airline airline("TAP", 100);
    airline.LoadPlanes();
    airline.printPlanes();
}

void testMenus() {
    Airline airline("Tap", 100);
    main_menu(airline);
}

int main() {
    testAddFlight();

    return 0;
}

