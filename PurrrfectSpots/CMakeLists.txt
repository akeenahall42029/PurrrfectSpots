cmake_minimum_required(VERSION 3.22)
project(PurrrfectSpots)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(PurrrfectSpots main.cpp
        Demo.cpp
        Demo.h
        Reservations.cpp
        Reservations.h
        MyButton.cpp
        MyButton.h)

target_link_libraries(PurrrfectSpots sqlite3 ${GTKMM_LIBRARIES})

