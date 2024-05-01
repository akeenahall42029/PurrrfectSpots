//
// Created by Akeena on 4/22/2024.
//

#ifndef PURRRFECTSPOTS_USERMANAGER_H
#define PURRRFECTSPOTS_USERMANAGER_H
#include "../database/UserDB.h" // opens the database
#include "UserAccount.h"

class UserManager{

private:
    UserDB* db;
public:
    UserManager();
    UserManager(UserDB* db);

    int verify(UserAccount& a, std::string username);
    // Method to insert a new user into the database, call for sign in
    void create_user(const std::string& userName, const std::string& password);

};
#endif //PURRRFECTSPOTS_USERMANAGER_H
