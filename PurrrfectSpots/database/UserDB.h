//
// Created by Akeena on 4/22/2024.
//

#ifndef PURRRFECTSPOTS_USERDB_H
#define PURRRFECTSPOTS_USERDB_H
#include <iostream>
#include "Database.h"

class UserDB: public Database{
public:
    UserDB(const std::string &db_path);

    void fetch_userName();
    void fetch_userPassword();
    void fetch_user();
    void verify_user(std::string userName, std::string password);

};


#endif //PURRRFECTSPOTS_USERDB_H
