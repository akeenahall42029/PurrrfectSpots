//
// Created by Akeena on 5/4/2024.
//

#include "NapspotDB.h"
NapspotDB::NapspotDB() {

}

NapspotDB::~NapspotDB() {

}
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

int NapspotDB::fetch_id(int napSpotId) {
    int id = -1; // Default value indicating ID not found

    // Check if the database is open
    if (!curr_db) {
        std::cerr << "Database not open. Call open() first." << std::endl;
        return id;
    }

    // Prepare SQL statement to fetch ID based on napSpotId
    std::string sql = "SELECT id FROM napSpots WHERE napSpotId = ?;";
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);

    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return id;
    }

    // Bind parameter (napSpotId)
    sqlite3_bind_int(stmt, 1, napSpotId);

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode == SQLITE_ROW) {
        // If a row is found, retrieve the ID
        id = sqlite3_column_int(stmt, 0);
    } else {
        // If no row is found, print an error message
        std::cerr << "No ID found for napSpotId: " << napSpotId << std::endl;
    }

    // Reset the statement for future use
    sqlite3_reset(stmt);

    return id;


}

int NapspotDB::fetch_userId(int napSpotId) {
    int userId = -1; // Default value indicating userId not found

    // Check if the database is open
    if (!curr_db) {
        std::cerr << "Database not open. Call open() first." << std::endl;
        return userId;
    }

    // Prepare SQL statement to fetch userId based on napSpotId
    std::string sql = "SELECT userId FROM napSpots WHERE napSpotId = ?;";
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);

    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return userId;
    }

    // Bind parameter (napSpotId)
    sqlite3_bind_int(stmt, 1, napSpotId);

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode == SQLITE_ROW) {
        // If a row is found, retrieve the userId
        userId = sqlite3_column_int(stmt, 0);
    } else {
        // If no row is found, print an error message
        std::cerr << "No userId found for napSpotId: " << napSpotId << std::endl;
    }

    // Reset the statement for future use
    sqlite3_reset(stmt);

    return userId;
}

std::string NapspotDB::fetch_location(int napSpotId) {
    std::string loc = "error fetching location"; // Default value indicating location not found

    // Check if the database is open
    if (!curr_db) {
        std::cerr << "Database not open. Call open() first." << std::endl;
        return loc;
    }

    // Prepare SQL statement to fetch location based on napSpotId
    std::string sql = "SELECT location FROM napSpots WHERE napSpotId = ?;";
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);

    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return loc;
    }

    // Bind parameter (napSpotId)
    sqlite3_bind_int(stmt, 1, napSpotId);

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode == SQLITE_ROW) {
        // If a row is found, retrieve the location
        loc = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    } else {
        // If no row is found, print an error message
        std::cerr << "No location found for napSpotId: " << napSpotId << std::endl;
    }

    // Reset the statement for future use
    sqlite3_reset(stmt);

    return loc;
}

void NapspotDB::deleteNapSpot(int napSpotId) {

    // Check if the database is open
    if (!curr_db) {
        std::cerr << "Database not open. Call open() first." << std::endl;
        return;
    }

    // Prepare SQL statement to delete the nap spot based on napSpotId
    std::string sql = "DELETE FROM napSpots WHERE napSpotId = ?;";
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);

    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return;
    }

    // Bind parameter (napSpotId)
    sqlite3_bind_int(stmt, 1, napSpotId);

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode != SQLITE_DONE) {
        std::cerr << "Error deleting nap spot: " << sqlite3_errmsg(curr_db) << std::endl;
    } else {
        std::cout << "Nap spot deleted successfully!" << std::endl;
    }

    // Reset the statement for future use
    sqlite3_reset(stmt);
}


