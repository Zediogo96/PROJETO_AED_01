//
// Created by zedio on 04/12/2021.
//

#ifndef PROJETO_SERVICE_H
#define PROJETO_SERVICE_H

#include <queue>
#include "../Plane.h"
#include "Staff.h"

class Service {

private:
    Plane plane;
    Staff responsible;
    Date date;
    bool status;

public:
    void setResponsible(const Staff& staff);
    void setComplete();
    Staff getResponsible();
};

#endif //PROJETO_SERVICE_H
