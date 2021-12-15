#include "BaggageConveyor.h"

void BaggageConveyor::addBaggage(Baggage baggage) {
    conveyor.push(baggage);
}

Baggage BaggageConveyor::retrieveBaggage() {
    Baggage baggage = conveyor.front(); 
    conveyor.pop();

    return baggage;
}

int BaggageConveyor::getSize() {
    return conveyor.size();
}