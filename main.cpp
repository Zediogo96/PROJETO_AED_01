#include <iostream>

#include "Utility/Time.h"
#include "Transports/Transport.h"
#include "Airline/Airline.h"
#include "Menus/Menu.h"

using namespace std;

void testAddPlane() {
    Airline airline("TAP", 100);
    airline.addPlane();
    airline.printPlanes();
    airline.sortPlanes();
    airline.printPlanes();
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
void testDate_now() {
    Date date;
    date.now();
    std::cout << date.getYear() << " " << date.getMonth() << " " << date.getDay();
}

void init() {
    Airline airline("Tap", 50);
    airline.loadAirports();
    airline.LoadPlanes();
    airline.LoadFlights();
    airline.LoadServices();
    airline.LoadPassengers();
    main_menu(airline);
}

int main() {
    init();
    return 0;
}