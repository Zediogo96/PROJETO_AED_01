//
// Created by zedio on 04/12/2021.
//

#ifndef PROJETO_STAFF_H
#define PROJETO_STAFF_H

#include <string>
#include <list>
#include <utility>
#include "Service.h"


class Staff {

private:

    std::string name;
    std::vector<class Service> history{};

public:

    explicit Staff(std::string name_) {
        this->name = std::move(name_);
    }

    void addHistory (class Service &service) {
        this->history.push_back(service);
    }

    std::string getName() {
        return name;
    }

    std::vector<Service> getHistory() {
        return history;
    }
};

#endif //PROJETO_STAFF_H
