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
    * Compares the Time Object we are using to another Time Object, returning True
    * if they are equal and False if they're not.
    * @param Time object to compare
    * @return boolearn
    */
    bool equals(Time &otherTime);

    /** @brief Prints attributes associated with the Time object to the screen */
    void printTime();
};

#endif //PROJETO_TIME_H
