//
// Created by zedio on 07/12/2021.
//

#ifndef PROJETO_SERVICE_H
#define PROJETO_SERVICE_H

#include "../Utility/Date.h"
#include "Staff.h"


class Service {

protected:
    int planeID{};
    int serviceID{};
    class Staff responsible;
    class Date completed;

public:
    virtual int getPlaneID();
    virtual int getServiceID();
    virtual void setPlaneID(int planeID_);
    virtual void setServiceID(int serviceID_);
    virtual void setComplete(Date &date);
    virtual bool check() = 0;
};

class Cleaning : public Service {

private:

    bool wc = false;
    bool seats = false;
    bool floor = false;

public:
    Cleaning(int planeID, int serviceID, Staff &staff);
    ~Cleaning() = default;
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
    Maintenance(int planeID, int serviceID, Staff &staff);
    ~Maintenance() = default;;
    bool check() override;
};

#endif //PROJETO_SERVICE_H
