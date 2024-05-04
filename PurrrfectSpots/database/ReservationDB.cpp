//
// Created by Akeena on 5/1/2024.
//

#include "ReservationDB.h"

ReservationDB::ReservationDB() {
    // default constructor should open DB from inherting Database
}

ReservationDB::~ReservationDB() {

}

int ReservationDB::fetch_id(int reservationId) {
    int id = -1; // Initialize with a default value

    // Construct the SQL query to fetch the ID from the reservations table
    std::string sql = "SELECT id FROM reservations WHERE id = " + std::to_string(reservationId) + ";";

    // Execute the SQL query
    sqlite3_stmt* stmt;
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode == SQLITE_OK) {
        // Fetch the result
        retCode = sqlite3_step(stmt);
        if (retCode == SQLITE_ROW) {
            // Extract the ID from the result
            id = sqlite3_column_int(stmt, 0);
        }
    } else {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

    return id;
}


