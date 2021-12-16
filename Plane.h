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
#include "Baggage/Baggage.h"

class Plane {

private:

    string numberPlate, type;
    int capacity, planeID{};
    std::vector<Baggage> baggages;

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

    void fill(Baggage baggage);
};

#endif //PROJETO_PLANE_H
