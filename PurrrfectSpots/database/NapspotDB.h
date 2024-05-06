//
// Created by Akeena on 5/4/2024.
//

#ifndef PURRRFECTSPOTS_NAPSPOTDB_H
#define PURRRFECTSPOTS_NAPSPOTDB_H
#include "Database.h"

class NapspotDB: public Database{
public:
    NapspotDB();
    ~NapspotDB();

    // fetchers
    int fetch_id(int napSpotId);
    int fetch_userId(int napSpotId);
    std::string fetch_location(int napSpotId);

    // Methods for admin users
    void deleteNapSpot(int napSpotId);


    bool insert_napspot(int napSpotID, std::string location, int userId, int averageRating);



};


#endif //PURRRFECTSPOTS_NAPSPOTDB_H
