//
// Created by Akeena on 5/1/2024.
//

#ifndef PURRRFECTSPOTS_RESERVATIONDB_H
#define PURRRFECTSPOTS_RESERVATIONDB_H


#include "Database.h"
#include "../reservation/Reservations.h"
#include <ctime>
#include <vector>
class ReservationDB: public Database {
private:
public:
    ReservationDB(); // opens the database
    ~ReservationDB(); // destructor


    // Retrive data from the reservations db
    int fetch_id(int reservationId);
    int fetch_napSpotID(int reservation_id);
    int fetch_userId(int reservation_id);
    int fetch_startTime(int reservation_id);
    int fetch_endTime(int reservation_id);
    std::string fetch_status(int reservation_id);
    bool check_availability(int napSpotID, std::time_t startTime, std::time_t endTime);

    // Methods for admin users
    void modifyStatus(int reservation_id,std::string newStatus); // will modify the status entry of the db
    void deleteReservation(int reservation_id); // will remove the entry from the database

    // Methods for regular pet/owner users
    void modifyStartTime(int reservation_id, int newStartTime);
    void modifyEndTime(int reservation_id, int newEndTime);
    void insert_reservation(int napSpotId, int userId, std::string userName,std::time_t startTime, std::time_t  endTime, std::string status); // stores reservation details into the db, ReservationManager will call this passing parameters to reservation object
    std::vector<Reservations> getReservationsForNapSpot(int napSpotID);
};


#endif //PURRRFECTSPOTS_RESERVATIONDB_H
