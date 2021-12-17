//
// Created by zedio on 21/11/2021.
//
#include <fstream>
#include <iostream>
#include "Airline.h"

using namespace std;

int Airline::getAirportCount() {
    return (int) airportList.size();
}

Airport Airline::getAirport(int id) {
    Airport airport;
    for (auto & i : airportList) {
        if (i.getID() == id) {
            return i;
        }
    }
    return airport;
}

bool Airline::airportExists(string &city) {
    for (auto &i : airportList) {
        if (i.getCity() == city) {
            return true;
        }
    }
    cout << "We do not have any Airport with that destination in our Airline." << endl;
    return false;
}

Airport Airline::getAirport(const string& city_) {
    Airport airport;
    for(auto ap : airportList) {
        if(ap.getCity() == city_)
            airport = ap;
    }

    return airport;
}

void Airline::loadAirports() {
    int airportID;
    string airportName, city;

    std::ifstream file;
    std::string filename = "airports.txt";

    file.open(filename, std::ifstream::in);

    while(file >> airportID >> airportName >> city) {
        Airport airport(airportID, airportName, city);
        airportList.push_back(airport);
    }
    file.close();
}

/////////////////////////////// HANDLE PLANES ////////////////////////////////////////////////
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

    do {
        InputStr(numberPlate, "Enter the numberPlate of this plane: ");
    } while (!validatePlaneNumber(numberPlate));

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

    bool result = std::any_of(planesList.begin(), planesList.end(), [&num](const Plane &plane){
        return (plane.getPlaneID() == num);
    });

    if (result) return true;
    else {
        cout << "Plane not found!" << endl;
        return false;
    }
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

/////////////////////////////// HANDLE FLIGHTS ////////////////////////////////////////////////

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
    if (flightsList.size() == maxNumOfFlights) {

    }
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

    do {
        InputStr(departLocation, "Enter the Flight's Departure Location: ");
    } while (!airportExists(departLocation));

    do {
        InputStr(destination, "Enter the Flight's Destination: ");
    } while (!airportExists(destination));

    Date date (std::stoi(departDate.substr(0,4)),
                                    std::stoi(departDate.substr(5,6)),
                                    std::stoi(departDate.substr(8,11)));

    Time time(std::stoi(flightDuration.substr(0,2)),
                                     std::stoi(flightDuration.substr(3,4)));

    int numSeats = getPlaneRef(planeID)->getCapacity();

    Flight flight(planeID, flightID, date,
                  time, departLocation, destination, numSeats);

    flight.setOriginAirport(getAirport(departLocation));
    flight.setDestAirport(getAirport(destination));

    flightsList.emplace_back(flight);
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

void Airline::sortFlights() {

    std::cin.clear();
    std::cin.ignore(10000, '\n');
    char userInput;

    std::cout << "Please select the parameter you wish to sort the planes by: " << std::endl;
    std::cout << "[1] FlightID" << std::endl;
    std::cout << "[2] Departure Date" << std::endl;
    std::cout << "[3] Flight Duration" << std::endl;
    std::cout << "[4] Available Seats" << std::endl;

    std::cin >> userInput;

    switch(userInput) {
        case '1':
            std::sort(flightsList.begin(), flightsList.end(),[](Flight & a, Flight & b) {
                return a.getFlightID() < b.getFlightID();
            });
            break;
        case '2':
            std::sort(flightsList.begin(), flightsList.end(),[](Flight & a, Flight & b) {
                return a.getDepartureDate() < b.getDepartureDate();
            });
            break;
        case '3':
            std::sort(flightsList.begin(), flightsList.end(),[](Flight & a, Flight & b) {
                return a.getFlightDuration() < b.getFlightDuration();
            });
            break;
        case '4':
            std::sort(flightsList.begin(), flightsList.end(),[](Flight & a, Flight & b) {
                return a.getSeatsAvailable().size() < b.getSeatsAvailable().size();
            });
            break;
        default: std::cout << "Invalid Input." << std::endl;
    }
}

void Airline::printAllFlights() {

    sortFlights();

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

        int numSeats = getPlaneRef(planeID)->getCapacity();

        Flight flight(planeID, flightID, Date(year,month,day),
                      Time(hour,minute), depart, destination,
                      numSeats);

        flight.setOriginAirport(getAirport(depart));
        flight.setDestAirport(getAirport(destination));
        flightsList.push_back(flight);
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

/////////////////////////////// HANDLE SERVICES ////////////////////////////////////////////////

void Airline::addService() {

    int serviceID, planeID;
    std::string firstName, lastName, date;
    std::string type;

    do  {
        InputInt(planeID, "Enter the planeID you want to add a Service to:");
    } while (!PlaneExists(planeID));

    do {
        InputStr(type, "Type of Service (Maintenance or Cleaning) : ");
    } while (!(type == "Cleaning" || (type == "Maintenance")));

    InputStr(firstName, "Enter the First Name of the Staff Member responsible for this Service: ");
    InputStr(lastName, "Enter his Last Name: ");

    Staff staff(firstName, lastName);

    if (type == "Cleaning") {
        Service* serviceptr;
        auto* cleaning = new Cleaning(planeID, staff);

        serviceptr = cleaning;
        servicesQueue.push(serviceptr);
    }
    else {
        Service* serviceptr;
        auto * maintenance = new Maintenance(planeID, staff);

        serviceptr = maintenance;
        servicesQueue.push(serviceptr);
    }
}

void Airline::checkService() {
    Service* service = servicesQueue.front();

    cout << "Service you are checking: " << endl;
    cout << "[Plane ID: " << service->getPlaneID() << "], [Responsible Staff: "<< service->getResponsible().toString()
         << "], [Type: " << service->printType() << "]" << endl;

    if (service->check()) {
        Date date;
        date.now();
        service->setComplete(date);
        servicesHistory.push_back(service);
        servicesQueue.pop();
    }
}

void Airline::printAllServicesDue() {
    queue<Service*> temp = servicesQueue;

    while (!temp.empty()) {
        Service* service = temp.front();
        cout << "[Plane ID: " << service->getPlaneID() << "], [Responsible Staff: "<< service->getResponsible().toString()
                << "], [Type: " << service->printType() << "]" << endl;
        temp.pop();
    }
}

void Airline::printAllServicesHistory() {
    if (servicesHistory.empty()) {
        cout << "There are no records of completed services." << endl;
    }
    else {
        for (auto elem : servicesHistory) {
            cout << "[Plane ID: " << elem->getPlaneID() << "], [Responsible Staff: "<< elem->getResponsible().toString()
                 << "] [Completed in: " << elem->getDateCompleted().toString() << "], [Type: " << elem->printType() << "]" << endl;
        }
    }

}

void Airline::LoadServices() {

    while (!servicesQueue.empty()) {
        Service* service = servicesQueue.front();
        servicesQueue.pop();
    }

    int planeID;
    string type, firstName, lastName;

    std::ifstream file;
    std::string filename = "services.txt";

    file.open(filename, std::ifstream::in);

    while(file >> planeID >> type >> firstName >> lastName) {

        Staff staff(firstName, lastName);

        if (type == "Cleaning") {
            Service* serviceptr;
            auto* cleaning = new Cleaning(planeID, staff);

            serviceptr = cleaning;
            servicesQueue.push(serviceptr);
        }
        else {
            Service* serviceptr;
            auto * maintenance = new Maintenance(planeID, staff);

            serviceptr = maintenance;
            servicesQueue.push(serviceptr);
        }
    }
    file.close();
}

void Airline::reserveSeat() {

    int chosenSeat, numberOfSeats, flightID;
    std::string firstName;
    std::string lastName;
    int passengerId;

    InputInt(flightID, "To which Flight do you wish to buy seat(s)?");
    Flight& flight = getFlightRef(flightID);

    InputInt(numberOfSeats, "How many Seats do you wish to buy?");

    for (int i = 0; i < numberOfSeats; i++) {

        flight.printSeats();

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
        if(includeBaggage == "y") 
            passenger.setBaggageInclusion(true);
        else 
            passenger.setBaggageInclusion(false);
    }

    std::cout << "________________________________________________" << std::endl;
    std::cout << "|                                              |" << std::endl;
    std::cout << "|   Your Seats were successfully reserved!     |" << std::endl;
    std::cout << "________________________________________________" << std::endl;
}