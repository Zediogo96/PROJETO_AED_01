cmake_minimum_required(VERSION 3.20)
project(PROJETO)

set(CMAKE_CXX_STANDARD 14)

add_executable(PROJETO main.cpp Utility/Time.h Airline.cpp Airline.h Plane.cpp Plane.h Flight.cpp Flight.h Utility/Date.h Utility/utility.h Menus/Menu.cpp Menus/Menu.h Services/Service.cpp Services/Service.h Services/Staff.h)
