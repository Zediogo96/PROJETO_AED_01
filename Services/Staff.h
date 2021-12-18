//
// Created by zedio on 05/12/2021.
//

#ifndef PROJETO_STAFF_H
#define PROJETO_STAFF_H


#include <string>
#include <utility>

using namespace std;

/**
 * @brief Class handling staff responsible for performing services
 * 
 */
class Staff {
private:
    std::string firstName;
    std::string lastName;

public:
    /**
     * @brief Default constructor
     * 
     */
    Staff() = default;
    /**
     * @brief Constructs a new Staff object with a first and last name
     * 
     * @param firstName 
     * @param lastName 
     */
    Staff(string &firstName, string &lastName) {
        this->firstName = firstName;
        this->lastName = lastName;
    }
    /**
     * @brief Returns the first and last name of the staff as a custom formatted string
     * 
     * @return std::string 
     */
    std::string toString() {
        std::ostringstream oss;
        oss << firstName << " " << lastName;
        return oss.str();
    }
};


#endif //PROJETO_STAFF_H
