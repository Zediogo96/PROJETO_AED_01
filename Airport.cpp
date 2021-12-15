#include <fstream>

#include "Airport.h"
#include "Utility/utility.h"


Airport::Airport(int id, string name) : transportTree(Transport(type::BUS, -1, -1, -1, vector<Time>())) {
    this->id = id;
    this->name = name;

}

const string& Airport::getName() {
    return name;
}

const int& Airport::getID() {
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
        Transport P1 = Transport(t, nID, airportid ,nDist, schedule);
        transportTree.insert(P1);
    }
    transports.close();
}
void Airport::showAvailables(type vehicle) {
    cout << "Available: " << endl;
    BSTItrLevel<Transport> it(transportTree);
    while (!it.isAtEnd()){
        if (it.retrieve().getType() == vehicle && it.retrieve().getAirportId() == id) cout << "- " << it.retrieve().getId() << endl;
        it.advance();
    }
}
void Airport::showDistances(type vehicle) {
    cout << "Distance from the airport: " << endl;
    BSTItrLevel<Transport> it(transportTree);
    while (!it.isAtEnd()){
        if (it.retrieve().getType() == vehicle && it.retrieve().getAirportId() == id) cout << "Number: " << it.retrieve().getId() << " is " << it.retrieve().getDistance() << " kms away from the airport." << endl;
        it.advance();
    }
}
void Airport::showSchedules(type vehicle) {
    cout << "Available Schedules: " << endl;
    BSTItrLevel<Transport> it(transportTree);
    while (!it.isAtEnd()){
        if (it.retrieve().getType() == vehicle && it.retrieve().getAirportId() == id){
            cout << "\n-For number: " << it.retrieve().getId() << endl;
            it.retrieve().printSchedule();
        }
        it.advance();
    }
}

void Airport::reserveSeat() {
    int chosenSeat, numberOfSeats, flightID;
    std::string firstName;
    std::string lastName;
    int passengerId;

    InputInt(flightID, "To which Flight do you wish to buy seat(s)?");
    Flight& flight = airline->getFlightRef(flightID);

    InputInt(numberOfSeats, "How many Seats do you wish to buy?");

    for (int seat : flight.getSeatsAvailable()) {
        std::cout << seat << " ";
    }

    for (int i = 0; i < numberOfSeats; i++) {

        do {
            InputInt(chosenSeat, "Choose your seat: ");
        } while(!flight.availableSeat(chosenSeat));

        InputStr(firstName, "Your First Name: ");
        InputStr(lastName, "Your Last Name: ");

        do {
            InputInt(passengerId, "Your Client ID: ");
        } while(!flight.availableClientID(passengerId, firstName, lastName));


        Passenger passenger(firstName, lastName, passengerId);
        passenger.SetSeatNumber(chosenSeat);
        flight.ReserveSeat(passenger);

        string includeBaggage;
        string autoBaggage;
        InputStr(includeBaggage, "Include baggage (y/n)? ");
        if(includeBaggage == "y") {
            InputStr(autoBaggage, "Automatic baggage check-in (y/n)? ");
            if(autoBaggage == "y") {
                addBaggageToConveyor(Baggage(passengerId, flightID));
            }
        }
    }

    std::cout << "________________________________________________" << std::endl;
    std::cout << "|                                              |" << std::endl;
    std::cout << "|   Your Seats were successfully reserved!     |" << std::endl;
    std::cout << "________________________________________________" << std::endl;
}

void Airport::addBaggageToConveyor(Baggage baggage) {
    conveyor.addBaggage(baggage);
    if(conveyor.getAmount() >= baggageCart.getMaxAmount())
        emptyConveyor();
}

void Airport::emptyConveyor() {
    while(!conveyor.isEmpty())
        baggageCart.addBaggage(conveyor.retrieveBaggage());
    
    fillPlane();
}

void Airport::fillPlane() {
    while(!baggageCart.getAmount() > 0) {
        Baggage baggage = baggageCart.retrieveBaggage();
        airline->getPlaneRef(airline->getFlightRef(baggage.getFlightID()).getPlaneID())->fill(baggage);
    }
}