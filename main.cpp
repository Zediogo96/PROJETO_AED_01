#include <iostream>

#include "Time.h"

int main() {

    Time t1(10, 20);
    Time t2;


    t2.setHours(10);
    t2.setMinutes(20);

    std::cout << t1.equals(t2);

    return 0;
}
