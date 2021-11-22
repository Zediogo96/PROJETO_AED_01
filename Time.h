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
    Time();
    Time(int hours, int minutes);


    /** @brief GETTERS for the Time Class */

    int getHours();
    int getMinutes();

    /** @brief SETTERS for the Time Class */

    void setHours(int h);
    void setMinutes(int m);

    /**
     * Method to override .equals(), to compare if two object of Time class are equals
     * @param otherTime
     * @return boolean
     */

    bool equals(Time &otherTime);

    void printTime();

    Time(Time *pTime);
};

#endif //PROJETO_TIME_H
