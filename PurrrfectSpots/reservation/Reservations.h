//
// Created by Akeena on 3/25/2024.
//

#ifndef PURRRFECTSPOTS_RESERVATIONS_H
#define PURRRFECTSPOTS_RESERVATIONS_H
#include <string>
#include <random>
#include <sqlite3.h>
#include <iostream>
#include <ctime>
class Reservations {
private:
    int napSpotId;
    int userId;
    std::string userName;
    int time;
    std::time_t startTime;
    std::time_t endTime;
    std::string status;
    int id;
    sqlite3* curr_db{};
    int retCode{};
    char* zErrMsg{};
    std::string sql;

    // Declare the method to generate ID
public:

    Reservations(int napSpotID, int userId, int time, std::string status);
    Reservations(int napSpotID, int userId, std::time_t startTime, std::time_t endTime, std::string status); // create classes from user account using this one
    Reservations(); // default constructor

    // Getter functions, will be useful for SQL binding
    int getID(); // Change the return type to int
    int getNapSpotId() const;
    int getUserId() const ;
    int getTime() const;
    std::string getStatus() const;
    int getRetCode() const;
    void setNapSpotId(int napSpotId);

    void setUserId(int userId);
    void setTime(int time);
    void setStatus(std::string status);
    void storeData();

    int generateID();
};

#endif //PURRRFECTSPOTS_RESERVATIONS_H
