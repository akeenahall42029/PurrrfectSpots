//
// Created by Akeena on 4/22/2024.
//

#ifndef PURRRFECTSPOTS_USERACCOUNT_H
#define PURRRFECTSPOTS_USERACCOUNT_H
/**
 * Handles all account information
 */

#include "../database/UserDB.h"

class UserAccount {


    friend class UserManager;
private:
    int id;
    int access; // change to enum : 0 for cats, 1 for pet owners, 2 for app admin
    std::string userName;
public:
    UserAccount();
    UserAccount(std::string userName,int id);
    UserAccount(std::string userName);
    UserAccount(std::string userName, std::string password)
    ~UserAccount();

    int get_id();
    std::string get_userName();
    void set_userName(std::string u);
    void set_id(int newId);
    int generateId();

};


#endif //PURRRFECTSPOTS_USERACCOUNT_H
