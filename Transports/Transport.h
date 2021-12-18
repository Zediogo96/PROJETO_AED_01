//
// Created by Anibal on 13/12/2021.
//
#include<string>
#include "../Utility/Time.h"
#include<vector>
#ifndef PROJETO_TRANSPORT_H
#define PROJETO_TRANSPORT_H

using namespace std;
/**
 * @brief An enum class to differentiate types of transports
 * 
 */
enum class type {SUBWAY,BUS,TRAIN};
/**
 * @brief A class handling transports.
 * 
 *  Stores information regarding their schedule, airport they belong to, along with their distance from it
 * 
 */
class Transport {
private:
        type transporttype;
        int transportid;
        int airportid;
        int distance;
        vector<Time> schedule;
public:
/**
 * @brief Construct a new Transport object
 * 
 * @param t -> transport type
 * @param id -> transport's unique identifier
 * @param airportid -> identifier of the airport the transport belongs to
 * @param distance -> transport distance to its respective airport
 * @param schedule -> transport's schedule
 */
    Transport(type t, int id, int airportid , int distance, vector<Time> schedule);
    /**
     * @brief Adds a new time to the transport's schedule
     * 
     * @param time 
     */
    void addTime(Time time);
    /**
     * @brief Prints the transport's schedule
     * 
     */
    void printSchedule() const;
    /**
     * @brief Returns the type of the transport
     * 
     * @return type
     */
    type getType() const;
    /**
     * @brief Returns the transport's id
     * 
     * @return int 
     */
    int getId() const;
    /**
     * @brief Returns the airport's id that the transport belongs to
     * 
     * @return int 
     */
    int getAirportId() const;
    /**
     * @brief Returns the transport's distance to their respective airport
     * 
     * @return int 
     */
    int getDistance() const;
    /**
     * @brief Returns the transport's schedule
     * 
     * @return vector<Time> 
     */
    vector<Time> getSchedule() const;
    /**
     * @brief Operator '<' overload allowing for sorting and comparison of transports
     * 
     * @param T1 -> Transport object to compare
     * 
     * @return bool
     */
    bool operator < (const Transport& T1) const;
    /**
     * @brief Operator '==' overload to allow equality checking between transports
     * 
     * @param T1 -> Transport object to compare
     * 
     * @return bool
     */
    bool operator == (const Transport& T1) const;
};


#endif //PROJETO_TRANSPORT_H
