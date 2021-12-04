//
// Created by zedio on 24/11/2021.
//

#ifndef PROJETO_UTILITY_H
#define PROJETO_UTILITY_H

#include <string>
#include <regex>
#include <iostream>

#include "Date.h"
#include "Time.h"

/**
 * Using Regular Expressions (Regex) to validate a number plate input
 * Example accepted formats: A340, B500, C731
 * @param string
 * @return boolean
 */
static bool validatePlaneType(const std::string &s) {

    static const std::regex validType("([A-Z]([0-9]{3}))");

    if (std::regex_match(s, validType))
        return true;
    std::cout << "Invalid type format, must be for example 'A750'." << std::endl;
    return false;
}

/**
 * Using Regular Expressions (Regex) to validate a Date input
 * Example accepted formats: YYYY-MM-DD
 * @param string
 * @return boolean
 */
static bool validateDate(const std::string &s) {
    static const std::regex validType(R"(^(19|20)\d\d([- /.])(0[1-9]|1[012])\2(0[1-9]|[12][0-9]|3[01])$)");

    if (std::regex_match(s, validType))
        return true;
    std::cout << "Invalid date format, must be for example: 2021-12-03.";
    return false;
}

/**
 * Using Regular Expressions (Regex) to validate a TIME input
 * Example accepted formats: HH:MM (H -> hours , M -> minutes)
 * @param string
 * @return boolean
 */
static bool validateTime(const std::string &s) {

    static const std::regex validType("([01]?[0-9]|2[0-3]):[0-5][0-9]");

    if (std::regex_match(s, validType))
        return true;
    std::cout << "Invalid time format, must be for example: 16:30.";
    return false;
}

/** @brief Method that implements input in case of string text */
static void InputStr(std::string &str, std::string const &text) {
    do {
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << text << std::endl;
        std::cin >> str;
    } while(!std::cin);
}

static void InputInt(int &num, const std::string &text) {
    do {
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << text << std::endl;
        std::cin >> num;
    } while(!std::cin);
}

static Time InputTime(Time &time, const std::string &text)
{
    int h, m;

    std::cin >> h; // read the hours

    if ( std::cin.get() != ':' ) // make sure there is a slash between DD and MM
    {
        std::cout << "expected : in between Year and Month. \n";
    }
    std::cin >> m; // read the month

    time.setHours(h);
    time.setMinutes(m);

    return time;
}

#endif //PROJETO_UTILITY_H