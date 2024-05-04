cmake_minimum_required(VERSION 3.22)
#set(CMAKE_OSX_ARCHITECTURES arm64)
#remeber to comment out-Sanaa
project(PurrrfectSpots)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(/user/include)
link_directories(/usr/lib)

add_executable(PurrrfectSpots main.cpp
        reservation/Reservations.cpp
        reservation/Reservations.h
        ui/MyButton.cpp
        ui/MyButton.h
        MyValue.cpp
        MyValue.h
        MyDisplayBuffer.cpp
        MyDisplayBuffer.h
        database/UserDB.cpp
        database/UserDB.h
        database/Database.cpp
        database/Database.h
        user/UserManager.cpp
        user/UserManager.h
        user/UserAccount.cpp
        user/UserAccount.h
        ui/Profile.cpp
        ui/Profile.h
        napspot/Napspots.cpp
        napspot/Napspots.h
        napspot/Napspots.h
        napspot/Napspots.h
        review/Reviews.cpp
        review/Reviews.h
        review/Reviews.h
        admin/Admins.cpp
        admin/Admins.h
        admin/Admins.h
        ui/SpotStructure.cpp
        ui/SpotStructure.h
        ui/Rating.cpp
        ui/Rating.h
        ui/NotebookManager.cpp
        ui/NotebookManager.h
        database/ReservationDB.cpp
        database/ReservationDB.h

)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(/user/include)
link_directories(/usr/lib)
add_executable(Profilescreen ui/Profile.cpp ui/Profile.h
        reservation/ReservationManager.cpp
        reservation/ReservationManager.h)

include_directories(googletest googletest/include googletest/include/gtest)
add_executable(unittests googletest/src/gtest-all.cc
        unit_tests/ReservationTests.cpp
        unit_tests/ReservationTests.h
        unit_tests/DatabaseTest.cpp
        unit_tests/DatabaseTest.h
        database/Database.cpp
        database/Database.h
        database/UserDB.cpp
        database/UserDB.h
        unit_tests/UserDBTests.cpp
        reservation/Reservations.cpp
        reservation/Reservations.h
        unit_tests/SpotTests.cpp
        ui/SpotStructure.h
        ui/SpotStructure.cpp
)

#include_directories(googletest googletest/include googletest/include/gtest)
#add_executable(unittests googletest/src/gtest-all.cc
#        unit_tests/ReservationsTests.cpp
#        Reservations.h
#        Reservations.cpp
#
#
#)
target_link_libraries(unittests sqlite3)
target_link_libraries(PurrrfectSpots sqlite3 ${GTKMM_LIBRARIES})
target_link_libraries(Profilescreen ${GTKMM_LIBRARIES})

