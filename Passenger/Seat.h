//
// Created by zedio on 16/12/2021.
//

#ifndef PROJETO_SEAT_H
#define PROJETO_SEAT_H


#include <iostream>
#include "Passenger.h"
/**
 * @brief Class handling seats
 * 
 */
class Seat {
private:
    int seatNum;
    int occupied;
public:
/**
 * @brief Default constructor
 * 
 */
    Seat() = default;
    /**
     * @brief Construct a new Seat object specifying a seat number
     * 
     * @param num -> seat number
     */
    explicit Seat(int num) {
        this->seatNum = num;
        occupied = false;
    }
    /**
     * @brief Method for checking if seat is already occupied
     * 
     * @return bool -> occupied
     */
    bool isTaken() const {
        return occupied;
    }
    /**
     * @brief Set 'occupied' to true
     * 
     */
    void setTaken() {
        occupied = true;
    }
    /**
     * @brief Returns the seat number stored in 'seatNum'
     * 
     * @return int -> seat number
     */
    int getSeatNum() const {
        return seatNum;
    }

};


#endif //PROJETO_SEAT_H
