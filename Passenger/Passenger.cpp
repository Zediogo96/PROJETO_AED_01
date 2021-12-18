//
// Created by zedio on 09/12/2021.
//

#include "Passenger.h"

Passenger::Passenger(const std::string& firstName, const std::string& lastName, int id)
{
    mfirstName = firstName;
    mlastName = lastName;
    mID = id;
}

void Passenger::SetPassengerFirstName(const std::string& firstName)
{
    mfirstName = firstName;
}
std::string Passenger::GetPassengerFirstName() const
{
    return mfirstName;
}
void Passenger::SetPassengerLastName(const std::string& lastName)
{
    mfirstName = lastName;
}
std::string Passenger::GetPassengerLastName() const
{
    return mlastName;
}

void Passenger::SetSeatNumber(int seatNumber)
{
    mSeatNumber = seatNumber;
}
int Passenger::GetSeatNumber() const
{
    return mSeatNumber;
}

void Passenger::SetPassengerID(int Id)
{
    mID = Id;
}
int Passenger::GetPassengerID() const
{
    return mID;
}

bool Passenger::includedBaggage() const {
    return includeBaggage;
}

void Passenger::setBaggageInclusion(bool state) {
    includeBaggage = state;
    if(includeBaggage)
        baggage = Baggage(GetPassengerID());
}

Baggage Passenger::getBaggage() {
    return baggage;
}