//
// Created by Akeena on 5/1/2024.
//

#ifndef PURRRFECTSPOTS_RESERVATIONMANAGER_H
#define PURRRFECTSPOTS_RESERVATIONMANAGER_H

#include <iostream>
#include "../database/ReservationDB.h"

class ReservationManager {
private:
    ReservationDB* db;
public:
    void create_reservation();

};


#endif //PURRRFECTSPOTS_RESERVATIONMANAGER_H
