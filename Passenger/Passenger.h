//
// Created by zedio on 09/12/2021.
//

#ifndef PROJETO_PASSENGER_H
#define PROJETO_PASSENGER_H

#include <string>

class Passenger
	{
	public:
		Passenger() = default;
		Passenger(const std::string& firstName, const std::string& lastName, int id);
		void SetPassengerFirstName(const std::string& firstName);
		std::string GetPassengerFirstName() const;
		void SetPassengerLastName(const std::string& lastName);
		std::string GetPassengerLastName() const;
		void SetPassengerID(int Id);
		int GetPassengerID() const;
		void SetSeatNumber(int seatNumber);
		int GetSeatNumber() const;

	private:
		std::string mfirstName;
		std::string mlastName;
		int mSeatNumber=-1;
		int mID=-1;
	};


#endif //PROJETO_PASSENGER_H