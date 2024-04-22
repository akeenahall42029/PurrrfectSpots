//
// Created by Akeena on 4/22/2024.
//

#ifndef PURRRFECTSPOTS_USERMANAGER_H
#define PURRRFECTSPOTS_USERMANAGER_H
#include "../database/UserDB.h" // opens the database
#include "UserAccount.h"

class UserManager{
public:
    UserManager();
    UserManager(UserDB* db);

    int verify(UserAccount& a, std::string username);

private:
    UserDB* db;
};
#endif //PURRRFECTSPOTS_USERMANAGER_H
