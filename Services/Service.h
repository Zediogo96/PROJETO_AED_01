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
    class Staff responsible;
    class Date completed;

public:
    virtual int getPlaneID();
    virtual void setPlaneID(int planeID_);
    virtual void setComplete(Date &date);
    Date getDateCompleted();
    Staff getResponsible();
    virtual bool check() = 0;
    virtual string printType() = 0;
};

class Cleaning : public Service {

private:

    bool wc = false;
    bool seats = false;
    bool floor = false;

public:
    Cleaning(int planeID, Staff &staff);
    ~Cleaning() = default;
    void setWc();
    void setSeats();
    void setFloor();
    bool check() override;
    string printType() override {
        return "Cleaning";
    }

};

class Maintenance : public Service {

private:

    bool engine = false;
    bool landingGear = false;
    bool emergencyDoors = false;

public:
    Maintenance(int planeID, Staff &staff);
    ~Maintenance() = default;
    bool check() override;
    string printType() {
        return "Maintenance";
    }

};

#endif //PROJETO_SERVICE_H
