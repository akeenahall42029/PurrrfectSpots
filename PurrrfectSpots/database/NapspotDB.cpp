//
// Created by Akeena on 5/4/2024.
//

#include "NapspotDB.h"

bool NapspotDB::insert_napspot(int napSpotID, std::string location, int userId, int averageRating) {
    if (!curr_db) {
        std::cerr << "Database not open. Call open() first." << std::endl;
        return false;
    }

    std::string sql = "INSERT INTO napspots (id, location, userId, averageRating) VALUES (?, ?, ?, ?);";
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);

    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return false;
    }

    // Bind parameters
    sqlite3_bind_int(stmt, 1, napSpotID);
    sqlite3_bind_text(stmt, 2, location.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, userId);
    sqlite3_bind_int(stmt, 4, averageRating);

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode != SQLITE_DONE) {
        std::cerr << "Error inserting NapSpot: " << sqlite3_errmsg(curr_db) << std::endl;
        return false;
    } else {
        std::cout << "NapSpot inserted successfully!" << std::endl;
    }

    // Reset the statement for future use
    sqlite3_reset(stmt);

    return true;
}
