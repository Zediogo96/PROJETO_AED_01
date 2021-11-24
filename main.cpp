#include <iostream>

#include "Time.h"
#include "LinkedList.h"
#include "utility.h"

#include "Airline.h"
int main() {

    Airline& airline = Airline::getInstance("TAP", 100);

    airline.addPlane();
    airline.addPlane();


    airline.printPlanes();

    return 0;
}
