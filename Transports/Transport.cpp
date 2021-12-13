//
// Created by Anibal on 13/12/2021.
//

#include "Transport.h"

Transport::Transport(type t, int distance, vector<Time> schedule) {
    this->transporttype = t;
    this->distance = distance;
    this->schedule = schedule;
}
void Transport::addTime(Time time) {
    schedule.push_back(time);
}
void Transport::printSchedule() {
    cout << "--------------------------" << endl;
    cout << "|  Available Schedules:  |" << endl;
    cout << "--------------------------" << endl;
    for (int i = 0; i < schedule.size(); i++){
        if ((i % 4) == 0) cout << endl;
        cout << setfill('0') << setw(2) << schedule[i].getHours() << ":" << setw(2) <<schedule[i].getMinutes() << "  ";
    }
    cout << endl;
}

type Transport::getType() {return transporttype;}
int Transport::getDistance() {return distance;}
vector<Time> Transport::getSchedule() {return schedule;}
