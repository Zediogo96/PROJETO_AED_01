#include <list>
#include "BaggageCarriage.h"


using namespace std;

class BaggageCart {
    list<BaggageCarriage> carriages;
    int numCarriages;

public:
    BaggageCart(int c);
    void addBaggage(Baggage baggage);
};