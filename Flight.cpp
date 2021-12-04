// Created by zedio on 22/11/2021.
//

#include "Flight.h"

Flight::Flight() {

    flightID = 0;
    departureDate = Date();
    flightDuration = Time();
    departureLocation = "N/A";
    destination = "N/A";
}

Flight::Flight (int numberOfFlight_, Date departureDate_, Time flightDuration_,
       std::string departureLocation_, std::string destination_) {

    numberOfFlight_ = numberOfFlight_;
    departureDate = departureDate_;
    flightDuration = flightDuration_;
    departureLocation = departureLocation_;
    destination = destination_;
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
    departureLocation = departureLocation_;
}

void Flight::setDestination(std::string destination_) {
    destination = destination_;
}
