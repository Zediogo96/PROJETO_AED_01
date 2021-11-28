//
// Created by zedio on 21/11/2021.
//

#ifndef PROJETO_TIME_H
#define PROJETO_TIME_H


#include <iostream>
#include <iomanip>

class Time {
private:
    int hours, minutes;
public:

    /** @brief Constructors for Time Class */
    Time() {
        hours, minutes = 0;
    };

    Time(int hours, int minutes) {
        hours = hours;
        minutes = minutes;
    };

    /** @brief GETTERS for the Time Class */
    int getHours() {
        return hours;
    }

    int getMinutes() {
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
    * @return boolearn
    */
    bool equals(Time &otherTime) {
        if (hours == otherTime.hours && minutes == otherTime.minutes)
            return true;

        return false;
    }

    /** @brief Prints attributes associated with the Time object to the screen */
    void printTime() {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << "\n";
    }
};

#endif //PROJETO_TIME_H
