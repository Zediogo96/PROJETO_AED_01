cmake_minimum_required(VERSION 3.20)
project(PROJETO)

set(CMAKE_CXX_STANDARD 14)

add_executable(PROJETO main.cpp Utility/Time.h Airline.cpp Airline.h Plane.cpp Plane.h Flight.cpp Flight.h Utility/Date.h Utility/utility.h Menus/Menu.cpp Menus/Menu.h Services/Staff.h Services/Service.cpp Services/Service.h Passenger/Passenger.cpp Passenger/Passenger.h Transports/Transport.h Transports/Transport.cpp Baggage/Baggage.cpp Baggage/Baggage.h Baggage/BaggageCarriage.cpp Baggage/BaggageCarriage.h Baggage/BaggageCart.cpp Baggage/BaggageConveyor.h Baggage/BaggageConveyor.cpp binaryTree.h Airport.cpp Airport.h Passenger/Seat.h Passenger/Ticket.h)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
        COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
