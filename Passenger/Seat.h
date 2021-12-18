//
// Created by zedio on 16/12/2021.
//

#ifndef PROJETO_SEAT_H
#define PROJETO_SEAT_H


#include <iostream>
#include "Passenger.h"

class Seat {
private:
    int seatNum;
    int occupied;
public:
    Seat() = default;
    explicit Seat(int num) {
        this->seatNum = num;
        occupied = false;
    }
    bool isTaken() const {
        return occupied;
    }
    /** brief: **/
    void setTaken() {
        occupied = true;
    }
    int getSeatNum() const {
        return seatNum;
    }

};


#endif //PROJETO_SEAT_H
