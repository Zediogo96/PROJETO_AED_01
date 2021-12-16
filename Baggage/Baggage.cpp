#include "Baggage.h"

Baggage::Baggage() {};

Baggage::Baggage(int pid) : passengerID(pid)
{}

int Baggage::getPassengerID() {
    return passengerID;
}
