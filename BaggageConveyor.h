#include <queue>
#include <vector>
#include "Baggage.h"

using namespace std;

class BaggageConveyor {
    queue<Baggage> conveyor;

public:
    void addBaggage(Baggage baggage);
    Baggage retrieveBaggage();
    int getSize();
};