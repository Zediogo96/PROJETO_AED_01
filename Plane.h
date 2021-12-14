//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_PLANE_H
#define PROJETO_PLANE_H

#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <queue>

#include "Utility/utility.h"
#include "Flight.h"
#include "Services/Service.h"

class Plane {

private:

    /** TO IMPLEMENT ASSIGNMENT OF FLIGHTS */
    std::list<int> assignments;

    std::string numberPlate, type;
    int capacity, planeID{};

public:

    Plane();
    Plane(int planeID, std::string type, std::string numberPlate,  int capacity);

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
