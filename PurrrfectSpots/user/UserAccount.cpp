//
// Created by Akeena on 4/22/2024.
//
/**
 * Handles all account information
 */
#include "UserAccount.h"

/** This constructor will be used to create a new user object
 * */
UserAccount::UserAccount(std::string userName, int id) : userName(userName), id(id){
 access = 0; //represents cat user


}

UserAccount::~UserAccount(){
    id = generateId();
}

//UserAccount::UserAccount(std::string username) : username(username) {}

std::string UserAccount::get_userName() {return userName;}

int UserAccount::get_id() {return id;}

void UserAccount::set_userName(std::string u) {
    if(userName == u) return;
    userName =u;
}
void UserAccount::set_id(int newId) {
    id = newId;
}

/* Will be used by AccountManager to create new accounts
 * Creates a randomly generated 9-digit id number upon the creation of
 * a new reservation
 * @return randomly generated id number
 * */

int UserAccount::generateId() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(100000000, 999999999);

    return distrib(gen);
}

UserAccount::UserAccount(std::string userName): userName(userName) {

}

UserAccount::UserAccount(std::string userName, std::string password) {

}


