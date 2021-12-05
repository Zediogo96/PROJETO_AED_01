//
// Created by zedio on 05/12/2021.
//

#ifndef PROJETO_SERVICE_H
#define PROJETO_SERVICE_H


#include "../Utility/Date.h"
#include "Staff.h"

enum class Type { cleaning = 1, maintenance  = 2};

class Service {

private:
    Type type;
    Date currentDate;
    Date completedDate;
    Staff responsible;
    bool completed;

public:
    Service(Type type, const Staff& responsible);
    void setResponsible(const Staff &staff);
    void setComplete();
    Staff getResponsible() const;
    Type getType() const;
};


#endif //PROJETO_SERVICE_H
