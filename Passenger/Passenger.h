//
// Created by zedio on 09/12/2021.
//

#ifndef PROJETO_PASSENGER_H
#define PROJETO_PASSENGER_H

#include <string>
#include "../Baggage/Baggage.h"
/**
 * @brief Class handling passengers and all data related to them
 * 
 */
class Passenger
	{
	public:
	/**
	 * @brief Default constructor
	 * 
	 */
		Passenger() = default;
		/**
		 * @brief Construct a new Passenger object with a first and last name and a unique id
		 * 
		 * @param firstName 
		 * @param lastName 
		 * @param id 
		 */
		Passenger(const std::string& firstName, const std::string& lastName, int id);
		/**
		 * @brief Sets the passenger's first name as the name passed as a parameter
		 * 
		 * @param firstName
		 */
		void SetPassengerFirstName(const std::string& firstName);
		/**
		 * @brief Returns the passenger's first name
		 * 
		 * @return string
		 */
		std::string GetPassengerFirstName() const;
		/**
		 * @brief Sets the passenger's last name as the name passed as a parameter
		 * 
		 * @param lastName
		 */
		void SetPassengerLastName(const std::string& lastName);
		/**
		 * @brief Returns the passenger's last name
		 * 
		 * @return string 
		 */
		std::string GetPassengerLastName() const;
		/**
		 * @brief Sets the passenger's id
		 * 
		 * @param Id 
		 */
		void SetPassengerID(int Id);
		/**
		 * @brief Returns the passenger's id
		 * 
		 * @return int 
		 */
		int GetPassengerID() const;
		/**
		 * @brief Sets the passenger's seat number as the number passed as a parameter
		 * 
		 * @param seatNumber 
		 */
		void SetSeatNumber(int seatNumber);
		/**
		 * @brief Returns the passenger's seat number
		 * 
		 * @return int 
		 */
		int GetSeatNumber() const;
		/**
		 * @brief Sets whether the passenger wants to include a baggage or not
		 * 
		 * @param state 
		 */
		void setBaggageInclusion(bool state);

		bool includedBaggage() const;

		/**
		 * @brief Checks if the passenger has chosen to include baggage
		 * 
		 * @return bool -> includeBaggage
		 */
		bool includedBaggage();
		/**
		 * @brief Retrieves the passenger's baggage
		 * 
		 * @return Baggage -> a Baggage object
		 */

		Baggage getBaggage();
	private:
		std::string mfirstName;
		std::string mlastName;
		int mSeatNumber=-1;
		int mID=-1;
		bool includeBaggage{};
		Baggage baggage;
	};


#endif //PROJETO_PASSENGER_H
