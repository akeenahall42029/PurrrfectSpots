cmake_minimum_required(VERSION 3.27)

project(coral1)

set(CMAKE_CXX_STANDARD 14)
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(PurrrfectSpots)

add_executable(coral1
        PurrrfectSpots/Demo.cpp
        PurrrfectSpots/Demo.h
        PurrrfectSpots/main.cpp
        PurrrfectSpots/MyButton.cpp
        PurrrfectSpots/MyButton.h
        PurrrfectSpots/MyDisplayBuffer.cpp
        PurrrfectSpots/MyDisplayBuffer.h
        PurrrfectSpots/MyValue.cpp
        PurrrfectSpots/MyValue.h
        PurrrfectSpots/Reservations.cpp
        PurrrfectSpots/Reservations.h)
add_executable(unittest
        unit_tests/ReservationsTests.cpp
)
include_directories(googletest googletest/include googletest/include/gtest)
add_executable(unittests googletest/src/gtest-all.cc)
target_link_libraries(unittests sqlite3 gtest gtest_main )
target_link_libraries(coral1 sqlite3 ${GTKMM_LIBRARIES})
