//
// Created by zedio on 16/12/2021.
//

#ifndef PROJETO_AIRPORT_H
#define PROJETO_AIRPORT_H


#pragma once
#include <string>

#include "binaryTree.h"
#include "Transports/Transport.h"
#include "BaggageCart.h"
#include "BaggageConveyor.h"


class Airline;

class Airport {
    BST<Transport> transportTree;
    Airline *airline;
    std::string name;
    int id;
    int numCarts;
    BaggageConveyor conveyor;
    BaggageCart baggageCart = BaggageCart(2);

public:
    Airport();
    Airport(int id, string name, Airline *airline);
    const std::string& getName();
    const int& getID();

    void LoadTransports();
    void showAvailables(type vehicle);
    void showDistances(type vehicle);
    void showSchedules(type vehicle);

    void reserveSeat();

    void addBaggageToConveyor(Baggage baggage);
    void emptyConveyor();
    void fillPlane();
};


#endif //PROJETO_AIRPORT_H
