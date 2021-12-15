#include "Baggage.h"

Baggage::Baggage(int pid, int fid) : passengerID(pid), flightID(fid) 
{}

int Baggage::getPassengerID() {
    return passengerID;
}

int Baggage::getFlightID() {
    return flightID;
}