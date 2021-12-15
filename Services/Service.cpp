//
// Created by zedio on 07/12/2021.
//

#include "Service.h"
#include "../Utility/utility.h"

int Service::getPlaneID() {
    return planeID;
}

int Service::getServiceID() {
    return serviceID;
}
void Service::setComplete(Date &date) {
    this->completed = date;
}

void Service::setPlaneID(int planeID_) {
    this->planeID = planeID_;
}

void Service::setServiceID(int serviceID_) {
    this->serviceID = serviceID_;
}

Cleaning::Cleaning(int planeID_, int serviceID_, Staff &staff){
    planeID = planeID_;
    this->serviceID = serviceID_;
    this->responsible = staff;
}

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
    } while(!validateAnswer(ch));
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

Maintenance::Maintenance(int planeID_, int serviceID, Staff &staff) {
    planeID = planeID_;
    this->serviceID = serviceID;
    this->responsible = staff;
}

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
    } while(!validateAnswer(ch));
    if (ch == "Y" || ch == "y") {
        this->emergencyDoors = true;
    }

    if (engine && landingGear && emergencyDoors) {
        std::cout << "All is well and the plane is ready to fly!" << std::endl;
        return true;
    }
    else return false;
}