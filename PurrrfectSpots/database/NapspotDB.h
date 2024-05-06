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

    bool insert_napspot(int napSpotID, std::string location, int userId, int averageRating);



};


#endif //PURRRFECTSPOTS_NAPSPOTDB_H
