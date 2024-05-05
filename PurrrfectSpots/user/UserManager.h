//
// Created by Akeena on 4/22/2024.
//

#ifndef PURRRFECTSPOTS_USERMANAGER_H
#define PURRRFECTSPOTS_USERMANAGER_H
#include "../database/UserDB.h" // opens the database
#include "UserAccount.h"

class UserManager {
public:
    UserManager(); // Default constructor
    UserManager(UserDB *db = nullptr); // Constructor with optional UserDB parameter

    int verify(UserAccount &a, std::string password);
    void create_user(const std::string &userName, const std::string &password);

private:
    UserDB *db; // Ensure this is declared properly in the class
    int verify(UserAccount &a, const std::string &password);
};

#endif //PURRRFECTSPOTS_USERMANAGER_H
