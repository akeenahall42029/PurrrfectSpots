//
// Created by Akeena on 5/1/2024.
//

#ifndef PURRRFECTSPOTS_RESERVATIONDB_H
#define PURRRFECTSPOTS_RESERVATIONDB_H


#include "Database.h"

class ReservationDB: public Database {
private:
public:
    ReservationDB(); // opens the database
    ~ReservationDB(); // destructor


    // Retrive data from the reservations db
    int fetch_id(int reservationId);
    int fetch_napSpotID();
    std::string fetch_userName();
    int fetch_startTime();
    int fetch_endTime();
    std::string fetch_status();


    // Methods for admin users
    void modifyStatus(); // will modify the status entry of the db
    void deleteNapSpot(); // will remove the entry from the database

    // Methods for regular pet/owner users
    void modifyStartTime();
    void modifyEndTime();
    void insert_reservation(); // stores reservation details into the db, ReservationManager will call this passing parameters to reservation object
};


#endif //PURRRFECTSPOTS_RESERVATIONDB_H
