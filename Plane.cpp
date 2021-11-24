//
// Created by zedio on 22/11/2021.
//

#include "Plane.h"

/** @brief: Empty Constructor for class Plane */
Plane::Plane() {
    numberPlate = "N/A";
    type = "N/A";
    capacity = 0;
}

/** @brief: Creates a new object of class Plane */
Plane::Plane(std::string numberPlate, std::string type, int capacity, int planeID) {
    this->numberPlate = numberPlate;
    this->type = type;
    this->capacity = capacity;
    this->planeID = planeID;
}

std::string Plane::getNumberPlate() const {
    return numberPlate;
}

std::string Plane::getType() const {
    return type;
}

int Plane::getCapacity() const {
    return capacity;
}

int Plane::getPlaneID() const {
    return planeID;
}

void Plane::setNumberPlate(std::string numberPlate_) {
    this->numberPlate = numberPlate_;
}

void Plane::setType(std::string type_) {

    try {
        // Using method from utility to validate input using Regular Expressions (regex)
        if (validatePlaneType(type_)) {
            this->type = type_;
        }
    }
    catch (std::logic_error){
        std::cout << "Invalid input for Plane Type." << std::endl;
    }
}

void Plane::setCapacity(int capacity_) {
    this->capacity = capacity_;
}

void Plane::setPlaneID(int pID) {
    if(pID > 0) {
        this->planeID = pID;
    }
    std::cout << "Invalid value for planeID. \n";
}




