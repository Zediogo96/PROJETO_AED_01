//
// Created by zedio on 21/11/2021.
//

#ifndef PROJETO_AIRLINE_H
#define PROJETO_AIRLINE_H


#include <string>
#include <vector>
#include "Plane.h"

class Airline {
private:

    std::vector<Plane> planesList;

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

    /******************************************** HANDLE PLANES **************************** */

    void SavePlanes();
    void LoadPlanes();

    bool availablePlane(int planeID);
    int findPlane();
    void addPlane();
    void searchPlane();
    void editPlane();
    void printPlanes();
    void deletePlane();
    void clearPlanes();

};





#endif //PROJETO_AIRLINE_H
