#include <iostream>

#include "Time.h"
#include "LinkedList.h"
#include "utility.h"

#include "Airline.h"
int main() {


    // CONSTRUCTION OF SINGLETON
    Airline& airline = Airline::getInstance("TAP", 100);


    airline.addPlane();
    /*airline.addPlane();*/


    /*airline.printPlanes();*/


    /*airline.deletePlane();*/

    /*airline.printPlanes();*/

    airline.LoadPlanes();

    airline.printPlanes();

    return 0;
}
