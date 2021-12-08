//
// Created by zedio on 07/12/2021.
//

#ifndef PROJETO_SERVICE_H
#define PROJETO_SERVICE_H


class Service {

private:

    class Plane* plane;
    class Staff* responsible;
    class Date* created;
    class Date* completed;

public:

    Service(Plane &plane, Date* date, Staff &staff);
    void setResponsible(Staff* staff);
    void setComplete(Date* date);
    Staff* getResponsible();
};


#endif //PROJETO_SERVICE_H
