cmake_minimum_required(VERSION 3.22)
project(PurrrfectSpots)

set(CMAKE_CXX_STANDARD 17)


add_executable(PurrrfectSpots main.cpp
        Demo.cpp
        Demo.h
        Reservations.cpp
        Reservations.h)

target_link_libraries(PurrrfectSpots sqlite3)
