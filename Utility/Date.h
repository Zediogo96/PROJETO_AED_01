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
        year = 0, month = 0, day = 0;
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
        year = y;
    }

    void setMonth(int m) {
        month = m;
    }

    void setDay(int d) {
        day = d;
    }

    /**
     * Method to override .equals(), to compare if two object of Time class are equals
     * @param otherTime
     * @return boolean
     */
    bool equals(Date &otherDate) const {
        if (year == otherDate.year && month == otherDate.month && day == otherDate.day)
            return true;

        return false;
    }

    void printDate() const {
        std::cout << std::setw(4) << std::setfill('0') << year << "/"
                  << std::setw(2) << std::setfill('0') << month << "/"
                  << std::setw(2) << std::setfill('0') << day << std::endl;
    }

    /**
    * Calculates today's Date based on current system, and updates current Date object with those values
    */
    void now() {
        // Current Date/Time based on current System
        time_t now = time(0);

        tm *ltm = localtime(&now);

        setYear(1900 + ltm->tm_year);
        setMonth(1 + ltm->tm_mon);
        setDay(ltm->tm_mday);

    }


    std::string toString() const {
        std::ostringstream oss;
        oss << year << "/" << std::setfill('0') << std::setw(2) << month << "/"
            << std::setfill('0') << std::setw(2) << day;
        return oss.str();
    }

    bool operator < (const Date &b) const {
        if (year == b.year) {
            if (month == b.month) {
                return day < b.day;
            }
            return month < b.month;
        }
        return year < b.year;
    }


};

#endif //PROJETO_DATE_H