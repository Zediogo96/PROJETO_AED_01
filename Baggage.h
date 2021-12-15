#pragma once

class Baggage {
    int passengerID;
    int flightID;

public:
    Baggage(int pid, int fid);
    int getPassengerID();
    int getFlightID();
};
