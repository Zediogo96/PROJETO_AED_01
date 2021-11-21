//
// Created by zedio on 21/11/2021.
//

#ifndef PROJETO_AIRLINE_H
#define PROJETO_AIRLINE_H


#include <string>

class Airline {
private:

    /*static const int MAX_NUM_OF_PASSENGERS = 100;*/

    int maxNumOfFlights;
    int currentNumOfFlights;
    std::string name;

    /* LinkedList<Flight> flights;
    vector<Passenger*> passengers;
    vector<Employee*> employees; */

    Airline(const std::string &name, int maxNumOfFlights);

    static Airline *airline;

public:
    /** Safer way to create an instance */
    static Airline &getInstance(const std::string &name, int maxNumOfFlights);

    /** @brief Destructor */
    ~Airline();

    /** @brief Singletons should not be cloneable. */
    Airline(const Airline &other) = delete;

    /** @brief Singletons should not be assignable, hence overload it's = operator. */
    const Airline &operator=(const Airline &other) = delete;

    /** @brief GETTERS for fields of Airline Class */
    const std::string& getName();
    int getMaxNumOfFlights();
    int getCurrentNumOfFlights();

};


#endif //PROJETO_AIRLINE_H
