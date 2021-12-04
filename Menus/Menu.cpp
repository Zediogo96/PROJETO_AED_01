//
// Created by zedio on 04/12/2021.
//


#include "Menu.h"

void main_menu(Airline &airline) {

    char option;

    while (true) {

        std::cout << "----------------------------" << std::endl;
        std::cout << "      Main Menu   "           << std::endl;
        std::cout << "----------------------------" << std::endl;

        std::cout << "\n [1] Airport Management";
        std::cout << "\n [2] Costumer";
        std::cout << "\n [0] Exit\n \n";

        std::cout << "Please input your choice: " << std::flush;
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

        std::cout << "----------------------------" << std::endl;
        std::cout << "      Airport Management   " << std::endl;
        std::cout << "----------------------------" << std::endl;

        std::cout << "What do you want to manage? \n";

        std::cout << "\n [1] Planes";
        std::cout << "\n [2] Flights";
        std::cout << "\n [3] Services";
        std::cout << "\n [0] Exit\n";

        std::cout << "Please input your choice: " << std::flush;
        std::cin >> option;

        switch (option) {
            case '1':
                planes_menu(airline);
                break;
            case '2':
                ;
                break;
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

        std::cout << "----------------------------" << std::endl;
        std::cout << "      Planes Management   " << std::endl;
        std::cout << "----------------------------" << std::endl;

        std::cout << "\n [1] Add Plane";
        std::cout << "\n [2] Delete Plane";
        std::cout << "\n [3] View Planes";
        std::cout << "\n [4] Erase all planes.";
        std::cout << "\n [0] Exit to Main Menu\n";

        std::cout << "Please input your choice: " << std::flush;
        std::cin >> option;


        switch (option) {
            case '1':
                airline.addPlane();
                break;
            case '2':
                airline.deletePlane();
                break;
            case '3':
                airline.sortPlanes();
                airline.printPlanes();
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
                airline.LoadPlanes();
                break;
            case '0':
                return;
            default:
                std::cout << "Invalid input" << std::endl;
                system("pause");
        }
    }
}