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
Plane::Plane(int planeID, std::string type, std::string numberPlate,  int capacity) {
    this->planeID = planeID;
    this->type = std::move(type);
    this->numberPlate = std::move(numberPlate);
    this->capacity = capacity;

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
    this->numberPlate = std::move(numberPlate_);
}

void Plane::setType(std::string type_) {
    this->type = std::move(type_);
}

void Plane::setCapacity(int capacity_) {
    this->capacity = capacity_;
}

void Plane::setPlaneID(int pID) {
    this->planeID = pID;
}

void Plane::fill(Baggage baggage) {
    baggages.push_back(baggage);
}