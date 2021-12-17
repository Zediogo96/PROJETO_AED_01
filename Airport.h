#pragma once
#include <string>
#include <vector>

#include "binaryTree.h"
#include "Transports/Transport.h"
#include "Baggage/BaggageCart.h"
#include "Baggage/BaggageConveyor.h"

class Plane;

class Airport {

    BST<Transport> transportTree;
    std::string name;
    string city;
    int id;
    BaggageConveyor conveyor;
    BaggageCart baggageCart = BaggageCart(2);

public:
    /** brief: default constructor for Airpot **/
    Airport();
    /**
     * Constructor
     * @param id (Airport ID)
     * @param name (Airport Name)
     * @param city (Airport City)
     */
    Airport(int id, string name, string city);

    // GETTERS
    const int& getID();
    const std::string& getName();
    const std::string& getCity();

    /** brief: method to load transports for this associated with this Airport **/
    void LoadTransports();
    /**
     * Outputs the available transports of type vehicle (input)
     * @param vehicle
     */
    void showAvailables(type vehicle) const;
    /**
     * Outputs the distance of the different vehicles to
     * @param vehicle
     */
    void showDistances(type vehicle) const;
    void showSchedules(type vehicle) const;

    int getCartLoad();
    int getCartMaxLoad();
    int getConveyorLoad();
    void addBaggageToConveyor(Baggage baggage);
    void emptyConveyor();
    void fillPlane(Plane& plane);

    string toString() const;
};
