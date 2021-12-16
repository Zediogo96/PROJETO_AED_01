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
    int numCarts;
    BaggageConveyor conveyor;
    BaggageCart baggageCart = BaggageCart(2);

public:
    Airport();
    Airport(int id, string name, string city);
    const int& getID();
    const std::string& getName();
    const std::string& getCity();


    
    void LoadTransports();
    void showAvailables(type vehicle) const;
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
