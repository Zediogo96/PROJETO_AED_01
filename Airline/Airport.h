#pragma once
#include <string>
#include <vector>

#include "../Utility/binaryTree.h"
#include "../Transports/Transport.h"
#include "../Baggage/BaggageCart.h"
#include "../Baggage/BaggageConveyor.h"

class Plane;

/**
 * @brief Class handling airports. Stores transports belonging to the airport, as well as the baggage system and other specific information
 * 
 */
class Airport {

    BST<Transport> transportTree;
    std::string name;
    string city;
    int id{};
    BaggageConveyor conveyor;
    BaggageCart baggageCart = BaggageCart(2);

public:
    /** @brief default constructor for Airpot **/
    Airport();
    /**
     * @brief Constructs an airport with specified information
     * @param id -> (Airport ID)
     * @param name -> (Airport Name)
     * @param city -> (Airport City)
     */
    Airport(int id, string name, string city);

    /**
     * @brief Returns the airport's unique identifier
     * 
     * @return const int& 
     */
    const int& getID() const;
    /**
     * @brief Returns the airport's name
     * 
     * @return const std::string& 
     */
    const std::string& getName();
    /**
     * @brief Returns the city the airport is located in
     * 
     * @return const std::string& 
     */
    const std::string& getCity();

    /** @brief Method to load transports associated with this Airport **/
    void LoadTransports();
    /**
     * @brief Outputs the available transports of type vehicle (input)
     * @param vehicle
     */
    void showAvailables(type vehicle) const;
    /**
     * @brief Outputs the distance of the different vehicles to the airport
     * @param vehicle
     */
    void showDistances(type vehicle) const;
    /**
     * @brief Outputs the schedules of all the transports associated with the airport
     * 
     * @param vehicle 
     */
    void showSchedules(type vehicle) const;
    /**
     * @brief Returns the baggage cart's current baggage load
     * 
     * @return int 
     */
    int getCartLoad();
    /**
     * @brief Returns the baggage cart's maximum baggage load
     * 
     * @return int 
     */
    int getCartMaxLoad();
    /**
     * @brief Returns the baggage conveyor's current baggage load
     * 
     * @return int 
     */
    int getConveyorLoad();
    /**
     * @brief Adds a baggage to the baggage conveyor
     * 
     * @param baggage 
     */
    void addBaggageToConveyor(Baggage baggage);
    /**
     * @brief Empties the baggage conveyor of all baggages
     * 
     */
    void emptyConveyor();

    /**
     * @brief Fills the plane passed as parameter with the passenger's baggages
     * 
     * @param plane 
     */
    void fillPlane(Plane& plane);

    /**
     * @brief Returns airport information as a custom formatted string
     * 
     * @return string 
     */
    string toString() const;
};
