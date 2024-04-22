//
// Created by Akeena on 3/25/2024.
//
#include "Reservations.h"
#include <string>


// constructor
Reservations::Reservations(int napSpotID, int userId, int time,  std::string status)
        : napSpotId(napSpotID), userId(userId), time(time), status(status) {

    // open the database to prepare to pass queries


    //location and name of the datbase
    std::string db_name = "example.sqlite";
    std::string db_location = "../database";


    std::string full_name = db_location + "/" + db_name;

    // open the database and check return codes

    retCode = sqlite3_open(full_name.c_str(),&curr_db);
    if( retCode ){
        std::cerr << "Database does not open -- "
                  << sqlite3_errmsg(curr_db)
                  << std::endl;
        std::cerr << " File -- " << full_name << std::endl;
        exit(0);
    }else{
        std::cerr << "Opened database successfully\n";
    }

    id = generateID(); // generate a random 9 digit ID number
    storeData();

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
    std::cout << "\033[1;95mYour nap spot ID is: \033[0m" << napSpotId << std::endl;
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


void Reservations::storeData() {
   // sql = "INSERT INTO reservations(id, napSpotId, userId, userName, time, status) VALUES (?, ?, ?, ?, ?, ? )";

   //Initialize local vars
   retCode = 0;
   zErrMsg = 0;

   int size_value = 0;
    // Construct the SQL query for INSERT INTO reservations
    //std::string
    sql = "INSERT INTO reservations";
    sql += "(id, napSpotId, userId, time, status) ";
    sql += "VALUES (";
    sql += std::to_string(id);
    sql += ", ";
    // add userName
    sql += std::to_string(napSpotId);
    sql += ", ";
    sql += std::to_string(userId);
    sql += ", ";
    sql += userName;
    sql += ", ";
    sql += std::to_string(time);
    sql += ", '";
    sql += status;
    sql += "');";
    // Execute the SQL query
    retCode = sqlite3_exec(curr_db, sql.c_str(), 0, 0, &zErrMsg);
    if (retCode != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Record inserted successfully!" << std::endl;
    }

    // Close the database
    sqlite3_close(curr_db);

}



