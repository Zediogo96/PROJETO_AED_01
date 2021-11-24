//
// Created by zedio on 24/11/2021.
//

#ifndef PROJETO_UTILITY_H
#define PROJETO_UTILITY_H

#include <string>
#include <regex>
#include <iostream>

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

#endif //PROJETO_UTILITY_H