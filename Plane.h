//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_PLANE_H
#define PROJETO_PLANE_H

#include <string>
#include <iostream>

#include "utility.h"
#include "Flight.h"

class Plane {

private:
    /** TO IMPLEMENT LIST OF FLIGHTS */
    /*std::vector<Flight> flightList;*/

    /** TO IMPLEMENT LIST OF CLEANING AND MAINTENANCE SCHEDULE */
    /* queue<Services> servicesQueue; */ //

    std::string numberPlate, type;
    int capacity, planeID;

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

};

#endif //PROJETO_PLANE_H
