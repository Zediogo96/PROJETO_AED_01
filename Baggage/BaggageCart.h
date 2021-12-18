#pragma once

#include <list>
#include "BaggageCarriage.h"
#include "Baggage.h"

using namespace std;

/**
 * @brief Class handling baggage carts, storing the baggage carriages attached to it. It sets each carriage's stack amount and maximum stack size.
 * 
 */
class BaggageCart {
    list<BaggageCarriage> carriages;
    int numCarriages;
    int carriage_stacks;
    int stack_size;
    int maxAmount;
    bool full;

public:
/**
 * @brief Constructs a new baggage cart with a specified number of carriages
 * 
 * @param c -> number of baggage carriages
 */
    BaggageCart(int c);
    /**
     * @brief Adds a baggage to a cart's carriage
     * 
     * @param baggage 
     */
    void addBaggage(Baggage baggage);
    /**
     * @brief Checks if all of the cart's carriages are full
     * 
     * @return bool
     */
    bool isFull();
    /**
     * @brief Removes all baggages from the cart's carriages
     * 
     */
    void clear();
    /**
     * @brief Returns the total amount of baggages in all of the cart's carriages
     * 
     * @return int 
     */
    int getAmount();
    /**
     * @brief Returns the maximum amount of baggages the cart can carry.
     * 
     * It's calculated by the amount of stacks times the stack size of each carriage times the number of carriages the cart has
     * 
     * @return int
     */
    int getMaxAmount();
    /**
     * @brief Removes and returns a baggage from the cart
     * 
     * @return Baggage -> Baggage object
     */
    Baggage retrieveBaggage();
    
};