//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_PLANE_H
#define PROJETO_PLANE_H

#include <string>
#include <iostream>
#include <list>
#include <fstream>

#include "Utility/utility.h"
#include "Flight.h"
#include "Services/Service.h"

class Plane {

private:

    /** TO IMPLEMENT LIST OF FLIGHTS */
    std::list<Flight> flightsList;

    /** TO IMPLEMENT LIST OF CLEANING AND MAINTENANCE SCHEDULE */
    queue<Service> servicesQueue;

    std::string numberPlate, type;
    int capacity, planeID{};

public:

    Plane();
    Plane(std::string numberPlate, std::string type, int capacity, int planeID);

    void setNumberPlate(std::string numberPlate_);
    void setType(std::string type_);
    void setCapacity(int capacity_);
    void setPlaneID(int pID);

    std::string getNumberPlate() const;
    std::string getType() const;
    int getCapacity() const;
    int getPlaneID() const;
    std::list<Flight> getFlightsList();

    /* ******************************************** HANDLE FLIGHTS ********************************* */

    void addFlight();
    void deleteFlight();
    void SaveFlights();
    void LoadFlights();

    void printFlights();


};

#endif //PROJETO_PLANE_H
