#pragma once
#include <string>
#include <vector>

#include "binaryTree.h"
#include "Transports/Transport.h"
#include "BaggageCart.h"
#include "BaggageConveyor.h"

class Plane;

class Airport {
    BST<Transport> transportTree;
    std::string name;
    int id;
    int numCarts;
    BaggageConveyor conveyor;
    BaggageCart baggageCart = BaggageCart(2);

public:
    Airport();
    Airport(int id, string name);
    const std::string& getName();
    const int& getID();
    
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
};