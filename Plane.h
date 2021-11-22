//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_PLANE_H
#define PROJETO_PLANE_H

#include <string>


class Plane {

private:
    /** TO IMPLEMENT LIST OF FLIGHTS */
    /* vector<Flight> flightList; */

    /** TO IMPLEMENT LIST OF CLEANING AND MAINTENANCE SCHEDULE */
    /* queue<Services> servicesQueue; */ //

    std::string numberPlate, type;
    int capacity;

public:

    Plane();
    Plane(std::string numberPlate, std::string type, int capacity);

    void setNumberPlate(std::string numberPlate_);
    void setType(std::string type_);
    void setCapacity(int capacity_);

    std::string getNumberPlate() const;
    std::string getType() const;
    int getCapacity() const;

};

#endif //PROJETO_PLANE_H
