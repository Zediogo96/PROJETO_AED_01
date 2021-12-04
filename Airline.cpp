//
// Created by zedio on 21/11/2021.
//
#include <fstream>
#include "Airline.h"
#include "Utility/utility.h"

const std::string& Airline::getName() {
    return name;
}

int Airline::getMaxNumOfFlights() const {
    return maxNumOfFlights;
}

bool Airline::availablePlane(int planeID) {

    for (auto & it : planesList) {
        if (it.getPlaneID() == planeID) {
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


    std::cout << "Plane was added successfully!" << std::endl;
    std::cin.ignore();
}

void Airline::deletePlane() {

    int tmpIndex = findPlane();

    if (tmpIndex != -1) {
        planesList.erase(planesList.begin() + tmpIndex);
        std::cout << "Plane was deleted successfully" << std::endl;
    }
}

void Airline::printPlanes() {
    for (const Plane& tmp : planesList) {
        std::cout << "{ PlaneID: " << tmp.getPlaneID() << ", Plane Type: " << tmp.getType() << ", NumberPlate: " << tmp.getNumberPlate()
                << ", Capacity: " << tmp.getCapacity() << " }" << std::endl;
    }
}

void Airline::SavePlanes() {

    std::fstream file("Planes.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
    file.clear();

    for (auto & it : planesList) {
        file << (std::string)it.getNumberPlate() << std::endl;
        file << (std::string)it.getType() << std::endl;
        file << (int)it.getCapacity() << std::endl;
        file << (int)it.getPlaneID() << std::endl;
    }
    file.close();
}

void Airline::LoadPlanes() {

    std::ifstream file;

    Plane newPlane;
    std::string str;
    int num;

    file.open("Planes.txt");

    while(file) {
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
    file.close();
}

void Airline::clearPlanes() {
    planesList.clear();
}

void Airline::sortPlanes() {

    int userInput;

    std::cout << "Please select the parameter you wish to sort the planes by: " << std::endl;
    std::cout << "[1] PlaneID" << std::endl;
    std::cout << "[2] Plate Number" << std::endl;
    std::cout << "[3] Plane Type" << std::endl;
    std::cout << "[4] Capacity" << std::endl;

    std::cin >> userInput;

    switch(userInput) {
        case 1:
            std::sort(planesList.begin(), planesList.end(),[&](const Plane & a, const Plane & b) {
                return a.getPlaneID() > b.getPlaneID();
            });
        case 2:
            std::sort(planesList.begin(), planesList.end(),[&](const Plane & a, const Plane & b) {
                return a.getNumberPlate() > b.getNumberPlate();
            });
        case 3:
            std::sort(planesList.begin(), planesList.end(),[&](const Plane & a, const Plane & b) {
                return a.getType() > b.getType();
            });
        case 4:
            std::sort(planesList.begin(), planesList.end(),[&](const Plane & a, const Plane & b) {
                return a.getCapacity() > b.getCapacity();
            });
        default: std::cout << "Invalid Input" << std::endl;
    }
}

std::vector<Plane> Airline::getPlanes() {
    return planesList;
}


