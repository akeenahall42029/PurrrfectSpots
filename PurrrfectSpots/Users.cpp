//
// Created by Akeena on 4/17/2024.
//

#include "Users.h"

Users::Users(std::string name, std::string password) : userName(name), password(password){

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
}
/* Creates a randomly generated 9-digit id number upon the creation of
 * a new reservation
 * @return randomly generated id number */

int Users::generateID() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(100000000, 999999999);

    return distrib(gen);
}

void Users::storeData() {
    // sql = "INSERT INTO reservations(id, napSpotId, userId, userName, time, status) VALUES (?, ?, ?, ?, ?, ? )";

    //Initialize local vars
    retCode = 0;
    zErrMsg = 0;

    int size_value = 0;
    // Construct the SQL query for INSERT INTO reservations
    //std::string
    sql = "INSERT INTO reservations";
    sql += "(id, name, password) ";
    sql += "VALUES (";
    sql += std::to_string(id);
    sql += ", ";
    // add userName
    sql += userName;
    sql += ", ";
    sql += password;
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