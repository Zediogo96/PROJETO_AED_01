//
// Created by zedio on 04/12/2021.
//

#include "Service.h"

void Service::setResponsible(const Staff& staff_responsible) {
    responsible = staff_responsible;
}

void Service::setComplete() {
    status = true;
}

Staff Service::getResponsible() {
    return responsible;
}