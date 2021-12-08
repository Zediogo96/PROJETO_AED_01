//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_FLIGHT_H
#define PROJETO_FLIGHT_H


#include "Utility/Date.h"
#include "Utility/Time.h"

class Flight {

private:

    int planeID;
    int flightID;
    Date departureDate;
    Time flightDuration;
    std::string departureLocation;
    std::string destination;

public:
    int getPlaneID() const;
    int getFlightID() const;
    Date getDepartureDate() const;
    Time getFlightDuration() const;
    std::string getDepartureLocation() const;
    std::string getDestination() const;

    void setPlaneID(int planeID_);
    void setFlightID(int flightID_);
    void setDepartureDate(Date date_);
    void setFlightDuration(Time time_);
    void setDepartureLocation(std::string departureLocation_);
    void setDestination(std::string destination_);

    Flight();

    Flight(int planeAssigned, int numberOfFlight_, Date departureDate_, Time flightDuration_,
           std::string departureLocation_, std::string destination_);
};

#endif //PROJETO_FLIGHT_H