//
// Created by Akeena on 3/25/2024.
//

#include "Reservations.h"
#include <random>
#include <sqlite3.h>
#include "iostream"
// constructor
Reservations::Reservations(const std::string &napSpotID, const std::string &userName) {
    id = generateID();

}

/* Creates a randomly generated 9-digit id number upon the creation of
 * a new reservation
 * @return randomly generated id number */

int Reservations::generateID() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(100000000, 999999999);

    return distrib(gen);
}

std::string Reservations::getNapSpotId() const {
    return napSpotId;
}

std::string Reservations::getUserName() const {
    return userName;
}

int Reservations::getTime() {
    return time;
}

int Reservations::getID() const {
    return id; // id is defined as a private variable in the header, return to this if this causes problems

}
std::string Reservations::getUserId() const {
    return userId;
}


std::string Reservations::getStatus() {
    return status;
}

void Reservations::setNapSpotId(int napSpotId) {
    napSpotId = napSpotId;
}

void Reservations::setUserName(std::string userName) {
    userName = userName;
}

void Reservations::setUserId(std::string userId) {
    userId = userId;
}

/* Bonds connection between userInput when a user creates a new reservation and adds
 * an entry to the reservations table.
 * @param reservation object reservation
 * */


void storeData(const Reservations& reservation){
    sqlite3* db; // access sqlite database using a pointer
    int rc = sqlite3_open("build_tables.sql", &db); // rc--> return code
    if(rc) {
        std::cerr << "Error opening SQlite database" << sqlite3_errmsg(db) << std::endl;
        return;

    }

    //Prepare the sqlite statement to add info to database
    sqlite3_stmt* sql_statement;
    const char* sql = "INSERT INTO reservations (id, napSpotId, userId, time, status) VALUES (?, ?, ?, ?, ?)";
    rc = sqlite3_prepare_v2(db,sql,-1,&sql_statement,NULL); // prepare parameters: database handle, sql statement, max length of bytes, pointer to statement
    if(rc !=SQLITE_OK){
        std::cerr << "Error preparing SQL statement" << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Bind paremeters to SQL statement NOTE: this is more secure than Sql insections
    sqlite3_bind_int(sql_statement,1,reservation.getID());
    sqlite3_bind_text(sql_statement,2,reservation.getNapSpotId().c_str(),-1,SQLITE_STATIC);

}
