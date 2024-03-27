//
// Created by Akeena on 3/25/2024.
//

#ifndef PURRRFECTSPOTS_RESERVATIONS_H
#define PURRRFECTSPOTS_RESERVATIONS_H
#include <string>
#include <random>
#include <sqlite3.h>
#include "iostream"

class Reservations {
private:
    int id;
    int napSpotId;
    int userId;
    std::string userName;
    int time ;
    std::string status;

    // Function to generate random id number for the reservation
    int generateID();
    void setNapSpotId(int napSpotId);
    void setUserId(std::string userId);
    sqlite3 *curr_db;
    std::string sql;
    int retCode = 0;
    char *zErrMsg = 0;
   //void resTime();


public:
    //Constructor
    /* id        INT   NOT NULL UNIQUE,
    napSpotId INT  NOT NULL,
    userId    INT   NOT NULL,
    time      INT NOT NULL, -- will be in minutes
    status
     * */
    Reservations(int napSpotID, int userId, std::string& userName, int time, const std::string& status);

    // Getter functions, will be useful for SQL binding
    int getID() const; // Change the return type to int
    int getNapSpotId() const;
    int getUserId() const ;
    int getTime() const;
    std::string getStatus() const;
    void storeData();






};


#endif //PURRRFECTSPOTS_RESERVATIONS_H
