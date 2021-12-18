#pragma once
/**
 * @brief Class handling baggages, storing basic information about their owners
 * 
 */
class Baggage {
    int passengerID;


public:
/**
 * @brief Default constructor
 * 
 */
    Baggage();
    /**
     * @brief Constructs a new Baggage object with a passenger's unique identifier
     * 
     * @param pid -> Passenger id
     */
    Baggage(int pid);
    /**
     * @brief Returns the id of the passenger the baggage belongs to
     * 
     * @return int 
     */
    int getPassengerID();
};