// Created by zedio on 22/11/2021.
//

#include "Flight.h"

#include <utility>

Flight::Flight() {

    flightID = 0;
    departureDate = Date();
    flightDuration = Time();
    departureLocation = "N/A";
    destination = "N/A";
}

Flight::Flight (int flightID, Date departureDate_, Time flightDuration_,
       std::string departureLocation_, std::string destination_) {

    this->flightID = flightID;
    this->departureDate = departureDate_;
    this->flightDuration = flightDuration_;
    this->departureLocation = std::move(departureLocation_);
    this->destination = std::move(destination_);

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
    departureLocation = std::move(departureLocation_);
}

void Flight::setDestination(std::string destination_) {
    destination = std::move(destination_);
}
