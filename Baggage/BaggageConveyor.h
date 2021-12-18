#pragma once

#include <queue>
#include <vector>
#include "Baggage.h"

using namespace std;
/**
 * @brief Class handling a baggage conveyor. Implements a queue system to store baggages
 * 
 */
class BaggageConveyor {
    queue<Baggage> conveyor;

public:
    /**
     * @brief Adds a baggage to the conveyor's queue
     * 
     * @param baggage 
     */
    void addBaggage(Baggage baggage);
    /**
     * @brief Removes and returns the first baggage in the conveyor's queue
     * 
     * @return Baggage 
     */
    Baggage retrieveBaggage();
    /**
     * @brief Returns the amount of baggages in the conveyor
     * 
     * @return int 
     */
    int getAmount();
    /**
     * @brief Checks whether the conveyor has any baggages
     * 
     * @return bool
     */
    bool isEmpty();
};