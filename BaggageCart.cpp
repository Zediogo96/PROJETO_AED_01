#include "BaggageCart.h"

BaggageCart::BaggageCart(int c) {
    numCarriages = c;

    for(int i = 0; i < numCarriages; i++) {
        BaggageCarriage carriage = BaggageCarriage(3, 4);
        carriages.push_back(carriage);
    }

    full = false;
}

void BaggageCart::addBaggage(Baggage baggage) {

    for(BaggageCarriage carriage : carriages) {
        if(carriage.hasSpace())
            carriage.addBaggage(baggage);
    }
}

bool BaggageCart::isFull() {
    full = true;

    for(BaggageCarriage carriage : carriages) {
        if(carriage.hasSpace())
            full = false;
    }

    return full;
}

void BaggageCart::empty() {
    for(BaggageCarriage carriage : carriages) {
        carriage.empty();
    }

    full = false;
}