//
// Created by zedio on 05/12/2021.
//

#include "Service.h"

Service::Service(Type type, const Staff& responsible) {
    this->type = type;
    this->currentDate.now();
    this->responsible = responsible;
    this->completed = false;
}

void Service::setResponsible(const Staff& staff) {
    responsible = staff;
}

void Service::setComplete() {
    completed = true;
    completedDate.now();
}

Staff Service::getResponsible() const {
    return responsible;
}

Type Service::getType() const {
    return type;
}
