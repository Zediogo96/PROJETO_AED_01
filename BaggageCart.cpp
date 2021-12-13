#include "BaggageCart.h"

BaggageCart::BaggageCart(int c) {
    numCarriages = c;

    for(int i = 0; i < numCarriages; i++) {
        BaggageCarriage carriage = BaggageCarriage(3, 4);
        carriages.push_back(carriage);
    }
}

void BaggageCart::addBaggage(Baggage baggage) {

    for(BaggageCarriage carriage : carriages) {
        if(carriage.hasSpace())
            carriage.addBaggage(baggage);
    }
}