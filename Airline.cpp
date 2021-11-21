//
// Created by zedio on 21/11/2021.
//
#include "Airline.h"

Airline* Airline::airline = nullptr;

Airline::Airline(const std::string& name, int maxNumOfFlights): name(name), maxNumOfFlights(maxNumOfFlights) {}

Airline& Airline::getInstance(const std::string &name, int maxNumOfFlights) {
    if (airline == nullptr) {
        airline = new Airline(name, maxNumOfFlights);
    }
    return *airline;
}

Airline::~Airline() {
    delete airline;
}

const std::string& Airline::getName() {
    return name;
}

int Airline::getMaxNumOfFlights() {
    return maxNumOfFlights;
}

int Airline::getCurrentNumOfFlights() {
    return currentNumOfFlights;
}
