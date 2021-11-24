//
// Created by zedio on 21/11/2021.
//
#include <fstream>
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

    std::cin.clear();
    InputInt(planeID, "Enter the Plane's ID: ");

    for (int i = 0; i < planesList.size(); i++) {

        if (planesList.at(i).getPlaneID() == planeID) {
            std::cout << "Plane Found. \n";
            return i;
        }
    }
    std::cout << "Plane not found in our database \n";
    return -1;

}

void Airline::searchPlane() {

    int tmpIndex = findPlane();

    std::cout << "{ PlaneID: " << planesList.at(tmpIndex).getPlaneID() << ", Plane Type: " << planesList.at(tmpIndex).getType()
        << ", NumberPlate: " << planesList.at(tmpIndex).getNumberPlate()
              << ", Capacity: " << planesList.at(tmpIndex).getCapacity() << " }" << std::endl;
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
    SavePlanes();
}

void Airline::deletePlane() {
    int planeID;

    int tmpIndex = findPlane();

    if (tmpIndex != -1) {
        planesList.erase(planesList.begin() + tmpIndex);
        std::cout << "Plane was deleted successfully" << std::endl;
    }

    SavePlanes();
}

void Airline::printPlanes() {
    for (Plane tmp : planesList) {
        std::cout << "{ PlaneID: " << tmp.getPlaneID() << ", Plane Type: " << tmp.getType() << ", NumberPlate: " << tmp.getNumberPlate()
                << ", Capacity: " << tmp.getCapacity() << " }" << std::endl;
    }
}


void Airline::SavePlanes() {

    std::fstream file("Planes.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);

    for (std::vector<Plane>::iterator it = planesList.begin(); it != planesList.end(); it++) {
        file << (std::string)(*it).getNumberPlate() << std::endl;
        file << (std::string)(*it).getType() << std::endl;
        file << (int)(*it).getCapacity() << std::endl;
        file << (int)(*it).getPlaneID() << std::endl;
    }
    file.close();
}

void Airline::LoadPlanes() {

    std::ifstream file;

    Plane newPlane;
    std::string str;
    int num;

    file.open("Planes.txt");

    while(!file) {
        file >> str;
        newPlane.setNumberPlate(str);
        file >> str;
        newPlane.setType(str);
        file >> num;
        newPlane.setCapacity(num);
        file >> num;
        newPlane.setPlaneID(num);

        planesList.push_back(newPlane);
    }
}
void Airline::clearPlanes() {
    planesList.clear();
}


