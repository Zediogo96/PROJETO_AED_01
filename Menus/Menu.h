//
// Created by zedio on 02/12/2021.
//

#ifndef PROJETO_MENU_H
#define PROJETO_MENU_H

void main_menu() {

    char option;

    while (true) {

        system("CLS");
        std::cout << "----------------------------" << std::endl;
        std::cout << "      Main Menu   " << std::endl;
        std::cout << "----------------------------" << std::endl;

        std::cout << "\n [1] Airport Management";
        std::cout << "\n [2] Costumer";
        std::cout << "\n [0] Exit\n \n";

        std::cout << "Please input your choice: ";
        std::cin >> option;

        switch ((char) option) {
            case '1':
                ; break;
            case '2': ; break;
            case '0' : ; return;

            default: std::cout << "Invalid Input \n:";
            system("pause");
        }

    }
}

void airport_menu() {

    system("CLS");
    char option;

    while (true) {

        system("CLS");
        std::cout << "----------------------------" << std::endl;
        std::cout << "      Airport Management   " << std::endl;
        std::cout << "----------------------------" << std::endl;

        std::cout << "What do you want to manage? \n";

        std::cout << "\n [1] Planes";
        std::cout << "\n [2] Flights";
        std::cout << "\n [3] Services";
        std::cout << "\n [0] Exit\n";

        std::cin >> option;

        switch (option) {
            case '1':
                ;
                break;
            case '2':
                ;
                break;
            case '0':
                ;
                return;

            default:
                std::cout << "Invalid Input \n:";
        }
    }
}

void planes_menu(Airline &airline) {

    char option;

    while (1) {
        system("CLS");
        std::cout << "----------------------------" << std::endl;
        std::cout << "      Planes Management   " << std::endl;
        std::cout << "----------------------------" << std::endl;

        std::cout << "\n [1] Add Plane";
        std::cout << "\n [2] Remove Plane";
        std::cout << "\n [3] Edit Plane";
        std::cout << "\n [4] View Planes";
        std::cout << "\n [0] Exit to Main Menu\n";

        std::cin >> option;

        switch (option) {
            case '1': airline.addPlane(); break;
            case '2': ; break;
            case '3': ; break;
            case '4': ; break;
            case '0': return;

            default: std::cout << "Invalid Input \n:";
        }
    }
}


#endif //PROJETO_MENU_H
