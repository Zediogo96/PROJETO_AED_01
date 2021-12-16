#pragma once

#include <list>
#include "BaggageCarriage.h"
#include "Baggage.h"

using namespace std;

class BaggageCart {
    list<BaggageCarriage> carriages;
    int numCarriages;
    int carriage_stacks;
    int stack_size;
    int maxAmount;
    bool full;

public:
    BaggageCart(int c);
    void addBaggage(Baggage baggage);
    bool isFull();
    void clear();
    int getAmount();
    int getMaxAmount();
    Baggage retrieveBaggage();
    
};