//
// Created by zedio on 05/12/2021.
//

#ifndef PROJETO_STAFF_H
#define PROJETO_STAFF_H


#include <string>
#include <utility>

using namespace std;

class Staff {

private:
    std::string firstName;
    std::string lastName;

public:

    Staff() = default;

    Staff(string &firstName, string &lastName) {
        this->firstName = firstName;
        this->lastName = lastName;
    }

    /**
    * @brief Converts Staff into a string format to be output
    * @return string format of Staff
    **/
    std::string toString() {
        std::ostringstream oss;
        oss << firstName << " " << lastName;
        return oss.str();
    }
};


#endif //PROJETO_STAFF_H
