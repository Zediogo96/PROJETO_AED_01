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

/**
 * @brief Class handling flights. Stores information regarding airports connected by the flight, plane's id associated with the flight, passengers who booked the flight and seats availiable.
 * 
 * 
 */
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

    /** @brief: Default constructor **/
    Flight();

    /** @brief: Constructor for Flight Class **/
    Flight(int planeAssigned, int numberOfFlight_, Date departureDate_, Time flightDuration_,
           std::string departureLocation_, std::string destination_, int seatsNum);

    /**
     * @brief Returns the plane's id associated with the flight
     * 
     * @return int 
     */
    int getPlaneID() const;
    /**
     * @brief Returns the flight's unique identifier
     * 
     * @return int 
     */
    int getFlightID() const;
    /**
     * @brief Returns the date of departure of the flight
     * 
     * @return Date 
     */
    Date getDepartureDate() const;
    /**
     * @brief Returns the duration of the flight
     * 
     * @return Time 
     */
    Time getFlightDuration() const;
    /**
     * @brief Returns the departure location of the flight
     * 
     * @return string 
     */
    std::string getDepartureLocation() const;
    /**
     * @brief Returns the destination location of the light
     * 
     * @return string 
     */
    std::string getDestination() const;
    /**
     * @brief Returns the numbers of the seats allocated to the flight
     * 
     * @return int 
     */
    int getSeatsNumber() const;
    /**
     * @brief Returns the airport of origin of the flight
     * 
     * @return Airport& 
     */
    Airport& getOriginAirport();
    /**
     * @brief Returns the airport of destination of the flight
     * 
     * @return Airport& 
     */
    Airport& getDestAirport();
    /**
     * @brief Returns the seats still avaliable in the flight
     * 
     * @return vector<Seat>& 
     */
    vector<Seat> & getSeatsAvailable();

    /** @brief Sets the Origin Airport according to the departure city of the flight **/
    void setOriginAirport(Airport airport);
    /** @brief Sets the Destination Airport according to the destination city of the flight **/
    void setDestAirport(Airport airport);
    /** @brief Prints the info about this specific Flight **/
    void printInfo() const;

    /**
     * @brief reserves a Seat for the Passenger, and updates the Seat in the Flight to occupied.
     * @param passenger
     */
    void ReserveSeat(Passenger &passenger);

    /**
     * @brief Checks if the Seat a User is trying to choose is already taken or not
     * @param num
     * @return Returns false if it's already taken, true if not.
     */
    bool availableSeat(int num);

    /**
     * @brief Check if the clientID belongs to another person, and also if the user with this clientID already has a
     * reserved Seat to this flight, notyfing him
     * @param num
     * @param firstName
     * @param lastName
     * @return
     */
    bool availableClientID(int num, const std::string& firstName, const std::string& lastName);

    /** @brief Method to print all the available seats in this flight **/
    void printSeats();
    /**
     * @brief Boards the passengers belonging to the flight
     * 
     * @return string 
     */
    string board();

    /**
     * @brief Returns the passengers belonging to the flight
     * 
     * @return vector<Passenger>& 
     */
    vector<Passenger> &getPassengersList();

    /**
     * @brief Method to count the Number of Free Seats in a Flight (in which taken is set to false)
     * @return int
     */
    int getFreeSeatsCount() const;
};

#endif //PROJETO_FLIGHT_H