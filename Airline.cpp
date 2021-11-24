//
// Created by zedio on 21/11/2021.
//
#include "Airline.h"
#include "utility.h"

Airline* Airline::airline = nullptr;

Airline::Airline(const std::string& name, int maxNumOfFlights): name(name), maxNumOfFlights(maxNumOfFlights) {}

Airline& Airline::getInstance(const std::string &name, int maxNumOfFlights) {
    if (airline == nullptr) {
        airline = new Airline(name, maxNumOfFlights);
    }
    return *airline;
}

Airline::~Airline() {
    delete airline;
}

const std::string& Airline::getName() {
    return name;
}

int Airline::getMaxNumOfFlights() {
    return maxNumOfFlights;
}

int Airline::getCurrentNumOfFlights() {
    return currentNumOfFlights;
}

bool Airline::availablePlane(int planeID) {

    for (std::vector<Plane>::iterator it = planesList.begin(); it != planesList.end(); it++) {
        if ((*it).getPlaneID() == planeID) {
            std::cout << "This planeID is already used in another plane, please select another.\n";
            return false;
        }
    }
    return true;
}

int Airline::findPlane() {

    int planeID;

    std::cin.ignore();
    InputInt(planeID, "Enter the Plane's number Plate: \n");

    for (int i = 0; i < planesList.size(); i++) {

        if (planesList.at(i).getPlaneID() == planeID) {
            std::cout << "Plane Found. \n";
            return true;
        }
    }
    std::cout << "Plane not found in our database \n";
    return -1;
}

void Airline::addPlane() {

    std::string numberPlate, type;
    int capacity, planeID;

    InputStr(numberPlate, "Enter the numberPlate of this plane: ");

    do {
        InputStr(type, "Enter the type of this plane: ");
    } while (!validatePlaneType(type));

    InputInt(capacity, "Enter the capacity of this plane: ");

    do
    {
        InputInt(planeID, "Enter the ID for this plane: ");

    } while(!availablePlane(planeID));

    Plane newPlane(numberPlate, type, capacity, planeID);

    planesList.push_back(newPlane);

    std::cin.ignore();
}

void Airline::printPlanes() {
    for (Plane tmp : planesList) {
        std::cout << "{ PlaneID: " << tmp.getPlaneID() << ", Plane Type: " << tmp.getType() << ", NumberPlate: " << tmp.getNumberPlate()
                << ", Capacity: " << tmp.getCapacity() << " }" << std::endl;
    }
}


