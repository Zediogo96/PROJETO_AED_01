#include "BaggageCart.h"

BaggageCart::BaggageCart(int c) {
    numCarriages = c;
    carriage_stacks = 3;
    stack_size = 4;
    maxAmount = carriage_stacks * stack_size;

    for(int i = 0; i < numCarriages; i++) {
        BaggageCarriage carriage = BaggageCarriage(carriage_stacks, stack_size);
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

void BaggageCart::clear() {
    for(list<BaggageCarriage>::iterator itr = carriages.begin(); itr != carriages.end(); itr++) {
        itr->clear();
    }

    full = false;
}

int BaggageCart::getAmount() {
    int size = 0;

    for(list<BaggageCarriage>::iterator itr = carriages.begin(); itr != carriages.end(); itr++) {
        size += itr->getAmount();
    }

    return size;
}

int BaggageCart::getMaxAmount() {
    return maxAmount;
}

Baggage BaggageCart::retrieveBaggage() {
    for(list<BaggageCarriage>::iterator itr = carriages.begin(); itr != carriages.end(); itr++) {
        if(itr->getAmount() > 0)
            return itr->retrieveBaggage();
    }
}