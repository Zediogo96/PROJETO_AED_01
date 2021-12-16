//
// Created by zedio on 04/12/2021.
//

#ifndef PROJETO_MENU_H
#define PROJETO_MENU_H
#include <cstdlib>
#include <iostream>
#include "../Airline.h"

void main_menu(Airline &airline);
void airport_menu(Airline &airline);
void costumer_menu(Airline &airline);
void transport_menu(const Airport &airport);
void select_airport_menu(Airline &airline);
void planes_menu(Airline &airline);
void flights_menu(Airline &airline);
void services_menu(Airline &airline);

#endif //PROJETO_MENU_H
