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
    Date() {
        year, month, day = 0;
    }

    Date(int year_, int month_, int day_) {
        year = year_;
        month = month_;
        day = day_;
    }

    /** @brief GETTERS for the Date Class */

    int getYear() const {
        return year;
    }

    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }

    /** @brief SETTERS for the Date Class */

    void setYear(int y) {
        if (y > 0)
            year = y;
        else {
            std::cout << "Invalid Year" << std::endl;
        }
    }

    void setMonth(int m){
        if (m > 0 && m < 13)
            month = m;
        else {
            std::cout << "Invalid Month" << std::endl;
        }
    }

    void setDay(int d) {
        if ((month = 1) || (month = 3) || (month = 5) || (month = 7) ||
            (month = 8) || (month = 10) || (month = 12)) {
            if (day > 0 && day <= 31) {
                day = d;
            }
        }

        else if ((month = 4) || (month = 6) || (month = 9) || (month = 11))
        {
            if (day > 0 && day <= 30) {
                day = d;
            }
        }
    }

    /**
     * Method to override .equals(), to compare if two object of Time class are equals
     * @param otherTime
     * @return boolean
     */
    bool equals(Date &otherDate) {
        if (year == otherDate.year && month == otherDate.month && day == otherDate.day)
            return true;

        return false;
    }

    void printDate() {
        std::cout << std::setw(4) << std::setfill('0') << year << "/"
                  << std::setw(2) << std::setfill('0') << month << "/"
                  << std::setw(2) << std::setfill('0') << day << std::endl;
    }
};











#endif //PROJETO_DATE_H
