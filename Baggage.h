#pragma once

class Baggage {
    int passengerID;
    int flightID;

public:
    Baggage();
    Baggage(int pid);
    int getPassengerID();
    int getFlightID();
};