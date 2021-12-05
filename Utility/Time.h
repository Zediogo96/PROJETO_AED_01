//
// Created by zedio on 21/11/2021.
//

#ifndef PROJETO_TIME_H
#define PROJETO_TIME_H


#include <iostream>
#include <iomanip>
#include <ctime>

class Time {
private:
    int hours, minutes;
public:

    /** @brief Constructors for Time Class */
    Time() {
        hours = 0;
        minutes = 0;
    };

    Time(int hours_, int minutes_) {
        hours = hours_;
        minutes = minutes_;
    };

    /** @brief GETTERS for the Time Class */
    int getHours() const {
        return hours;
    }

    int getMinutes() const {
        return minutes;
    }

    /** @brief SETTERS for the Time Class */
    void setHours(int h) {

        if (h >= 0 && h <= 24)
            hours = h;

        std::cout << "Invalid input value for the hours parameter" << std::endl;
    }

    void setMinutes(int m){

        if (m >= 0 && m <= 60)
            minutes = m;

        std::cout << "Invalid input value for the minutes parameter" << std::endl;
    }

    /**
    * Compares the Time Object we are using to another Time Object, returning True
    * if they are equal and False if they're not.
    * @param Time object to compare
    * @return boolean
    */
    bool equals(Time &otherTime) const {
        if (hours == otherTime.hours && minutes == otherTime.minutes)
            return true;

        return false;
    }

    /** @brief Prints attributes associated with the Time object to the screen */
    void printTime() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << "\n";
    }
};
#endif //PROJETO_TIME_H
