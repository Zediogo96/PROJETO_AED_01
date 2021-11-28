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
    this->type = type_;
}

void Plane::setCapacity(int capacity_) {
    this->capacity = capacity_;
}

void Plane::setPlaneID(int pID) {
    this->planeID = pID;
}

void Plane::SaveFlights() {

    std::fstream file("Flights.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);

    for (std::list<Flight>::iterator it = flightsList.begin(); it != flightsList.end(); it++) {

        file << (int) (*it).getFlightID() << std::endl;

        file << (int) (*it).getDepartureDate().getYear() << std::endl;
        file << (int) (*it).getDepartureDate().getMonth() << std::endl;
        file << (int) (*it).getDepartureDate().getDay() << std::endl;

        file << (int) (*it).getFlightDuration().getHours() << std::endl;
        file << (int) (*it).getFlightDuration().getMinutes() << std::endl;

        file << (std::string) (*it).getDepartureLocation() << std::endl;
        file << (std::string) (*it).getDestination() << std::endl;
    }
    file.close();
}

void Plane::LoadFlights() {

    std::ifstream file;

    Flight newFlight;

    std::string str;
    int num;

    file.open("Planes.txt");

    while(file) {
        file >> num;
        newFlight.setFlightID(num);
        file >> num;
        newFlight.getDepartureDate().setYear(num);
        file >> num;
        newFlight.getDepartureDate().setMonth(num);
        file >> num;
        newFlight.getDepartureDate().setDay(num);
        file >> num;
        newFlight.getFlightDuration().setHours(num);
        file >> num;
        newFlight.getFlightDuration().setMinutes(num);
        file >> str;
        newFlight.setDepartureLocation(str);
        file >> str;
        newFlight.setDestination(str);


        flightsList.push_back(newFlight);
        }
}

void Plane::addFlight() {

    Flight newFlight;

    int flightID;
    Date departDate;
    Time duration;
    std::string departLocation;
    std::string destination;

    InputInt(flightID, "Enter the flightID for this Flight: ");

    InputDate(departDate, "Enter the Departure Date for this Flight: ");

    InputTime(duration, "Enter the duration of this Flight: ");

    InputStr(departLocation, "Enter the Departure Location for this Flight: ");

    InputStr(destination, "Enter the Destination for this Flight: ");

    newFlight.setFlightID(flightID);
    newFlight.setDepartureDate(departDate);
    newFlight.setFlightDuration(duration);
    newFlight.setDepartureLocation(departLocation);
    newFlight.setDestination(destination);

    flightsList.push_back(newFlight);
}




