//
// Created by zedio on 22/11/2021.
//

#include "Date.h"

Date::Date() {
    year, month, day = 0;
}

Date::Date(int year_, int month_, int day_) {
    year = year_;
    month = month_;
    day = day_;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

void Date::setYear(int y) {
    if (y >= 0)
        year = y;
    else {
        std::cout << "Invalid Year" << std::endl;
    }
}

void Date::setMonth(int m){
    if (m >= 1 && m <= 12)
        month = m;
    else {
        std::cout << "Invalid Month" << std::endl;
    }
}

void Date::setDay(int d) {
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

bool Date::equals(Date &otherDate) {
    if (year == otherDate.year && month == otherDate.month && day == otherDate.day)
        return true;

    return false;
}

void Date::printDate() {
    std::cout << std::setw(4) << std::setfill('0') << year << "/"
              << std::setw(2) << std::setfill('0') << month << "/"
              << std::setw(2) << std::setfill('0') << day << std::endl;
}