//
// Created by Anibal on 13/12/2021.
//
#include<string>
#include "../Utility/Time.h"
#include<vector>
#ifndef PROJETO_TRANSPORT_H
#define PROJETO_TRANSPORT_H

using namespace std;

enum class type {METRO,AUTOCARRO,COMBOIO};

class Transport {
private:
        type transporttype;
        int distance;
        vector<Time> schedule;
public:
    Transport(type t, int distance, vector<Time> schedule);
    void addTime(Time time);
    void printSchedule();
    type getType();
    int getDistance();
    vector<Time> getSchedule();

};


#endif //PROJETO_TRANSPORT_H
