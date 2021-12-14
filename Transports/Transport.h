//
// Created by Anibal on 13/12/2021.
//
#include<string>
#include "../Utility/Time.h"
#include<vector>
#ifndef PROJETO_TRANSPORT_H
#define PROJETO_TRANSPORT_H

using namespace std;

enum class type {SUBWAY,BUS,TRAIN};

class Transport {
private:
        type transporttype;
        int transportid;
        int distance;
        vector<Time> schedule;
public:
    Transport(type t, int id , int distance, vector<Time> schedule);
    void addTime(Time time);
    void printSchedule() const;
    type getType() const;
    int getId() const;
    int getDistance() const;
    vector<Time> getSchedule() const;
    bool operator < (const Transport& T1) const;
    bool operator == (const Transport& T1) const;
};


#endif //PROJETO_TRANSPORT_H
