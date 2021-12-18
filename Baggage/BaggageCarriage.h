#pragma once

#include <stack>
#include <list>
#include "Baggage.h"

using namespace std;
/**
 * @brief Class handling baggage carriages, storing the amount of stacks of baggages they have and the maximum size of each stack
 * 
 */
class BaggageCarriage {
    list<stack<Baggage>> baggageStacks;
    int stackSize;
    int stackAmount;

public:
/**
 * @brief Constructs a new carriage with a number of baggage stacks and each stack's maximum size
 * 
 * @param n -> amount of stacks
 * @param m  -> stack's maximum size
 */
    BaggageCarriage(int n, int m);
    /**
     * @brief Returns whether the carriage still has space to carry more baggages
     * 
     * @return bool
     */
    bool hasSpace();
    /**
     * @brief Adds a baggage to the carriage
     * 
     * @param baggage 
     */
    void addBaggage(Baggage baggage);
    /**
     * @brief Empties all the baggages in the carriage
     * 
     */
    void clear();
    /**
     * @brief Returns the current amount of baggages the carriage is carrying
     * 
     * @return int 
     */
    int getAmount();
    /**
     * @brief Removes and returns a baggage from the carriage
     * 
     * The order is from the first stack to the last stack.
     * 
     * @return Baggage -> Baggage object
     */
    Baggage retrieveBaggage();
};