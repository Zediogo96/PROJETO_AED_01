//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_FLIGHT_H
#define PROJETO_FLIGHT_H


#include <vector>
#include "Utility/Date.h"
#include "Utility/Time.h"
#include "Passenger/Passenger.h"
#include "Airport.h"
#include "Passenger/Seat.h"

class Flight {

private:
    Airport destAirport;
    Airport originAirport;
    int planeID{};
    int flightID{};
    Date departureDate;
    Time flightDuration;
    std::string departureLocation;
    std::string destination;
    int seatsNumber{};

    std::vector<Passenger> mPassengers;
    std::vector<Seat> mSeatsAvailable;

public:

    int getPlaneID() const;
    int getFlightID() const;
    Date getDepartureDate() const;
    Time getFlightDuration() const;
    std::string getDepartureLocation() const;
    std::string getDestination() const;
    int getSeatsNumber() const;
    Airport& getOriginAirport();
    Airport& getDestAirport();
    vector<Seat> & getSeatsAvailable();

    void setPlaneID(int planeID_);
    void setFlightID(int flightID_);
    void setDepartureDate(Date date_);
    void setFlightDuration(Time time_);
    void setDepartureLocation(std::string departureLocation_);
    void setDestination(std::string destination_);
    void setSeatsNumber(int seatsNum_);
    void setOriginAirport(Airport airport);
    void setDestAirport(Airport airport);

    void printInfo() const;

    void printAirport() {
        destAirport.toString();
        originAirport.toString();
    }

    Flight();

    Flight(int planeAssigned, int numberOfFlight_, Date departureDate_, Time flightDuration_,
           std::string departureLocation_, std::string destination_, int seatsNum);

    void ReserveSeat(Passenger &passenger);

    bool availableSeat(int num);

    bool availableClientID(int num, const std::string& firstName, const std::string& lastName);

    string board();

    void printSeats();
};

#endif //PROJETO_FLIGHT_H