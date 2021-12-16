#pragma once

class Baggage {
    int passengerID;
    int flightID;

public:
    Baggage();
    Baggage(int pid, int fid);
    int getPassengerID();
    int getFlightID();
};
