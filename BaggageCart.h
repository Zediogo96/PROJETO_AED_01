#include <list>
#include "BaggageCarriage.h"


using namespace std;

class BaggageCart {
    list<BaggageCarriage> carriages;
    int numCarriages;
    bool full;

public:
    BaggageCart(int c);
    void addBaggage(Baggage baggage);
    bool isFull();
    void empty();
};