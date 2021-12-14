//
// Created by zedio on 05/12/2021.
//

#ifndef PROJETO_STAFF_H
#define PROJETO_STAFF_H


#include <string>
#include <utility>
#include "Service.h"

class Staff {
private:
    std::string firstName;
    std::string lastName;

public:

    Staff(std::string firstName, std::string lastName) {
        this->firstName = std::move(firstName);
        this->lastName = std::move(lastName);
    }

    std::string toString() {
        std::ostringstream oss;
        oss << firstName << " " << lastName;
        return oss.str();
    }
};




#endif //PROJETO_STAFF_H
