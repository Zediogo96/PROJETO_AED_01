#include <fstream>
#include <utility>

#include "Airport.h"
#include "Plane.h"

Airport::Airport() : transportTree(Transport(type::BUS, -1, -1, -1, vector<Time>())) {}

Airport::Airport(int id, string name, string city) : transportTree(Transport(type::BUS, -1, -1, -1, vector<Time>())) {
    this->id = id;
    this->name = std::move(name);
    this->city  = std::move(city);
    LoadTransports();
}

const string& Airport::getName() {
    return name;
}

const int& Airport::getID() const {
    return id;
}

void Airport::LoadTransports() {
    ifstream transports;
    transports.open("transports.txt", ifstream::in);
    while(!transports.eof()){
        string id, dist, trans, airportId;
        vector<Time> schedule;
        int nID, nDist, airportid;
        type t;
        getline(transports, trans, ' ');
        getline(transports, id, ' ');
        getline(transports, airportId, ' ');
        getline(transports, dist, ' ');
        nID = stoi(id);
        airportid = stoi(airportId);
        nDist = stoi(dist);
        if (trans == "SUBWAY") t = type::SUBWAY;
        if (trans == "TRAIN") t = type::TRAIN;
        if (trans == "BUS") t = type::BUS;
        Time time1;
        string time;
        int len = 0;
        getline(transports, time);
        while(len < time.length()){
            string subtime = time.substr(len, 5);
            len += subtime.size() + 1;
            string hour = subtime.substr(0,2);
            string min = subtime.substr(3,2);
            time1 = Time(stoi(hour),stoi(min));
            schedule.push_back(time1);
        }
        if(airportid == this->id) {
            Transport P1 = Transport(t, nID, airportid ,nDist, schedule);
            transportTree.insert(P1);
        }
    }
    transports.close();
}

void Airport::showAvailables(type vehicle) const {
    cout << "Available: " << endl;
    BSTItrLevel<Transport> it(transportTree);
    while (!it.isAtEnd()){
        if (it.retrieve().getType() == vehicle) cout << "- " << it.retrieve().getId() << endl;
        it.advance();
    }
}

void Airport::showDistances(type vehicle) const {
    cout << "Distance from the airport: " << endl;
    BSTItrLevel<Transport> it(transportTree);
    while (!it.isAtEnd()){
        if (it.retrieve().getType() == vehicle) cout << "Number: " << it.retrieve().getId() << " is " << it.retrieve().getDistance() << " kms away from the airport." << endl;
        it.advance();
    }
}

void Airport::showSchedules(type vehicle) const {
    cout << "Available Schedules: " << endl;
    BSTItrLevel<Transport> it(transportTree);
    while (!it.isAtEnd()){
        if (it.retrieve().getType() == vehicle){
            cout << "-For number: " << it.retrieve().getId() << endl;
            it.retrieve().printSchedule();
        }
        it.advance();
    }
}

int Airport::getCartLoad() {
    return baggageCart.getAmount();
}

int Airport::getCartMaxLoad() {
    return baggageCart.getMaxAmount();
}

int Airport::getConveyorLoad() {
    return conveyor.getAmount();
}

void Airport::addBaggageToConveyor(Baggage baggage) {
    conveyor.addBaggage(baggage);
    if(conveyor.getAmount() >= baggageCart.getMaxAmount())
        emptyConveyor();
}

void Airport::emptyConveyor() {
    while(!conveyor.isEmpty())
        baggageCart.addBaggage(conveyor.retrieveBaggage());
}

void Airport::fillPlane(Plane& plane) {
    while(baggageCart.getAmount() > 0) {
        Baggage baggage = baggageCart.retrieveBaggage();
        plane.fill(baggage);
    }
}

const std::string &Airport::getCity() {
    return city;
}

std::string Airport::toString() const {
    std::ostringstream oss;
    oss << id << " "  << name  << " "  << city;
    return oss.str();
}
