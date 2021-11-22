//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_DATE_H
#define PROJETO_DATE_H

#include <iostream>
#include <iomanip>

class Date {
private:
    int year, month, day;
public:

    /** @brief Constructors for Date Class */
    Date();
    Date(int year, int month, int day);

    /** @brief GETTERS for the Date Class */

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    /** @brief SETTERS for the Date Class */

    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);

    /**
     * Method to override .equals(), to compare if two object of Time class are equals
     * @param otherTime
     * @return boolean
     */

    bool equals(Date &otherDate);

    void printDate();
};

#endif //PROJETO_DATE_H
