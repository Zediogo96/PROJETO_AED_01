//
// Created by zedio on 24/11/2021.
//

#ifndef PROJETO_UTILITY_H
#define PROJETO_UTILITY_H

#include <string>
#include <regex>

/**
 * Using Regular Expressions (Regex) to validate a number plate input
 * Example accepted formats: A340, B500, C731
 * @param string
 * @return boolean
 */
bool validatePlaneType(const std::string &s) {

    static const std::regex validType("([A-Z]([0-9]{3}))");

    return std::regex_match(s, validType);
}

#endif //PROJETO_UTILITY_H
