//
// Created by Akeena on 5/1/2024.
//

#include "ReservationDB.h"
#include <ctime>
ReservationDB::ReservationDB() {
    // default constructor should open DB from inherting Database
}

ReservationDB::~ReservationDB() {
    //default destructor should close DB from inherited Database

}
/** Fetches the ID of a reservation from the database based on the given reservation ID.
 * @param reservationId the id of the reservations
 * @return id of the reservation, -1 if there's an error
 * */
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
/** Fetches the napSpot id associated with a reservation
 * @param reservation_id the id of the reservation
 * @ return the napSpot associated with the reservations
 * */

int ReservationDB::fetch_napSpotID(int reservation_id) {
    if (!curr_db) {
        std::cerr << "Database not open." << std::endl;
        return -1; // Return -1 to indicate error
    }
    // find
    std::string sql = "SELECT napSpotId FROM reservations WHERE id = ?;";
    sqlite3_stmt* stmt;

    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return -1; // Return -1 to indicate error
    }

    // Bind reservationId parameter
    sqlite3_bind_int(stmt, 1, reservation_id);

    // Execute the statement
    retCode = sqlite3_step(stmt);

    if (retCode == SQLITE_ROW) {
        int napSpotId = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt); // Finalize the statement
        return napSpotId;
    } else {
        std::cerr << "Reservation ID not found." << std::endl;
        sqlite3_finalize(stmt); // Finalize the statement
        return -1; // Return -1 to indicate error
    }
}

int ReservationDB::fetch_userId(int reservation_id) {
    if(!curr_db){
        std::cerr << "Database does not open -- "
                  << sqlite3_errmsg(curr_db)
                  << std::endl;
        return -1;
    }
    std::string sql = "SELECT userId FROM reservations WHERE id = ?";
    sqlite3_stmt* stmt;

    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return -1; // Return -1 to indicate error
    }

    // Bind reservationId parameter
    sqlite3_bind_int(stmt, 1, reservation_id);

    // Execute the statement
    retCode = sqlite3_step(stmt);

    if (retCode == SQLITE_ROW) {
        int userId = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt); // Finalize the statement
        return userId;
    } else {
        std::cerr << "Reservation ID not found." << std::endl;
        sqlite3_finalize(stmt); // Finalize the statement
        return -1; // Return -1 to indicate error
    }
}

int ReservationDB::fetch_startTime(int reservation_id) {
    int startTime = -1; // inital value, will return if error
    if(!curr_db){
        std::cerr << "Database does not open -- "
                  << sqlite3_errmsg(curr_db)
                  << std::endl;
        return startTime;
    }
    std::string sql = "SELECT startTime FROM reservations WHERE id = ?";
    sqlite3_stmt* stmt;

    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return startTime; // Return -1 to indicate error
    }

    // Bind reservationId parameter
    sqlite3_bind_int(stmt, 1, reservation_id);

    // Execute the statement
    retCode = sqlite3_step(stmt);

    if (retCode == SQLITE_ROW) {
        startTime = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt); // Finalize the statement
        return startTime;
    } else {
        std::cerr << "Reservation ID not found." << std::endl;
        sqlite3_finalize(stmt); // Finalize the statement
        return startTime; // Return -1 to indicate error
    }
}

int ReservationDB::fetch_endTime(int reservation_id) {
    int endTime = -1;
    if(!curr_db){
        std::cerr << "Database does not open -- "
                  << sqlite3_errmsg(curr_db)
                  << std::endl;
        return endTime;
    }
    std::string sql = "SELECT userId FROM reservations WHERE id = ?";
    sqlite3_stmt* stmt;

    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return endTime; // Return -1 to indicate error
    }

    // Bind reservationId parameter
    sqlite3_bind_int(stmt, 1, reservation_id);

    // Execute the statement
    retCode = sqlite3_step(stmt);

    if (retCode == SQLITE_ROW) {
        endTime = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt); // Finalize the statement
        return endTime;
    } else {
        std::cerr << "Reservation ID not found." << std::endl;
        sqlite3_finalize(stmt); // Finalize the statement
        return endTime; // Return -1 to indicate error
    }
}
std::string ReservationDB::fetch_status(int reservation_id) {
    std::string status = "error";
    if (!curr_db) {
        std::cerr << "Database does not open -- " << sqlite3_errmsg(curr_db) << std::endl;
        return status;
    }

    std::string sql = "SELECT status FROM reservations WHERE id = ?";
    sqlite3_stmt* stmt;

    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return status;
    }

    // Bind reservationId parameter
    sqlite3_bind_int(stmt, 1, reservation_id);

    // Execute the statement
    retCode = sqlite3_step(stmt);

    if (retCode == SQLITE_ROW) {
        // Retrieve the status as a string
        const unsigned char* statusText = sqlite3_column_text(stmt, 0);
        if (statusText) {
            status = reinterpret_cast<const char*>(statusText);
        }
    } else {
        std::cerr << "Reservation ID not found." << std::endl;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

    return status;
}

void ReservationDB::modifyStatus(int reservation_id, std::string newStatus) {

    if (!curr_db) {
        std::cerr << "Database does not open -- " << sqlite3_errmsg(curr_db) << std::endl;
    }
    // Construct the SQL query to update the status
    std::string sql = "UPDATE reservations SET status = ? WHERE id = ?";
    sqlite3_stmt* stmt;

    // Prepare the SQL statement
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return;
    }

    // Bind parameters
    sqlite3_bind_text(stmt, 1, newStatus.c_str(), -1, SQLITE_TRANSIENT); // Bind new status
    sqlite3_bind_int(stmt, 2, reservation_id); // Bind reservation ID

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode != SQLITE_DONE) {
        std::cerr << "Error updating status: " << sqlite3_errmsg(curr_db) << std::endl;
    } else {
        std::cout << "Status updated successfully!" << std::endl;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
}

void ReservationDB::deleteNapSpot(int reservation_id) {
    if (!curr_db) {
        std::cerr << "Database does not open -- " << sqlite3_errmsg(curr_db) << std::endl;
    }
    // Construct the SQL query to delete the entry
    std::string sql = "DELETE FROM reservations WHERE id = ?";
    sqlite3_stmt* stmt;

    // Prepare the SQL statement
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return;
    }

    // Bind the reservation ID parameter
    sqlite3_bind_int(stmt, 1, reservation_id);

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode != SQLITE_DONE) {
        std::cerr << "Error deleting entry: " << sqlite3_errmsg(curr_db) << std::endl;
    } else {
        std::cout << "Entry deleted successfully!" << std::endl;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
}

void ReservationDB::modifyStartTime(int reservation_id, int newStartTime) {

    if (!curr_db) {
        std::cerr << "Database does not open -- " << sqlite3_errmsg(curr_db) << std::endl;
    }
    // Construct the SQL query to update the status
    std::string sql = "UPDATE reservations SET status = ? WHERE id = ?";
    sqlite3_stmt* stmt;

    // Prepare the SQL statement
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return;
    }

    // Bind parameters
    sqlite3_bind_int(stmt, 1, newStartTime); // Bind new status
    sqlite3_bind_int(stmt, 2, reservation_id); // Bind reservation ID

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode != SQLITE_DONE) {
        std::cerr << "Error updating status: " << sqlite3_errmsg(curr_db) << std::endl;
    } else {
        std::cout << "Status updated successfully!" << std::endl;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

}
void ReservationDB::modifyEndTime(int reservation_id, int newEndTime) {
    if (!curr_db) {
        std::cerr << "Database does not open -- " << sqlite3_errmsg(curr_db) << std::endl;
    }
    // Construct the SQL query to update the status
    std::string sql = "UPDATE reservations SET status = ? WHERE id = ?";
    sqlite3_stmt* stmt;

    // Prepare the SQL statement
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return;
    }

    // Bind parameters
    sqlite3_bind_int(stmt, 1, newEndTime); // Bind new status
    sqlite3_bind_int(stmt, 2, reservation_id); // Bind reservation ID

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode != SQLITE_DONE) {
        std::cerr << "Error updating status: " << sqlite3_errmsg(curr_db) << std::endl;
    } else {
        std::cout << "Status updated successfully!" << std::endl;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
}
void ReservationDB::insert_reservation(int napSpotId, int userId, std::string userName, int startTime, int endTime,
                                       std::string status) {
    if (!curr_db) {
        std::cerr << "Database does not open -- " << sqlite3_errmsg(curr_db) << std::endl;
        return;
    }

    // Construct the SQL query to insert the reservation
    std::string sql = "INSERT INTO reservations (napSpotId, userId, userName, startTime, endTime, status) "
                      "VALUES (?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    // Prepare the SQL statement
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return;
    }

    // Bind parameters
    sqlite3_bind_int(stmt, 1, napSpotId);
    sqlite3_bind_int(stmt, 2, userId);
    sqlite3_bind_text(stmt, 3, userName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, startTime);
    sqlite3_bind_int(stmt, 5, endTime);
    sqlite3_bind_text(stmt, 6, status.c_str(), -1, SQLITE_TRANSIENT);

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode != SQLITE_DONE) {
        std::cerr << "Error inserting reservation: " << sqlite3_errmsg(curr_db) << std::endl;
    } else {
        std::cout << "Reservation inserted successfully!" << std::endl;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

}





