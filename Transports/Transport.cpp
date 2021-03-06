//
// Created by Anibal on 13/12/2021.
//

#include "Transport.h"

#include <utility>

Transport::Transport(type t, int id, int airportid , int distance, vector<Time> schedule) {
    this->transporttype = t;
    this->transportid = id;
    this->airportid = airportid;
    this->distance = distance;
    this->schedule = std::move(schedule);
}
void Transport::addTime(Time time) {
    schedule.push_back(time);
}
void Transport::printSchedule() const {
    for (int i = 0; i < schedule.size(); i++){
        if ((i % 4) == 0 && i != 0) cout << endl;
        cout << setfill('0') << right << setw(2) << schedule[i].getHours() << ":" << setw(2) <<schedule[i].getMinutes() << "  ";
    }
    cout << endl;
}

bool Transport::operator<(const Transport& T1) const{
    if (this->distance < T1.distance) return true;
    else if (this->distance == T1.distance && this->transportid < T1.transportid) return true;
    else return false;
}

bool Transport::operator == (const Transport& T1) const{
    if (this->transportid == T1.transportid && this->transporttype == T1.transporttype) return true;
    else return false;
}

type Transport::getType()const {return transporttype;}
int Transport::getId() const {return transportid;}
int Transport::getAirportId() const {return airportid;}
int Transport::getDistance() const {return distance;}
vector<Time> Transport::getSchedule() const {return schedule;}
