#include "Baggage.h"

Baggage::Baggage(int id) : passengerID(id) 
{}

int Baggage::getPassengerID() {
    return passengerID;
}