// Created by zedio on 22/11/2021.
//

#include "Flight.h"

#include <utility>

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
        mSeatsAvailable.emplace_back(Seat(i));
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

std::vector<Seat>& Flight::getSeatsAvailable() {
    return mSeatsAvailable;
}

void Flight::setDestAirport(Airport airport) {
    this->destAirport = std::move(airport);
}

void Flight::setOriginAirport(Airport airport) {
    this->originAirport = std::move(airport);
}

void Flight::printInfo() const {
    std::cout << "{Plane ID: " << getPlaneID() << " ,FlightID: " << getFlightID() << ", Departure Date: " <<
              getDepartureDate().toString() << ", Flight Duration: "
              << getFlightDuration().toString() << ", Departure Location: "
              << getDepartureLocation() << ", Destination: " << getDestination() << ", Number of Seats Available: "
              << mSeatsAvailable.size() << "}" << std::endl;
}

void Flight::ReserveSeat(Passenger& passenger)
{
    mPassengers.push_back(passenger);
    int seatNumber = passenger.GetSeatNumber();

    for (auto & it : mSeatsAvailable) {
        if (it.getSeatNum() == seatNumber) {
            it.setTaken();
        }
    }
}

bool Flight::availableSeat(int num) {

    for (auto &it : mSeatsAvailable) {
        if (it.getSeatNum() == num && !it.isTaken()) {
            return true;
        }
    }
    std::cout << "This Seat is Already Taken! \n";
    return false;
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

string Flight::board() {
    if (mPassengers.empty())
        return "This flight has no passengers!";

    char option;
    for(Passenger& passenger : mPassengers) {
        if(passenger.includedBaggage()) {
            std::cout << "Passenger " << passenger.GetPassengerFirstName() << " " << passenger.GetPassengerLastName() << ", auto-baggage collection (y/n)? " << endl;
            std::cin >> option;
            if(option == 'y')
                originAirport.addBaggageToConveyor(passenger.getBaggage());
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }
    
    return "All passengers boarded!";
}

Airport &Flight::getOriginAirport() {
    return originAirport;
}

Airport &Flight::getDestAirport() {
    return destAirport;
}

void Flight::printSeats() {
    int aux = 1;
    cout << "Seats Available: " << endl;
    for (Seat elem: mSeatsAvailable) {
        if (!elem.isTaken()) {
            if (aux % 16 == 0) {
                cout << endl;
            } else {
                cout << "[" << elem.getSeatNum() << "]";
            }
            aux++;
        }
    }
    cout << endl;
}
