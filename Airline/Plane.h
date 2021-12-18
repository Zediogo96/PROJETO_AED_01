//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_PLANE_H
#define PROJETO_PLANE_H

#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <queue>

#include "../Utility/utility.h"
#include "Flight.h"
#include "../Services/Service.h"
#include "../Baggage/Baggage.h"
/**
 * @brief Class handling planes, storing specific information regarding each plane
 * 
 * 
 */
class Plane {

private:

    string numberPlate, type;
    int capacity, planeID{};
    std::vector<Baggage> baggages;

public:
    /**
     * @brief Default constructor
     * 
     */
    Plane();
    /**
     * @brief Construct a new Plane object with specified data
     * 
     * @param planeID -> plane's unique identifier
     * @param type  -> plane's type
     * @param numberPlate -> plane's number plate
     * @param capacity -> plane's passenger capacity
     */
    Plane(int planeID, std::string type, std::string numberPlate,  int capacity);
    /**
     * @brief Sets the plane's number plate
     * 
     * @param numberPlate_ 
     */
    void setNumberPlate(std::string numberPlate_);
    /**
     * @brief Sets the plane's type
     * 
     * @param type_ 
     */
    void setType(std::string type_);
    /**
     * @brief Sets the plane's passenger capacity
     * 
     * @param capacity_ 
     */
    void setCapacity(int capacity_);
    /**
     * @brief Set the plane's unique identifier
     * 
     * @param pID 
     */
    void setPlaneID(int pID);
    /**
     * @brief Returns the plane's number plate
     * 
     * @return string 
     */
    std::string getNumberPlate() const;
    /**
     * @brief Returns the plane's type
     * 
     * @return string 
     */
    std::string getType() const;
    /**
     * @brief Returns the plane's capacity
     * 
     * @return int 
     */
    int getCapacity() const;
    /**
     * @brief Returns the plane's unique identifier
     * 
     * @return int 
     */
    int getPlaneID() const;
    /**
     * @brief Returns the flights associated with the plane
     * 
     * @return list<Flight> 
     */
    std::list<Flight> getFlightsList();
    /**
     * @brief Fills the plane with the passenger's baggages
     * 
     * @param baggage 
     */
    void fill(Baggage baggage);
};

#endif //PROJETO_PLANE_H
