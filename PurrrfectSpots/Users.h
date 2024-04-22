//
// Created by Akeena on 4/17/2024.
//

#ifndef PURRRFECTSPOTS_USERS_H
#define PURRRFECTSPOTS_USERS_H
#include "istream"
#include "string"
#include <iostream>
#include "random"
#include <sqlite3.h>
class Users {
private:
    int id; // this is generated in the constructor and passed to the database; no need to make it a parameter
    std::string userName;
    std::string password;
    int generateID();
    //variables for database connections
    int retCode;
    char* zErrMsg;
    sqlite3* curr_db;
    std::string sql;

    // I still need to figure out linking the reservation and review objects
    // I'm not sure if I want to save each reservation and review in an array
    // it depends on how this will connect to the front-end
public:
    Users(std::string name, std::string password);
    void storeData();
    Users(); // default constuctor


};


#endif //PURRRFECTSPOTS_USERS_H
