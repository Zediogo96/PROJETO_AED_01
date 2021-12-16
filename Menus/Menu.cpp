#include "Menu.h"

void main_menu(Airline &airline) {
    char option;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|        AIRLINE MANAGEMENT         |" << std::endl;
        std::cout << "|             MAIN MENU             |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|    [1] Airport Management         |" << std::endl;
        std::cout << "|    [2] Costumer                   |" << std::endl;
        std::cout << "|    [0] Exit                       |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        switch ((char) option) {
            case '1':
                airport_menu(airline);
                break;
            case '2':
                costumer_menu(airline);
                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

void airport_menu(Airline &airline) {

    char option;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|        AIRPORT MANAGEMENT         |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|    What do you want to manage?    |" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|    [1] Planes                     |" << std::endl;
        std::cout << "|    [2] Flights                    |" << std::endl;
        std::cout << "|    [3] Services                   |" << std::endl;
        std::cout << "|    [4] Boarding                   |" << std::endl;
        std::cout << "|    [0] Exit                       |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        switch (option) {
            case '1':
                planes_menu(airline);
                break;
            case '2':
                flights_menu(airline);
                break;
            case '3':
                services_menu(airline);
                break;
            case '4': {
               int id;
                std::cout << "Choose which flight to board passengers into: " << std::endl << std::flush;
                std::cin >> id;
                Flight& flight = airline.getFlightRef(id);
                string message = flight.board();
                std::cout << message << endl;
                break;
            }
            case '0':
                return;
            default:
                std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

void planes_menu(Airline &airline) {

    char option;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|         PLANES MANAGEMENT         |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|    What do you want to manage?    |" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|    [1] Add Plane                  |" << std::endl;
        std::cout << "|    [2] Delete Plane               |" << std::endl;
        std::cout << "|    [3] View all Planes            |" << std::endl;
        std::cout << "|    [4] Erase all Planes           |" << std::endl;
        std::cout << "|    [5] Save all Planes            |" << std::endl;
        std::cout << "|    [0] Exit to Main Menu          |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        switch (option) {
            case '1':
                airline.addPlane();
                break;
            case '2':
                airline.deletePlane();
                break;
            case '3':
                airline.printPlanes();
                system("pause");
                break;
            case '4':
                char check;
                std::cout << "Are you sure? [Y/n]" << std::endl;
                std::cin >> check;
                if (check == 'Y' || check == 'y') {
                    airline.clearPlanes();
                    break;
                }
                std::cout << "All planes were erased" << std::endl;
            case '5':
                airline.SavePlanes();
                break;
            case '0':
                return;
            default:
                std::cout << "Invalid input" << std::endl;
                system("pause");
        }
    }
}

void flights_menu(Airline &airline) {

    char option;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|         FLIGHTS MANAGEMENT        |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|    What do you want to manage?    |" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|    [1] Add Flight                 |" << std::endl;
        std::cout << "|    [2] Delete Flight              |" << std::endl;
        std::cout << "|    [3] View all Flights           |" << std::endl;
        std::cout << "|    [4] Erase all Flights          |" << std::endl;
        std::cout << "|    [5] Save all Flights           |" << std::endl;
        std::cout << "|    [0] Exit to Main Menu          |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        cout << "Please input your choice: " << endl;
        cin >> option;

        switch (option) {
            case '1': {
                airline.addFlight();
                break;
            }
            case '2':
                airline.deleteFlight();
                break;
            case '3':
                airline.printAllFlights();
                system("pause");
                break;
            case '4':
                char check;
                cout << "Are you sure? [Y/n]" << endl;
                cin >> check;
                if (check == 'Y' || check == 'y') {
                    airline.clearFlights();
                    break;
                }
                cout << "All planes were erased" << endl;
                planes_menu(airline);

            case '5':
                airline.SaveFlights();
            case '6':

                break;
            case '0':
                return;
            default:
                std::cout << "Invalid input" << std::endl;
                system("pause");
        }
    }
}

void services_menu(Airline &airline) {
    char option;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|         SERVICE MANAGEMENT        |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|    What do you want to manage?    |" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|    [1] Add Service                |" << std::endl;
        std::cout << "|    [2] Check next Service         |" << std::endl;
        std::cout << "|    [3] Services not completed     |" << std::endl;
        std::cout << "|    [4] Services history           |" << std::endl;
        std::cout << "|    [0] Exit to Main Menu          |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl <<std::flush;
        std::cin >> option;

        switch (option) {
            case '1':
                airline.addService();
                break;
            case '2':
                airline.checkService();
                break;
            case '3':
                airline.printAllServicesDue();
                break;
            case '4':
                airline.printAllServicesHistory();
                break;
            case '0':
                return;
            default:
                std::cout << "Invalid input" << std::endl;
                system("pause");
        }
    }
}

void transport_options(char vehicle, const Airport &airport){
    char option;
    type transp;
    while (true){
        std::cout << "_____________________________________" << std::endl;
        switch(vehicle){
            case 'B':
                transp = type::BUS;
                std::cout << "|               BUS                 |" << std::endl;
                break;
            case 'S':
                transp = type::SUBWAY;
                std::cout << "|              SUBWAY               |" << std::endl;
                break;
            case 'T':
                transp = type::TRAIN;
                std::cout << "|               TRAIN               |" << std::endl;
                break;
            default: std::cout << "Invalid Input \n:";
                system("pause");

        }
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|    [1] AVAILABLES                 |" << std::endl;
        std::cout << "|    [2] DISTANCE FROM AIRPORT      |" << std::endl;
        std::cout << "|    [3] SCHEDULES                  |" << std::endl;
        std::cout << "|    [0] EXIT                       |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        switch ((char) option) {
            case '1':
                airport.showAvailables(transp);
                system("pause");
                break;
            case '2':
                airport.showDistances(transp);
                system("pause");
                break;
            case '3':
                airport.showSchedules(transp);
                system("pause");
                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }

}

void transport_menu(const Airport &airport){

    char option;

    while (true){

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|      Transport Information        |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|    [1] BUS                        |" << std::endl;
        std::cout << "|    [2] SUBWAY                     |" << std::endl;
        std::cout << "|    [3] TRAIN                      |" << std::endl;
        std::cout << "|    [0] EXIT                       |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;
        switch ((char) option) {
            case '1':
                transport_options('B', airport);
                break;
            case '2':
                transport_options('S', airport);
                break;
            case '3':
                transport_options('T', airport);
                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

void costumer_menu(Airline &airline) {
    //Airport airport;// = airline.getAirport(select_airport_menu(airline));
    char option;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|             CUSTOMER              |" << std::endl;
        std::cout << "|               MENU                |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|    [1] Seat Reservation           |" << std::endl;
        std::cout << "|    [2] Flights Schedule           |" << std::endl;
        std::cout << "|    [3] Transport Information      |" << std::endl;
        std::cout << "|    [0] Exit                       |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;
        int id;
        switch ((char) option) {
            case '1':
                airline.reserveSeat();
                break;
            case '2':
                airline.printAllFlights();
                break;
            case '3':
                select_airport_menu(airline);
                //transport_menu(airline.getAirport(id));
                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

void select_airport_menu(Airline &airline) {
    int option;

    while(true) {
        std::cout << "_____________________________________" << std::endl;
        std::cout << "|        AIRPORT SELECTION          |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "| Which airport you want to check?  |" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout<<setfill(' ');
        for(int i = 0; i < airline.getAirportCount(); i++) {
            std::cout << "|    [" << i + 1 << "] " << setw(3) << left << airline.getAirport(i + 1).getName() << " "
            << setw(23) << "|" << std::endl;
        }
        std::cout << "|                                   |" << std::endl;
        std::cout << "|    [0] EXIT                       |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;
        if(option > 0 && option < airline.getAirportCount() - 1) {
            Airport airport = airline.getAirport(option);
            transport_menu(airport);
        }
        else if (option == 0) return;
        else {
            std::cout << "Invalid Input \n:";
            system("pause");
        }
    }
}