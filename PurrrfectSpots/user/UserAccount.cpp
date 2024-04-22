//
// Created by Akeena on 4/22/2024.
//
/**
 * Handles all account information
 */
#include "UserAccount.h"

UserAccount::UserAccount() : username(""), id(-1){}

UserAccount::~UserAccount(){}

UserAccount::UserAccount(std::string username) : username(username) {}

std::string UserAccount::get_username() {return username;}
int UserAccount::get_id() {return id;}

void UserAccount::set_username(std::string u) {
    if(username == u) return;
    username =u;
}
void UserAccount::set_id(int newId) {
    id = newId;
}
