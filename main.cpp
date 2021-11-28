#include <iostream>

#include "Time.h"
#include "utility.h"

#include "Airline.h"
int main() {


    // CONSTRUCTION OF SINGLETON
    Airline& airline = Airline::getInstance("TAP", 100);


    airline.addPlane();
    airline.addPlane();

    airline.printPlanes();

    airline.sortPlanes();

    airline.printPlanes();

    /*Date date;
    InputDate(date, "Please enter the input for date: ");*/


    return 0;
}
