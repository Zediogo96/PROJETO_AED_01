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
    this->numberPlate = std::move(numberPlate);
    this->type = std::move(type);
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

std::list<Flight> Plane::getFlightsList() {
    return flightsList;
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

bool Plane::availableFlight(int flightID) {

    for (auto & it : flightsList) {
        if (it.getFlightID() == flightID) {
            std::cout << "This flightID is already used in another flight, please select another.\n";
            return false;
        }
    }
    return true;
}

void Plane::SaveFlights() {

    std::fstream file("Flights.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);

    for (auto & it : flightsList) {

        file << (int) it.getFlightID() << std::endl;

        file << (int) it.getDepartureDate().getYear() << std::endl;
        file << (int) it.getDepartureDate().getMonth() << std::endl;
        file << (int) it.getDepartureDate().getDay() << std::endl;

        file << (int) it.getFlightDuration().getHours() << std::endl;
        file << (int) it.getFlightDuration().getMinutes() << std::endl;

        file << (std::string) it.getDepartureLocation() << std::endl;
        file << (std::string) it.getDestination() << std::endl;
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
    std::string departDate;
    std::string flightDuration;
    std::string departLocation;
    std::string destination;

    do {
        InputInt(flightID, "Enter the flightID for this Flight: ");
    } while (!availableFlight(flightID));

    do {
        InputStr(departDate, "Enter the Departure Date for this Flight: ");
    } while(!validateDate(departDate));

    do {
        InputStr(flightDuration, "Enter the duration of this Flight: ");
    } while(!validateTime(flightDuration));

    InputStr(departLocation, "Enter the Departure Location for this Flight: ");

    InputStr(destination, "Enter the Destination for this Flight: ");

    newFlight.setFlightID(flightID);
    newFlight.setDepartureDate(Date(std::stoi(departDate.substr(0,4)),
                                    std::stoi(departDate.substr(5,6)),
                                    std::stoi(departDate.substr(8,11))));

    newFlight.setFlightDuration(Time(std::stoi(flightDuration.substr(0,2)),
                                     std::stoi(flightDuration.substr(3,4))));

    newFlight.setDepartureLocation(departLocation);
    newFlight.setDestination(destination);

    flightsList.emplace_back(newFlight);
}

void Plane::deleteFlight() {

    int flightID;
    InputInt(flightID, "Enter the Flight's ID: ");

    for (auto it = flightsList.begin(); it != flightsList.end(); it++) {
        if ((*it).getFlightID() == flightID) {
            flightsList.erase(it);
            std::cout << "Flight was deleted successfully!" << std::endl;
        }

    }
    std::cout << "Flight was not found in our database. \n";
}

void Plane::printFlights() {

    if (!flightsList.empty()) {
        std::cout << "[PlaneID: " << this->getPlaneID() << " ]" << std::endl;
        for (const Flight& it : flightsList) {
            std::cout << "{ FlightID: " << it.getFlightID() << ", Departure Date:  " << it.getDepartureDate().getYear()
                      << "/" << it.getDepartureDate().getMonth() << "/" << it.getDepartureDate().getDay() << ", Flight Duration: "
                      << it.getFlightDuration().getHours() << ":" << it.getFlightDuration().getMinutes() << ", Departure Location: "
                      << it.getDepartureLocation() << ", Destination: " << it.getDestination() << " }" << std::endl;
        }
    }

}



