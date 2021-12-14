//
// Created by zedio on 21/11/2021.
//
#include <fstream>
#include <iostream>
#include "Airline.h"

using namespace std;

const std::string& Airline::getName() {
    return name;
}

int Airline::getMaxNumOfFlights() const {
    return maxNumOfFlights;
}

/** Handle Transports **/
void Airline::LoadTransports() {
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
void Airline::showAvailables(type vehicle) {
    cout << "Available: " << endl;
    BSTItrLevel<Transport> it(transportTree);
    while (!it.isAtEnd()){
        if (it.retrieve().getType() == vehicle) cout << "- " << it.retrieve().getId() << endl;
        it.advance();
    }
}
void Airline::showDistances(type vehicle) {
    cout << "Distance from the airport: " << endl;
    BSTItrLevel<Transport> it(transportTree);
    while (!it.isAtEnd()){
        if (it.retrieve().getType() == vehicle) cout << "Number: " << it.retrieve().getId() << " is " << it.retrieve().getDistance() << " kms away from the airport." << endl;
        it.advance();
    }
}
void Airline::showSchedules(type vehicle) {
    cout << "Available Schedules: " << endl;
    BSTItrLevel<Transport> it(transportTree);
    while (!it.isAtEnd()){
        if (it.retrieve().getType() == vehicle){
            cout << "\n-For number: " << it.retrieve().getId() << endl;
            it.retrieve().printSchedule();
        }
        it.advance();
    }
}


bool Airline::availablePlane(int planeID) {

    for (auto & it : planesList) {
        if (it.getPlaneID() == planeID) {
            std::cout << "This planeID is already used in another plane, please select another.\n";
            return false;
        }
    }
    return true;
}

int Airline::findPlane() {

    int planeID;

    std::cin.clear();

    InputInt(planeID, "Enter the Plane's ID: ");

    for (int i = 0; i < planesList.size(); i++) {

        if (planesList.at(i).getPlaneID() == planeID) {
            std::cout << "Plane Found. \n";
            return i;
        }
    }
    return -1;
}

void Airline::addPlane() {

    std::string numberPlate, type;
    int capacity, planeID;

    do
    {
        InputInt(planeID, "Enter the ID for this plane: ");

    } while(!availablePlane(planeID));

    do {
        InputStr(type, "Enter the type of this plane: ");
    } while (!validatePlaneType(type));

    InputStr(numberPlate, "Enter the numberPlate of this plane: ");

    InputInt(capacity, "Enter the capacity of this plane: ");

    planesList.emplace_back(Plane(planeID, type, numberPlate, capacity));

    std::cout << "Plane was added successfully! \n" << std::endl;
    std::cin.ignore();
}

void Airline::deletePlane() {

    int tmpIndex = findPlane();

    if (tmpIndex != -1) {
        planesList.erase(planesList.begin() + tmpIndex);
        std::cout << "Plane was deleted successfully" << std::endl;
    }
}

void Airline::printPlanes() {
    sortPlanes();
    for (const Plane& tmp : planesList) {
        std::cout << "{ PlaneID: " << tmp.getPlaneID() << ", Plane Type: " << tmp.getType() << ", NumberPlate: " << tmp.getNumberPlate()
                  << ", Capacity: " << tmp.getCapacity() << " }" << std::endl;
    }
}

void Airline::SavePlanes() {

    std::string filename = "planes.txt";
    std::fstream output;

    output.open(filename, std::fstream::out);

    if(output.is_open()) {
        for (auto & it : planesList) {
            output << it.getPlaneID() << " " << it.getType() << " " <<
                   it.getNumberPlate() << " " << it.getCapacity();
        }
    }
}

void Airline::LoadPlanes() {

    planesList.clear();

    Plane newPlane;
    std::string plateNumber, type;
    int capacity, planeID;

    std::ifstream file;
    std::string filename = "planes.txt";

    file.open(filename, std::ifstream::in);

    while(file >> planeID >> type >> plateNumber>> capacity) {
        planesList.emplace_back(Plane(planeID, type, plateNumber, capacity));
    }
}

Plane* Airline::getPlaneRef_input() {
    int planeID;

    std::cin.clear();

    InputInt(planeID, "Enter the Plane's ID: ");

    Plane *c = nullptr;
    for (auto &i: planesList) {
        if (i.getPlaneID() == planeID) {
            c = &i;
            break;
        }
    }
    return c;
}

Plane* Airline::getPlaneRef(int num) {
    Plane *c = nullptr;
    for (auto &i: planesList) {
        if (i.getPlaneID() == num) {
            c = &i;
            break;
        }
    }
    return c;
}

bool Airline::PlaneExists(int num) {
    for(const auto &it : planesList) {
        if (it.getPlaneID() == num) return true;
    }
    return false;
}

void Airline::clearPlanes() {
    planesList.clear();
}

void Airline::sortPlanes() {

    std::cin.clear();
    std::cin.ignore(10000, '\n');
    char userInput;

    std::cout << "Please select the parameter you wish to sort the planes by: " << std::endl;
    std::cout << "[1] PlaneID" << std::endl;
    std::cout << "[2] Plate Number" << std::endl;
    std::cout << "[3] Plane Type" << std::endl;
    std::cout << "[4] Capacity" << std::endl;

    std::cin >> userInput;

    switch(userInput) {
        case '1':
            std::sort(planesList.begin(), planesList.end(),[](Plane & a, Plane & b) {
                return a.getPlaneID() < b.getPlaneID();
            });
            break;
        case '2':
            std::sort(planesList.begin(), planesList.end(),[](Plane & a, Plane & b) {
                return a.getType() < b.getType();
            });
            break;
        case '3':
            std::sort(planesList.begin(), planesList.end(),[](Plane & a, Plane & b) {
                return a.getNumberPlate() < b.getNumberPlate();
            });
            break;
        case '4':
            std::sort(planesList.begin(), planesList.end(),[](Plane & a, Plane & b) {
                return a.getCapacity() < b.getCapacity();
            });
            break;
        default: std::cout << "Invalid Input." << std::endl;
    }
}

std::vector<Plane> Airline::getPlanes() {
    return this->planesList;
}

//////////////// HANDLE FLIGHTS //////////////

bool Airline::availableFlight(int flightID) {

    for (auto & it : flightsList) {
        if (it.getFlightID() == flightID) {
            std::cout << "This flightID is already used in another flight, please select another.\n";
            return false;
        }
    }
    return true;
}

void Airline::addFlight() {

    Flight newFlight;

    int flightID, planeID;
    std::string departDate;
    std::string flightDuration;
    std::string departLocation;
    std::string destination;
    do  {
        InputInt(planeID, "Enter the planeID for this Flight:");
    } while (!PlaneExists(planeID));

    do {
        InputInt(flightID, "Enter the flightID for this Flight: ");
    } while (!availableFlight(flightID));

    do {
        InputStr(departDate, "Enter the Departure Date for this Flight: ");
    } while(!validateDate(departDate));

    do {
        InputStr(flightDuration, "Enter the duration of this Flight: ");
    } while(!validateTime(flightDuration));

    InputStr(departLocation, "Enter the Flight's Departure Location: ");

    InputStr(destination, "Enter the Flight's Destination: ");

    newFlight.setPlaneID(planeID);
    newFlight.setFlightID(flightID);
    newFlight.setDepartureDate(Date(std::stoi(departDate.substr(0,4)),
                                    std::stoi(departDate.substr(5,6)),
                                    std::stoi(departDate.substr(8,11))));

    newFlight.setFlightDuration(Time(std::stoi(flightDuration.substr(0,2)),
                                     std::stoi(flightDuration.substr(3,4))));

    newFlight.setDepartureLocation(departLocation);
    newFlight.setDestination(destination);

    int numSeats = getPlaneRef(planeID)->getCapacity();
    newFlight.setSeatsNumber(numSeats);


    flightsList.emplace_back(newFlight);
}

void Airline::deleteFlight() {

    int flightID;
    InputInt(flightID, "Enter the Flight's ID: ");

    for (auto it = flightsList.begin(); it != flightsList.end(); it++) {
        if ((*it).getFlightID() == flightID) {
            flightsList.erase(it);
            std::cout << "Flight was deleted successfully!" << std::endl;
        }

    }
    std::cout << "Flight was not found in our database. \n";
}

void Airline::printAllFlights() {
    for (const auto& it : flightsList) {
        it.printInfo();
    }
}

void Airline::clearFlights() {
    flightsList.clear();
}

void Airline::SaveFlights() {
    std::string filename = "flights.txt";
    std::fstream output;

    output.open(filename, std::fstream::out);

    if(output.is_open()) {
        for (auto & it : flightsList) {
            std::string s;
            output << it.getPlaneID() << " " << it.getFlightID() << " "
                   << it.getDepartureDate().toString() << " " << it.getFlightDuration().toString()
                   << " " << it.getDepartureLocation() << " " << it.getDestination() << std::endl;
        }
    }
}

void Airline::LoadFlights() {

    std::ifstream file;

    Flight newFlight;

    int planeID, flightID;
    int year, month, day, hour, minute;
    std::string depart, destination, line;
    char separator = '/';
    char sep2 = ':';
    file.open("flights.txt");

    while(!file.eof()) {

        //  Chk string
        std::getline(file, line);
        std::istringstream str(line);

        str >> planeID >> flightID >> year >> separator >> month >> separator >> day >> hour >> sep2 >> minute
            >> depart >> destination;

        newFlight.setPlaneID(planeID);
        newFlight.setFlightID(flightID);
        newFlight.setDepartureDate(Date(year, month, day));

        newFlight.setFlightDuration(Time(hour, minute));

        newFlight.setDepartureLocation(depart);
        newFlight.setDestination(destination);

        int numSeats = getPlaneRef(planeID)->getCapacity();
        newFlight.setSeatsNumber(numSeats);
        flightsList.push_back(newFlight);
    }
}

Flight& Airline::getFlightRef(int num) {

    for (Flight &i: flightsList) {
        if (i.getPlaneID() == num) {
            return i;
        }
    }
    throw std::logic_error("This flight number doesn't exist, please check our Records");
}

////////////////////////////// HANDLE PASSENGERS //////////////////////////////////

void Airline::reserveSeat() {
    int chosenSeat, numberOfSeats, flightID;
    std::string firstName;
    std::string lastName;
    int passengerId;

    InputInt(flightID, "To which Flight do you wish to buy seat(s)?");
    Flight& flight = getFlightRef(flightID);

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
                baggageCart.addBaggage(Baggage(passengerId));
                if(baggageCart.isFull()) {
                    cout << "Baggage Cart full, emptying..." << endl;
                    baggageCart.empty();
                }
            }
        }
    }

    std::cout << "________________________________________________" << std::endl;
    std::cout << "|                                              |" << std::endl;
    std::cout << "|   Your Seats were successfully reserved!     |" << std::endl;
    std::cout << "________________________________________________" << std::endl;
}