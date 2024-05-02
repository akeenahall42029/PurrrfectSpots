//
// Created by Akeena on 4/22/2024.
//

#ifndef PURRRFECTSPOTS_USERDB_H
#define PURRRFECTSPOTS_USERDB_H
#include <iostream>
#include "Database.h"
#include <sqlite3.h>
#include <string>
#include <vector> // For std::vector
#include "../Reservations.h"

class UserDB : public Database{
private:
    sqlite3_stmt* stm;
    int rectCode;
public:
    // Constructor to initialize the database connection
    UserDB();



    // Method to verify a user in the database
    void verify_user(const std::string& userName, const std::string& password);


    // Fetch user information directly from the DB
    std::string fetch_userName(int user_id);
   //  void fetch_user();

    std::vector<Reservations> fetch_reservations(int user_id, sqlite3* db); // need to fix this, doesn't match the structure
    std::vector<int> fetchUserReservationsById(int userId);
    void insert_user(const std::string& userName, const std::string& password);

    // bool verify_user(std::string , userName, std::string password);



    // Destructor to close the database connection
    ~UserDB();

};

#endif //PURRRFECTSPOTS_USERDB_H
