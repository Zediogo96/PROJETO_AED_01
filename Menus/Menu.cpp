//
// Created by zedio on 04/12/2021.
//


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
                airport_menu(airline); break;
            case '2': ; break;
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
        std::cout << "|    [5] Save all Planes           |" << std::endl;
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
                planes_menu(airline);
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
        std::cout << "|    [4] Save all Flights           |" << std::endl;
        std::cout << "|    [0] Exit to Main Menu          |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::flush;
        std::cin >> option;

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
                std::cout << "Are you sure? [Y/n]" << std::endl;
                std::cin >> check;
                if (check == 'Y' || check == 'y') {
                    airline.clearFlights();
                    break;
                }
                std::cout << "All planes were erased" << std::endl;
                planes_menu(airline);

            case '5':
                airline.SaveFlights();
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
        std::cout << "|    [3] Print All Services         |" << std::endl;
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
                services_menu(airline);
                break;
            case '3':
                airline.printAllServices();
                break;
            case '0':
                return;
            default:
                std::cout << "Invalid input" << std::endl;
                system("pause");
        }
    }
}