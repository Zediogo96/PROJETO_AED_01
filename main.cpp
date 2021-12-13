#include <iostream>

#include "Utility/Time.h"
#include "Utility/utility.h"
#include "Transports/Transport.h"
#include "Airline.h"
#include "Menus/Menu.h"

using namespace std;

void testAddPlane() {
    Airline airline("TAP", 100);
    airline.addPlane();
    airline.printPlanes();
    airline.sortPlanes();
    airline.printPlanes();
}

void testSavePlanes() {
    Airline airline("TAP", 100);
    airline.addPlane();
    airline.addPlane();
    airline.SavePlanes();
}

void testLoadPlanes() {
    Airline airline("TAP", 100);
    airline.LoadPlanes();
    airline.printPlanes();
}

void testMenus() {
    Airline airline("Tap", 100);
    main_menu(airline);
}
void testDate_now() {
    Date date;
    date.now();
    std::cout << date.getYear() << " " << date.getMonth() << " " << date.getDay();
}

void test() {
    Airline airline("Tap", 100);
    airline.LoadPlanes();
    airline.LoadFlights();
    main_menu(airline);
}

void transporttest(){
    Time t1(9,00);
    Time t2(9,15);
    Time t3(9,30);
    Time t4(9,45);
    Time t5(10,00);
    Time t6(10,15);
    Time t7(10,30);
    Time t8(10,45);
    Time t9(11,00);
    vector<Time> v1;
    v1.push_back(t1);
    v1.push_back(t2);
    v1.push_back(t3);
    v1.push_back(t4);
    v1.push_back(t5);
    v1.push_back(t6);
    v1.push_back(t7);
    v1.push_back(t8);
    v1.push_back(t9);
    int distance = 24;
    type trans = type::METRO;
    Transport p1(trans, distance, v1);
    p1.printSchedule();
}

int main() {
    test();
    return 0;
}