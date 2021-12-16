//
// Created by zedio on 07/12/2021.
//

#include "Service.h"
#include "../Utility/utility.h"

int Service::getPlaneID() {
    return planeID;
}

void Service::setComplete(Date &date) {
    this->completed = date;
}

Staff Service::getResponsible() {
    return responsible;
}

Date Service::getDateCompleted() {
    return completed;
}

Cleaning::Cleaning(int planeID_, Staff &staff){
    planeID = planeID_;
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
        wc = true;
    }

    do {
        InputStr(ch, "Are all the seats cleaned? (Y/n)");
    } while(!validateAnswer(ch));
    if (ch == "Y" || ch == "y") {
        seats = true;
    }

    do {
        InputStr(ch, "Is the floor cleaning complete? (Y/n)");
    } while(!validateAnswer(ch));
    if (ch == "Y" || ch == "y") {
       floor = true;
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

Maintenance::Maintenance(int planeID_,Staff &staff) {
    planeID = planeID_;
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