//
// Created by zedio on 07/12/2021.
//

#include "Service.h"
#include "../Utility/utility.h"

Staff* Service::getResponsible() {
    return responsible;
}

void Service::setComplete(Date &date) {
    this->completed = date;
}

void Service::setResponsible(Staff &staff) {
    this->responsible = &staff;
}

int Service::getPlaneID() {
    return planeID;
}

int Service::getServiceID() {
    return serviceID;
}

Date Service::getCreationDate() {
    return created;
}

Staff* Service::getStaff() {
    return responsible;
}

Cleaning::Cleaning(int planeID, int     serviceID, Date &date, Staff &staff){}

bool Cleaning::check() {

    std::cin.clear();
    std::cin.ignore(10000, '\n');

    std::string ch;
    do {
        InputStr(ch, "Are all the bathrooms cleaned? (Y/n)");
    } while(!validateAnswer(ch));
    if (ch == "Y" || ch == "y") {
        setWc();
    }

    do {
        InputStr(ch, "Are all the seats cleaned? (Y/n)");
    } while(!validateAnswer(ch));
    if (ch == "Y" || ch == "y") {
        setSeats();
    }

    do {
        InputStr(ch, "Is the floor cleaning complete? (Y/n)");
    } while(!validateAnswer(ch));;
    if (ch == "Y" || ch == "y") {
        setFloor();
    }

    if (wc && seats && floor) {
        std::cout << "Everything is well cleaned and shining bright like a diamond!" << std::endl;
        return true;
    }
    else{
        std::cout << "Better ask the Responsible for this Service what's going on!" << std::endl;
        return false;
    }
}

void Cleaning::setWc() {
    wc = true;
}

void Cleaning::setSeats() {
    seats = true;
}

void Cleaning::setFloor() {
    floor = true;
}

Maintenance::Maintenance(int planeID, int serviceID, Date &date, Staff &staff) {}

bool Maintenance::check() {
    std::string ch;
    do {
        InputStr(ch, "Is the Engine working correctly? (Y/n)");
    } while(!validateAnswer(ch));
    if (ch == "Y" || ch == "y") {
        this->engine = true;
    }

    do {
        InputStr(ch, "Are the landing gears ready to roll? (Y/n)");
    } while(!validateAnswer(ch));
    if (ch == "Y" || ch == "y") {
        this->landingGear = true;
    }

    do {
        InputStr(ch, "Are the Emergency Doors fully functional? (Y/n)");
    } while(!validateAnswer(ch));;
    if (ch == "Y" || ch == "y") {
        this->emergencyDoors = true;
    }

    if (engine && landingGear && emergencyDoors) {
        std::cout << "All is well and the plane is ready to fly!" << std::endl;
        return true;
    }
    else return false;
}