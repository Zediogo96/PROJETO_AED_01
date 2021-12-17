//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_FLIGHT_H
#define PROJETO_FLIGHT_H

#include <vector>
#include "../Utility/Date.h"
#include "../Utility/Time.h"
#include "../Passenger/Passenger.h"
#include "Airport.h"
#include "../Passenger/Seat.h"

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

    /** brief: Default constructor **/
    Flight();

    /** brief: Constructor for Flight Class **/
    Flight(int planeAssigned, int numberOfFlight_, Date departureDate_, Time flightDuration_,
           std::string departureLocation_, std::string destination_, int seatsNum);

    // GETTERS
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

    /** brief: Sets the Origin Airport according to the departure city of the flight **/
    void setOriginAirport(Airport airport);
    /** brief: Sets the Destination Airport according to the destination city of the flight **/
    void setDestAirport(Airport airport);
    /** brief: Prints the info about this specific Flight **/
    void printInfo() const;

    /**
     * reserves a Seat for the Passenger, and updates the Seat in the Flight to occupied.
     * @param passenger
     */
    void ReserveSeat(Passenger &passenger);

    /**
     * Checks if the Seat a User is trying to choose is already taken or not
     * @param num
     * @return Returns false if it's already taken, true if not.
     */
    bool availableSeat(int num);

    /**
     * Check if the clientID belongs to another person, and also if the user with this clientID already has a
     * reserved Seat to this flight, notyfing him
     * @param num
     * @param firstName
     * @param lastName
     * @return
     */
    bool availableClientID(int num, const std::string& firstName, const std::string& lastName);

    /** brief: Method to print all the available seats in this flight **/
    void printSeats();

    string board();

    vector<Passenger> &getPassengersList();
};

#endif //PROJETO_FLIGHT_H