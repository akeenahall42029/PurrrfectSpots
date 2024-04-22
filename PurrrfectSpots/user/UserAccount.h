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
public:
    UserAccount();
    UserAccount(std::string username);

    ~UserAccount();

    int get_id();
    std::string get_username();
    void set_username(std::string u);
    void set_id(int newId);
private:
    int id;
    int access;
    std::string username;
};


#endif //PURRRFECTSPOTS_USERACCOUNT_H
