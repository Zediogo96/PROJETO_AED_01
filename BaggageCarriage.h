#pragma once

#include <stack>
#include <list>
#include "Baggage.h"

using namespace std;

class BaggageCarriage {
    list<stack<Baggage>> baggageStacks;
    int stackSize;
    int stackAmount;

public:
    BaggageCarriage(int n, int m);
    bool hasSpace();
    void addBaggage(Baggage baggage);
    void clear();
    int getAmount();
    Baggage retrieveBaggage();
};