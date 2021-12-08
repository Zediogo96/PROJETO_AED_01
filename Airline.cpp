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

    std::string filename = "planes.txt";
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
    std::string filename = "planes.txt";

    file.open(filename, std::ifstream::in);

    while(file >> plateNumber >> type >> capacity >> planeID) {
        planesList.emplace_back(Plane(plateNumber, type, capacity, planeID));
    }
}

void Airline::SaveFlights() {
    std::string filename = "flights.txt";
    std::fstream output;

    output.open(filename, std::fstream::out);

    if(output.is_open()) {
        for (auto & plane : planesList) {
            for (auto & it : plane.getFlightsList()) {
                std::string s;
                output << plane.getPlaneID() << " " << it.getFlightID() << " "
                       << it.getDepartureDate().toString() << " " << it.getFlightDuration().toString()
                       << " " << it.getDepartureLocation() << " " << it.getDestination() << std::endl;
            }
        }
    }
}

void Airline::LoadFlights() {
/*
    std::ifstream file;

    Flight newFlight;

    int planeID, flightID, hours, minutes;
    std::string depart, destination, date;

    file.open("flights.txt");

    while(file >> planeID >> flightID >> date >> hours >> minutes >> depart >> destination) {

        newFlight.setFlightID(flightID);

        newFlight.getDepartureDate().setYear(std::stoi(date.substr(0,3)));

        newFlight.getDepartureDate().setMonth(std::stoi(date.substr(5,6)));

        newFlight.getDepartureDate().setDay(std::stoi(date.substr(8,9)));


        newFlight.getFlightDuration().setHours(hours);

        newFlight.getFlightDuration().setMinutes(minutes);

        newFlight.setDepartureLocation(depart);

        newFlight.setDestination(destination);

        for (auto it : planesList) {
            if (it.getPlaneID() == planeID) it.getFlightsList().push_back()
        }
    }*/
}

Plane* Airline::getPlaneRef_input() {
    int planeID;

    std::cin.clear();

    InputInt(planeID, "Enter the Plane's ID: ");

    Plane *c = nullptr;
    for (auto &i: planesList) {
        if (i.getPlaneID() == planeID) {
            c = &i;
            break;
        }
    }
    return c;
}

Plane* Airline::getPlaneRef(int num) {
    Plane *c = nullptr;
    for (auto &i: planesList) {
        if (i.getPlaneID() == num) {
            c = &i;
            break;
        }
    }
    return c;
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
                return a.getPlaneID() < b.getPlaneID();
            });
        case 2:
            std::sort(planesList.begin(), planesList.end(),[&](const Plane & a, const Plane & b) {
                return a.getNumberPlate() < b.getNumberPlate();
            });
        case 3:
            std::sort(planesList.begin(), planesList.end(),[&](const Plane & a, const Plane & b) {
                return a.getType() < b.getType();
            });
        case 4:
            std::sort(planesList.begin(), planesList.end(),[&](const Plane & a, const Plane & b) {
                return a.getCapacity() < b.getCapacity();
            });
        default: std::cout << "Invalid Input" << std::endl;
    }
}

std::vector<Plane> Airline::getPlanes() {
    return this->planesList;
}

//////////////////////////////////////////

void Airline::printAllFlights() {
    for (auto elem : planesList) {
        elem.printFlights();
    }
}

void Airline::clearFlights() {
    for (Plane elem : planesList) {
        elem.getFlightsList().clear();
    }
}

