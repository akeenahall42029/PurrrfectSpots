//
// Created by Akeena on 5/4/2024.
//

#ifndef PURRRFECTSPOTS_NAPSPOTMANAGER_H
#define PURRRFECTSPOTS_NAPSPOTMANAGER_H
#include "../database/NapspotDB.h"
#include "Napspots.h"
class NapspotManager {
private:
    NapspotDB* db;
public:
   NapspotManager();
   ~NapspotManager();
    void deleteNapSpot(int napSpotId);
    bool create_napSpot(int napSpotID, std::string location, int userId, int averageRating);



};


#endif //PURRRFECTSPOTS_NAPSPOTMANAGER_H
