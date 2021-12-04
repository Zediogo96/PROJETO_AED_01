//
// Created by zedio on 21/11/2021.
//
#include <fstream>
#include "Airline.h"

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

    std::cout << "Plane was added successfully! \n" << std::endl;
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

    std::string filename = R"(C:\Users\zedio\Documents\Documentos\FEUP\2ANO\AED\PROJETO\Data\planes.txt)";
    std::fstream output;

    output.open(filename, std::fstream::out);

    if(output.is_open()) {
        for (auto & it : planesList) {
            output << (std::string)it.getNumberPlate() << " " << (std::string)it.getType() <<
                 " " << (int)it.getCapacity() << " " << (int)it.getPlaneID() << std::endl;
        }
    }
}

void Airline::LoadPlanes() {

    planesList.clear();

    Plane newPlane;
    std::string plateNumber, type;
    int capacity, planeID;

    std::ifstream file;
    std::string filename = R"(C:\Users\zedio\Documents\Documentos\FEUP\2ANO\AED\PROJETO\Data\planes.txt)";

    file.open(filename, std::ifstream::in);

    while(file >> plateNumber >> type >> capacity >> planeID) {
        planesList.emplace_back(Plane(plateNumber, type, capacity, planeID));
    }
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


//////////////////////////////////////////

void Airline::printAllFlights() {
    for (auto elem : planesList) {
        elem.printFlights();
    }
}

void Airline::clearFlights() {
    for (auto elem : planesList) {
        elem.getFlightsList().clear();
    }
}

