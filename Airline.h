//
// Created by zedio on 21/11/2021.
//

#ifndef PROJETO_AIRLINE_H
#define PROJETO_AIRLINE_H


#include <string>
#include <vector>
#include <list>

#include "Plane.h"

class Airline {

private:
    std::vector<Plane> planesList;

    /*vector<Passenger*> passengers;
    vector<Employee*> employees; */

    std::string name;
    int maxNumOfFlights;

public:

    /** @brief Constructor for the Airline Class */
    Airline(const std::string &name, int maxNumOfFlights) {
        this->name = name;
        this->maxNumOfFlights = maxNumOfFlights;
        planesList.clear();
    }

    /** @brief GETTERS for fields of Airline Class */
    const std::string& getName();
    int getMaxNumOfFlights() const;
    std::vector<Plane> getPlanes();

    /******************************************** HANDLE PLANES **************************** */

    void SavePlanes();
    void LoadPlanes();

    bool availablePlane(int planeID);
    int findPlane();
    void addPlane();
    void deletePlane();
    void searchPlane();
    void printPlanes();
    void clearPlanes();

    void sortPlanes();


    /******************************************** HANDLE FLIGHTS **************************** */



};





#endif //PROJETO_AIRLINE_H
