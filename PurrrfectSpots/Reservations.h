//
// Created by Akeena on 3/25/2024.
//

#ifndef PURRRFECTSPOTS_RESERVATIONS_H
#define PURRRFECTSPOTS_RESERVATIONS_H
#include <string>
#include <random>
#include <sqlite3.h>
#include <iostream>

class Reservations {
private:
    int napSpotId;
    int userId;
    std::string userName;
    int time;
    std::string status;
    int id;
    sqlite3* curr_db;
    int retCode;
    char* zErrMsg;
    std::string sql;

    int generateID(); // Declare the method to generate ID
public:

    Reservations(int napSpotID, int userId, int time, std::string status);
    Reservations(); // default constructor
    // Getter functions, will be useful for SQL binding
    int getID() const; // Change the return type to int
    int getNapSpotId() const;
    int getUserId() const ;
    int getTime() const;
    std::string getStatus() const;

    void setNapSpotId(int napSpotId);

    void setUserId(std::string userId);

    void storeData();
};

#endif //PURRRFECTSPOTS_RESERVATIONS_H
