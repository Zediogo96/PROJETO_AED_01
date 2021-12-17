//
// Created by zedio on 21/11/2021.
//
#ifndef PROJETO_AIRLINE_H
#define PROJETO_AIRLINE_H


#include <string>
#include <vector>
#include <list>

#include "Plane.h"
#include "Services/Staff.h"
#include "Services/Service.h"
#include "Airport.h"

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

    /** @brief GETTERS for fields of Airline Class */
    const std::string& getName();
    int getMaxNumOfFlights() const;
    std::vector<Plane> getPlanes();
    int getAirportCount();
    Airport getAirport(int id);
    Airport getAirport(const string& name);
    /******************************************** HANDLE PLANES **************************** */

    void SavePlanes();
    void LoadPlanes();

    void loadAirports();

    /**
     * Method that analyzes if a determinate planeID is already in use when creating a new plane,
     * return False if it's already in use, return True if it's free.
     * @param planeID
     * @return Boolean
     */
    bool availablePlane(int planeID);

    /**
     * Method that allows the user to search for a determinate plane based on it's planeID (by input),
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
     * Allows the user to sort the planeList according to the user chosen parameter.
     */
    void sortPlanes();

    /**
     * @brief: Method that eliminates all Flights from all planes in the database.
     */
    void clearFlights();

    Plane* getPlaneRef_input();

    Plane *getPlaneRef(int num);

    bool PlaneExists(int num);

    /************************************** HANDLE FLIGHTS *********************/


    void SaveFlights();
    void LoadFlights();

    bool availableFlight(int flightID);

    void addFlight();
    void deleteFlight();
    Flight &getFlightRef(int num);

    void printAllFlights();

    /////////////////////////////////// HANDLE SERCICES ///////////////////////////////////////

    void addService();

    void checkService();

    void printAllServicesHistory();

    void LoadServices();

    void printAllServicesDue();

    void reserveSeat();

/////////////////////////////////// HANDLE PASSENGERS ///////////////////////////////////////

    void LoadPassengers();

    void ReservedSeats(int flightID, string firstName, string lastName, int seatNum, int clientID, bool baggage);

};

#endif //PROJETO_AIRLINE_H