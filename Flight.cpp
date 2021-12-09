// Created by zedio on 22/11/2021.
//

#include "Flight.h"

Flight::Flight() = default;

Flight::Flight(int planeID, int flightID, Date departureDate_, Time flightDuration_,
       std::string departureLocation_, std::string destination_, int seatsNum) {

    this->planeID = planeID;
    this->flightID = flightID;
    this->departureDate = departureDate_;
    this->flightDuration = flightDuration_;
    this->departureLocation = std::move(departureLocation_);
    this->destination = std::move(destination_);
    this->seatsNumber = seatsNum;

}


int Flight::getPlaneID() const {
    return planeID;
}
int Flight::getFlightID() const {
    return flightID;
}

Date Flight::getDepartureDate() const {
    return departureDate;
}

Time Flight::getFlightDuration() const {
    return flightDuration;
}

std::string Flight::getDepartureLocation() const {
    return departureLocation;
}

std::string Flight::getDestination() const {
    return destination;
}

int Flight::getSeatsNumber() const {
    return seatsNumber;
}

void Flight::setFlightID(int flightID_) {
    this->flightID = flightID_;
}

void Flight::setDepartureDate(Date date_) {
    departureDate = date_;
}

void Flight::setFlightDuration(Time time_) {
    flightDuration = time_;
}

void Flight::setDepartureLocation(std::string departureLocation_) {
    departureLocation = std::move(departureLocation_);
}

void Flight::setDestination(std::string destination_) {
    destination = std::move(destination_);
}

void Flight::setPlaneID(int planeID_) {
    planeID = planeID_;
}

void Flight::setSeatsNumber(int seatsNum_) {
    seatsNumber = seatsNum_;
}

void Flight::printInfo() const {
    std::cout << "{Plane ID: " << getPlaneID() << " ,FlightID: " << getFlightID() << ", Departure Date: " <<
              getDepartureDate().toString() << ", Flight Duration: "
              << getFlightDuration().toString() << ", Departure Location: "
              << getDepartureLocation() << ", Destination: " << getDestination() << ", Number of Seats: "
              << getSeatsNumber() << "}" << std::endl;
}


