//
// Created by zedio on 07/12/2021.
//

#ifndef PROJETO_SERVICE_H
#define PROJETO_SERVICE_H

#include "../Utility/Date.h"
#include "Staff.h"

/**
 * @brief Abstract superclass outlining basic service functionality and information
 * 
 */
class Service {

protected:
    int planeID{};
    class Staff responsible;
    class Date completed;

public:

    /**
     * @brief Method that returns the planeID to which the Service refers to
     * @return int (foreign key)
     */
    virtual int getPlaneID();

    /**
     * @brief Method to use after checking if the Service is already complete, sets the Date of completion of Service
     * (using date.now())
     * @param date
     */
    virtual void setComplete(Date &date);

    /**
     * @brief Returns the Date in which the Service was completed
     * @return Date
     */
    Date getDateCompleted();

    /**
     * @brief Returns the Staff responsible for the Service
     * @return Staff
     */
    Staff getResponsible();

    /** @brief: Body for pure virtual method **/
    virtual bool check() = 0;

    /** @brief: Body for pure virtual method **/
    virtual string printType() = 0;
};

/**
 * @brief Subclass for the services related to cleaning
 * 
 */
class Cleaning : public Service {

private:
    bool wc = false;
    bool seats = false;
    bool floor = false;

public:

    /**
     * @brief Constructor for Cleaning class, derived from Service
     * @param planeID
     * @param staff
     */
    Cleaning(int planeID, Staff &staff);
    /** @brief: default destructor **/
    ~Cleaning() = default;
    /** @brief: Overriden method from service, to use when we want to complete a service **/
    bool check() override;
    /** @brief: Just for convenience in outputting Service this type **/
    string printType() override {
        return "Cleaning";
    }
};
/**
 * @brief Subclass for services related to maintenance
 * 
 */
class Maintenance : public Service {

private:
    bool engine = false;
    bool landingGear = false;
    bool emergencyDoors = false;
public:
    /**
     * @brief Constructor for Maintenace class, derived from service
     * @param planeID
     * @param staff
     */
    Maintenance(int planeID, Staff &staff);
    /** @brief: default destructor **/
    ~Maintenance() = default;
    /** @brief: Overriden method from service, to use when we want to complete a service **/
    bool check() override;
    /** @brief: Just for convenience in outputting Service of this type **/
    string printType() override {
        return "Maintenance";
    }
};

#endif //PROJETO_SERVICE_H