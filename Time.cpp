//
// Created by zedio on 21/11/2021.
//

#include "Time.h"

Time::Time() {
    hours, minutes = 0;
};

Time::Time(int hours, int minutes): hours(hours), minutes(minutes) {};

int Time::getHours() {
    return hours;
}

int Time::getMinutes() {
    return minutes;
}

void Time::setHours(int h) {

    if (h >= 0 && h <= 24)
        this->hours = h;

    std::cout << "Invalid input value for the hours parameter" << std::endl;
}

void Time::setMinutes(int m){

    if (m >= 0 && m <= 60)
        this->minutes = m;

    std::cout << "Invalid input value for the minutes parameter" << std::endl;
}

bool Time::equals(Time &otherTime) {
    if (hours == otherTime.hours && minutes == otherTime.minutes)
        return true;

    return false;
}

void Time::printTime() {
    std::cout << std::setw(2) << std::setfill('0') << hours << ":"
              << std::setw(2) << std::setfill('0') << minutes << "\n";
}