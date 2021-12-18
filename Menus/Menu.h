//
// Created by zedio on 04/12/2021.
//

/**
 * @brief Menu interface to access system funcionality
 * 
 */
#ifndef PROJETO_MENU_H
#define PROJETO_MENU_H
#include <cstdlib>
#include <iostream>
#include "../Airline/Airline.h"

void main_menu(Airline &airline); //!< Start menu where the user can select customer or management options
void airport_menu(Airline &airline); //!< Airport menu where the user can select to manage planes, flights, services and boarding the passengers
void customer_menu(Airline &airline); //!< Customer menu where the user can reserve a seat for a flight, check flight schedules and reservations as well as access transport information
void transport_menu(const Airport &airport); //!< Transport menu where the user can check out avaliable transports, their distances from the airport and their schedules
void select_airport_menu(Airline &airline); //!< Selection menu where the user can select a specific airport to view transport related information for that airport
void planes_menu(Airline &airline); //!< Plane menu where the user can add or delete a plane and view, erase or save all planes
void flights_menu(Airline &airline); //!< Flight menu where the user can add or delete a flight, and view erase or save all flights
void services_menu(Airline &airline); //!< Service menu where the user can add services and check for completed or to complete services

#endif //PROJETO_MENU_H
