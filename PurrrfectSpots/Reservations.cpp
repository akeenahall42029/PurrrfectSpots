//
// Created by Akeena on 3/25/2024.
//

#include "Reservations.h"
#include <random>
#include <sqlite3.h>
#include "iostream"
// constructor
Reservations::Reservations(int napSpotID, int userId, int time, const std::string& status)
        : napSpotId(napSpotID), userId(userId), time(time), status(status) {

    id = generateID(); // genereate a random 9 digit ID number
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

int Reservations::getNapSpotId() const {
    return napSpotId;
}



int Reservations::getTime() const{
    return time;
}

int Reservations::getID() const {
    return id; // id is defined as a private variable in the header, return to this if this causes problems

}
int Reservations::getUserId()  const{
    return userId;
}


std::string Reservations::getStatus() const {
    return status;
}

void Reservations::setNapSpotId(int napSpotId)  {
    napSpotId = napSpotId;
}



void Reservations::setUserId(std::string userId) {
    userId = userId;
}

/* Stores reservation info into the SQL database. Binds parameters of the SQL statement to
 * the corresponding values obtained from provided Reservation object and executes statement to
 * create a new entry in the 'reservations' table.
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

    // Bind parameters to SQL statement NOTE: this is more secure than Sql injections
    sqlite3_bind_int(sql_statement,1,reservation.getID());
    sqlite3_bind_int(sql_statement, 2, reservation.getNapSpotId());
    sqlite3_bind_int(sql_statement, 3, reservation.getUserId());
    sqlite3_bind_int(sql_statement,4,reservation.getTime());
    // creating a char pointer to the status to work around having to make status a constant variable
    const char* status_str =  reservation.getStatus().c_str();
    sqlite3_bind_text(sql_statement, 5, status_str, -1, SQLITE_STATIC);

}
