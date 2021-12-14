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

    for(list<BaggageCarriage>::iterator itr = carriages.begin(); itr != carriages.end(); itr++) {
        if(itr->hasSpace()) {
            itr->addBaggage(baggage);
            return;
        }
    }
}

bool BaggageCart::isFull() {
    full = true;

    for(list<BaggageCarriage>::iterator itr = carriages.begin(); itr != carriages.end(); itr++) {
        if(itr->hasSpace())
            full = false;
    }

    return full;
}

void BaggageCart::empty() {
    for(list<BaggageCarriage>::iterator itr = carriages.begin(); itr != carriages.end(); itr++) {
        itr->empty();
    }

    full = false;
}

int BaggageCart::getSize() {
    int size = 0;

    for(list<BaggageCarriage>::iterator itr = carriages.begin(); itr != carriages.end(); itr++) {
        size += itr->getSize();
    }

    return size;
}