//
// Created by zedio on 21/11/2021.
//

#ifndef PROJETO_TIME_H
#define PROJETO_TIME_H


#include <iostream>
#include <iomanip>
#include <ctime>

/**
 * @brief Time class for storing and comparing time type values
 * 
 */
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

    /**
     * @brief: Converts this Time into a string format to be output
     * @return string format of Time
     */
    std::string toString() const
    {
        std::ostringstream oss;
        oss << std::setfill('0')  << std::setw(2) << hours << ":" << std::setfill('0')
        << std::setw(2)<< minutes;
        return oss.str();
    }

    /** brief: overload of operator < to be used while comparing two given Times **/
    bool operator < (const Time &b) const {
        if (hours == b.hours) {
            return minutes < b.minutes;
        }
        return hours < b.hours;
    }
};
#endif //PROJETO_TIME_H
