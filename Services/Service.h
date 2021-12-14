//
// Created by zedio on 07/12/2021.
//

#ifndef PROJETO_SERVICE_H
#define PROJETO_SERVICE_H


#include "../Utility/Date.h"


class Service {

private:
    int planeID{};
    int serviceID{};
    class Staff* responsible{};
    class Date created;
    class Date completed;

public:
    virtual int getPlaneID();
    virtual int getServiceID();
    virtual Date getCreationDate();
    virtual Staff* getStaff();
    virtual void setResponsible(Staff &staff);
    virtual void setComplete(Date &date);
    virtual Staff* getResponsible();
    virtual bool check() = 0;
};

class Cleaning : public Service {

private:

    bool wc = false;
    bool seats = false;
    bool floor = false;

public:
    Cleaning(int planeID, int serviceID, Date &date, Staff &staff);
    void setWc();
    void setSeats();
    void setFloor();
    bool check() override;
};

class Maintenance : public Service {

private:

    bool engine = false;
    bool landingGear = false;
    bool emergencyDoors = false;

public:
    Maintenance(int planeID, int serviceID, Date &date, Staff &staff);
    bool check() override;
};

#endif //PROJETO_SERVICE_H
