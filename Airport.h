//
// Created by zedio on 16/12/2021.
//

#ifndef PROJETO_AIRPORT_H
#define PROJETO_AIRPORT_H


#pragma once
#include <string>

#include "Transports/binaryTree.h"
#include "Transports/Transport.h"
#include "Baggage/BaggageCart.h"
#include "Baggage/BaggageConveyor.h"


class Airline;

class Airport {
    BST<Transport> transportTree;
    Airline *airline;
    std::string name;
    string city;
    int id;
    int numCarts;
    BaggageConveyor conveyor;
    BaggageCart baggageCart = BaggageCart(2);

public:
    Airport();
    Airport(int id, string name, string city,Airline *airline);
    const std::string& getName();
    const int& getID() const;

    void LoadTransports();
    void showAvailables(type vehicle);
    void showDistances(type vehicle);
    void showSchedules(type vehicle);

    void reserveSeat();

    void addBaggageToConveyor(Baggage baggage);
    void emptyConveyor();
    void fillPlane();

    const string &getCity();
};


#endif //PROJETO_AIRPORT_H
