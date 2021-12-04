//
// Created by zedio on 04/12/2021.
//

#ifndef PROJETO_MENU_H
#define PROJETO_MENU_H
#include <cstdlib>
#include <iostream>
#include "../Airline.h"

#include <conio.h>

#define BLUE "\u001b[36m"
#define RED "\u001b[31m"
#define GREEN "\u001b[32m"
#define RESET "\u001b[0m"

void main_menu(Airline &airline);
void airport_menu(Airline &airline);
void planes_menu(Airline &airline);

#endif //PROJETO_MENU_H
