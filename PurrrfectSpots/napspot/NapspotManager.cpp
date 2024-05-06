//
// Created by Akeena on 5/4/2024.
//

#include "NapspotManager.h"

NapspotManager::NapspotManager() {
    db = new NapspotDB();

}

NapspotManager::~NapspotManager() {

}
void NapspotManager::deleteNapSpot(int napSpotId) {
    db->deleteNapSpot(napSpotId);
}

bool NapspotManager::create_napSpot(int napSpotID, std::string location, int userId, int averageRating) {
   Napspots newNapSpot(location, userId, averageRating);
   return db->insert_napspot(newNapSpot.getId(),location,userId,averageRating);
}



