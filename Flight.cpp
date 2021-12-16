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

    for (int i = 1; i <= seatsNum; i++) {
        mSeatsAvailable.push_back(i);
    }
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

std::vector<int>& Flight::getSeatsAvailable() {
    return mSeatsAvailable;
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

void Flight::ReserveSeat(Passenger& passenger)
{
    mPassengers.push_back(passenger);
    int seatNumber = passenger.GetSeatNumber();

    for (auto it = mSeatsAvailable.begin(); it != mSeatsAvailable.end(); it++) {
        if ((*it) == seatNumber) {
            mSeatsAvailable.erase(it);
        }
    }
}

bool Flight::availableSeat(int num) {

    for (auto & it : mPassengers) {
        if (it.GetSeatNumber() == num) {
            std::cout << "This Seat is Already Taken! \n";
            return false;
        }
    }
    return true;
}

bool Flight::availableClientID(int num, const std::string& firstName, const std::string& lastName) {
    for (auto & it : mPassengers) {
        if (it.GetPassengerID() == num) {
            if (it.GetPassengerFirstName() == firstName && it.GetPassengerLastName() == lastName) {
                std::cout << "You already have a Seat under your clientID for this Flight!" << std::endl;
                system("pause");
                break;
            }
            std::cout << "That clientID belongs to another Person." << std::endl;
            return false;
        }
    }
    return true;
}

void Flight::setDepartureAirport(Airport &airport) {
    this->airportDeparture = airport;
}

void Flight::setArrivalAirport(Airport &airport) {
    this->airportArrival = airport;
}