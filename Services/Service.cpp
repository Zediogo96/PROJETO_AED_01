//
// Created by zedio on 07/12/2021.
//

#include "Service.h"

Service::Service(Plane &plane, Date* date, Staff &staff) {
    this->plane = &plane;
    this->responsible = &staff;
    created = date;
}

Staff* Service::getResponsible() {
    return responsible;
}

void Service::setComplete(Date *date) {
    this->completed = date;
}

void Service::setResponsible(Staff *staff) {
    this->responsible = staff;
}