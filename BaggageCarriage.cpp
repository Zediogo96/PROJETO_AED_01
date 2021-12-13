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
    for (stack<Baggage> baggageStack : baggageStacks) {
        if (baggageStack.size() < stackSize)
            return true;
    }

    return false;
}

void BaggageCarriage::addBaggage(Baggage baggage) {
    for (stack<Baggage> baggageStack : baggageStacks) {
        if (baggageStack.size() < stackSize)
            baggageStack.push(baggage);
    }
}