//
// Created by zedio on 07/12/2021.
//

#ifndef PROJETO_SERVICE_H
#define PROJETO_SERVICE_H

#include "../Utility/Date.h"
#include "Staff.h"

/** brief: Abstract Class for the different types of services **/
class Service {

protected:
    int planeID{};
    class Staff responsible;
    class Date completed;

public:

    /**
     * Method that returns the planeID to which the Service refers to
     * @return int (foreign key)
     */
    virtual int getPlaneID();

    /**
     * Method to use after checking if the Service is already complete, sets the Date of completion of Service
     * (using date.now())
     * @param date
     */
    virtual void setComplete(Date &date);

    /**
     * Returns the Date in which the Service was completed
     * @return Date
     */
    Date getDateCompleted();

    /**
     * Returns the Staff responsible for the Service
     * @return Staff
     */
    Staff getResponsible();

    /** brief: Body for pure virtual method **/
    virtual bool check() = 0;

    /** brief: Body for pure virtual method **/
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
    string printType() override {
        return "Maintenance";
    }
};

#endif //PROJETO_SERVICE_H