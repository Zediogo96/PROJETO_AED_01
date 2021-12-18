//
// Created by zedio on 21/11/2021.
//
#ifndef PROJETO_AIRLINE_H
#define PROJETO_AIRLINE_H


#include <string>
#include <vector>
#include <list>

#include "Plane.h"
#include "../Services/Staff.h"
#include "../Services/Service.h"
#include "Airport.h"

/**
 * @brief Class handling airlines. Contains information regarding services, planes, flights, and airports.
 * 
 */
class Airline {
private:
    std::vector<Plane> planesList;
    std::vector<Flight> flightsList;
    std::queue<Service*> servicesQueue;
    std::list<Service*> servicesHistory;
    vector<Airport> airportList;

    std::string name;
    int maxNumOfFlights;

public:

    /** @brief Constructor for the Airline Class */
    Airline(const std::string &name, int maxNumOfFlights) {
        this->name = name;
        this->maxNumOfFlights = maxNumOfFlights;
        planesList.clear();
    }

    /**
     * @brief Returns the name of the airline
     * 
     * @return const string& 
     */
    const std::string& getName();
    /**
     * @brief Returns the maximum number of flights allowed by the airline
     * 
     * @return int 
     */
    int getMaxNumOfFlights() const;
    /**
     * @brief Returns the planes belonging to the airline
     * 
     * @return std::vector<Plane> 
     */
    std::vector<Plane> getPlanes();
    /**
     * @brief Returns the amount of airports allocated to the airline
     * 
     * @return int 
     */
    int getAirportCount();
    /**
     * @brief Returns an airport with the respective 'id'
     * 
     * @param id 
     * @return Airport 
     */
    Airport getAirport(int id);

    /**
     * @brief Returns an airport with the respective 'name'
     * 
     * @param name 
     * @return Airport 
     */
    Airport getAirport(const string& name);

    /////////////////////////////////// HANDLE PLANES ///////////////////////////////////////

    /**
     * @brief Saves all the planes into the file 'Data/planes.txt'
     **/
    void SavePlanes();
    /**
     * @brief Loads all the planes from the file 'Data/planes.txt'
     * 
     */
    void LoadPlanes();

    /**
     * @brief Loads all the airports from the file 'Data/airports.txt'
     * 
     */
    void loadAirports();

    /**
     * @brief Method that analyzes if a determinate planeID is already in use when creating a new plane,
     * return False if it's already in use, return True if it's free.
     * @param planeID
     * @return Boolean
     */
    bool availablePlane(int planeID);

    /**
     * @brief Method that allows the user to search for a determinate plane based on it's planeID (by input),
     * returns the planeID if its found, or -1 in case if it's not found.
     * @return planeID
     */
    int findPlane();

    /**
     * @brief: Method to add a plane to the airline planes database, filling it's parameters by user input.
     */
    void addPlane();

    /**
     * @brief: Method to allow the user to delete a plane by inputting it's userID.
     */
    void deletePlane();

    /**
     * @brief: Method that prints all the planes in the Airline database.
     */
    void printPlanes();

    /**
     * @brief: Method that eliminates all Planes from the planesList database.
     */
    void clearPlanes();

    /**
     * @brief Allows the user to sort the planeList according to the user chosen parameter.
     */
    void sortPlanes();

    /**
     * @brief: Method that eliminates all Flights from all planes in the database.
     */
    void clearFlights();

    /**
     * @brief Returns a pointer to the plane with id equal to 'num'
     * 
     * @param num 
     * @return Plane* 
     */
    Plane *getPlaneRef(int num);

    /**
     * @brief Check if a plane with id equal to 'num' exists in the airline
     * 
     * @param num 
     * @return bool
     */
    bool PlaneExists(int num);

    /////////////////////////////////// HANDLE FLIGHTS ///////////////////////////////////////

    /**
     * @brief Saves all flights into the file 'Data/flights.txt'
     * 
     */
    void SaveFlights();
    /**
     * @brief Loads all the flights from the file 'Data/flights.txt'
     * 
     */
    void LoadFlights();

    /**
     * @brief Check if a flight with id equal to 'flightID' already exists in the airline
     * 
     * @param flightID 
     * @return bool
     */
    bool avaliableFlight(int flightID);
    /**
     * @brief Sorts the flights according to user input
     * 
     */
    void sortFlights();
    /**
     * @brief Adds a new flight to the airline
     * 
     */
    void addFlight();
    /**
     * @brief Deletes a flight from the airline
     * 
     */
    void deleteFlight();
    /**
     * @brief Returns a pointer to the flight with id equal to 'num'
     * 
     * @param num 
     * @return Flight& 
     */
    Flight &getFlightRef(int num);
    /**
     * @brief Prints all flights belonging to the airline
     * 
     */
    void printAllFlights();

    /////////////////////////////////// HANDLE SERVICES ///////////////////////////////////////

    /**
     * @brief Adds a new service with specified user input data
     **/
    void addService();
    /**
     * @brief Checks if a service with the specified user input exists
     * 
     */
    void checkService();
    /**
     * @brief Prints all performed services
     * 
     */
    void printAllServicesHistory();
    /**
     * @brief Loads all services from the file 'Data/services.txt'
     * 
     */
    void LoadServices();
    /**
     * @brief Prints all services to be performed
     * 
     */
    void printAllServicesDue();
    /**
     * @brief Allows the user to reserve a seat in a specific flight
     * 
     */
    void reserveSeat();

    /**
     * @brief Checks if an airport located in a 'city' exists in the airline
     * 
     * @param city 
     * @return bool 
     */
    bool airportExists(string &city);


/////////////////////////////////// HANDLE PASSENGERS ///////////////////////////////////////
    
    /**
     * @brief Loads all passengers from the file 'Data/passengers.txt'
     * 
     */
    void LoadPassengers();
    /**
     * @brief Adds seats already reserved from passengers loaded from file
     * 
     * @param flightID 
     * @param firstName 
     * @param lastName 
     * @param seatNum 
     * @param clientID 
     * @param baggage 
     */
    void ReservedSeats(int flightID, const string& firstName, const string& lastName, int seatNum, int clientID, bool baggage);

    /**
     * @brief Checks seats already taken by passengers
     * 
     */
    void checkPassengerSeats();

    void saveServices();
};

#endif //PROJETO_AIRLINE_H