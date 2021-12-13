cmake_minimum_required(VERSION 3.20)
project(PROJETO)

set(CMAKE_CXX_STANDARD 14)


add_executable(PROJETO main.cpp Utility/Time.h Airline.cpp Airline.h Plane.cpp Plane.h Flight.cpp Flight.h Utility/Date.h Utility/utility.h Menus/Menu.cpp Menus/Menu.h Services/Staff.h Services/Service.cpp Services/Service.h Passenger/Passenger.cpp Passenger/Passenger.h Transports/Transport.h Transports/Transport.cpp Baggage.cpp Baggage.h BaggageCarriage.cpp BaggageCarriage.h BaggageCart.cpp BaggageCart.h)

