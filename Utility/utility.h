//
// Created by zedio on 24/11/2021.
//

#ifndef PROJETO_UTILITY_H
#define PROJETO_UTILITY_H

#include <string>
#include <regex>
#include <iostream>
#include <cstdlib>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/**
 * Using Regular Expressions (Regex) to validate a Plane Type input
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
 * Using Regular Expressions (Regex) to validate a Plane NumberPlate input
 * Example accepted formats: CS5000, CS7010, AP8401
 * @param string
 * @return boolean
 */
static bool validatePlaneNumber(const std::string &s) {

    static const std::regex validType("([A-Z]{2}([0-9]{4}))");

    if (std::regex_match(s, validType))
        return true;
    std::cout << "Invalid Plate Number format, must be for example 'CS2010'." << std::endl;
    return false;
}

/**
 * Using Regular Expressions (Regex) to validate a Date input
 * Example accepted formats: YYYY-MM-DD
 * @param string
 * @return true if the regex accepts the string, false otherwise
 */
static bool validateDate(const std::string &s) {
    static const std::regex validType(R"(^(19|20)\d\d([/ /.])(0[1-9]|1[012])\2(0[1-9]|[12][0-9]|3[01])$)");

    if (std::regex_match(s, validType))
        return true;
    std::cout << "Invalid date format, must be for example: 1996/12/19 (yyyy/mm/dd).";
    return false;
}

/**
 * Using Regular Expressions (Regex) to validate a TIME input
 * Example accepted formats: HH:MM (H -> hours , M -> minutes)
 * @param string
 * @return True if the regex accepts the string, False otherwise
 */
static bool validateTime(const std::string &s) {

    static const std::regex validType("([01]?[0-9]|2[0-3]):[0-5][0-9]");

    if (std::regex_match(s, validType))
        return true;
    std::cout << "Invalid time format, must be for example: 16:30.";
    return false;
}

/**
 * @brief: Validates the answer of some user Input
 * @param string
 * @return True in case the regular expression Valid Type accepts the input, else False
 */
static bool validateAnswer(const std::string &s) {
    static const std::regex validType("^(y|Y|n|N)$");

    if (std::regex_match(s, validType)) return true;
    std::cout << "Invalid Answer, must be Y / N.";
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

/** @brief Method that implements input in case of string text */
static void InputChar(char ch, std::string const &text) {
    do {
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << text << std::endl;
        std::cin >> ch;
    } while(!std::cin);
}

/** @brief Method that implements input in case of string text with spaces */
static void InputStr_withSpaces(std::string &str, std::string const &text) {
    do {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << text << std::endl;

    } while(!std::getline(std::cin, str));
}

/**
 * @param num Number the User will input
 * @param text Text Message associated with the input, describing what type of input it expects.
 */
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