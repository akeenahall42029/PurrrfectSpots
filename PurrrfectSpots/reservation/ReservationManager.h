//
// Created by Akeena on 5/1/2024.
//

#ifndef PURRRFECTSPOTS_RESERVATIONMANAGER_H
#define PURRRFECTSPOTS_RESERVATIONMANAGER_H

#include <iostream>
#include "../database/ReservationDB.h"
#include "Reservations.h"
class ReservationManager {
private:
    ReservationDB* db;
public:
    ReservationManager(ReservationDB *db);
    ReservationManager();
    ~ReservationManager();

    // reservation management
    void create_reservation(int napSpotID, int userId, std::string userName, std::time_t startTime, std::time_t endTime, std::string status);
    void cancel_reservation(int reservation_id);
    bool check_availability(int napSpotID, std::time_t startTime, std::time_t endTime);
    void modifyStartTime(int reservation_id, time_t newStartTime);
    void modifyEndTime(int reservation_id, time_t newEndTime);
    void modifyStatus(int reservation_id, std::string newStatus);

    // retrieve info from a reservation
    int get_napSpot(int reservation_id);

};




#endif //PURRRFECTSPOTS_RESERVATIONMANAGER_H
