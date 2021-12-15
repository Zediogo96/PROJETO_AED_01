#include "BaggageCarriage.h"

BaggageCarriage::BaggageCarriage(int n, int m) {
    stackAmount = n;
    stackSize = m;

    for(int i = 0; i < stackAmount; i++) {
        stack<Baggage> baggageStack;
        baggageStacks.push_back(baggageStack);
    }
}

bool BaggageCarriage::hasSpace() {
    for (list<stack<Baggage>>::iterator itr = baggageStacks.begin(); itr != baggageStacks.end(); itr++) {
        if (itr->size() < stackSize)
            return true;
    }

    return false;
}

void BaggageCarriage::addBaggage(Baggage baggage) {
    for (auto itr = baggageStacks.begin(); itr != baggageStacks.end(); itr++) {
        if (itr->size() < stackSize) {
            itr->push(baggage);
            return;
        }
    }
}

void BaggageCarriage::empty() {
    for(list<stack<Baggage>>::iterator itr = baggageStacks.begin(); itr != baggageStacks.end(); itr++) {
        while(itr->size() > 0)
            itr->pop();
    }
}

int BaggageCarriage::getSize() {
    int size = 0;
    for(list<stack<Baggage>>::iterator itr = baggageStacks.begin(); itr != baggageStacks.end(); itr++) {
        size += itr->size();
    }

    return size;
}