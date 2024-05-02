//
// Created by Akeena on 4/22/2024.
//

#include "UserDB.h"


UserDB::UserDB() {

}

UserDB::~UserDB() {

}

std::string UserDB::fetch_userName(int user_id) {
    std::string username;


    if (!curr_db) {
        std::cerr << "Database not open." << std::endl;
    }

    std::string sql = "SELECT userName FROM users WHERE id = ?;";
    sqlite3_stmt* stmt;

    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);

    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;

    }

    // Bind user_id parameter
    sqlite3_bind_int(stmt, 1, user_id);

    // Execute the statement
    retCode = sqlite3_step(stmt);

    if (retCode == SQLITE_ROW) {
        const unsigned char* userName = sqlite3_column_text(stmt, 0);
        if (userName) {
            username = reinterpret_cast<const char*>(userName);
            std::cout << "Username for user ID " << user_id << ": " << username << std::endl;
        }
    } else {
        std::cerr << "User ID not found." << std::endl;
    }
    return username;
    // Finalize the statement
    sqlite3_finalize(stmt);
}



/**  Verifies user credentials against the database.
 *
 * @param userName The username to verify.
 * @param password The password to verify.
 * */
void UserDB::verify_user(const std::string& userName, const std::string& password) {
    if (!curr_db) {
        std::cerr << "Database not open. Call open() first." << std::endl;
        return;
    }

    std::string sql = "SELECT id FROM users WHERE userName = ? AND password = ?;";
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);

    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return;
    }

    // Bind parameters
    sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_TRANSIENT);

    // Execute the statement
    retCode = sqlite3_step(stmt);

    if (retCode == SQLITE_ROW) {
        // User exists
        std::cout << "User verified successfully!" << std::endl;
        // You can fetch the user ID from the result if needed
    } else {
        // User not found or incorrect credentials
        std::cout << "Invalid username or password." << std::endl;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
}

/**
 * Fetches reservations associated with the specified user ID from the database.
 * This method executes a SQL query to retrieve reservations made by the user with the given user ID.
 * It constructs Reservation objects based on the retrieved data and returns them in a vector.
 *
 * @param user_id The ID of the user
 * @param db The SQLite database connection.
 * @return A vector containing Reservation objects representing reservations made by the user.
 */
std::vector<Reservations> UserDB::fetch_reservations(int user_id, sqlite3 *db) {
    std::vector<Reservations> reservations;

    std::string sql = "SELECT id, napSpotId, userId, time, status FROM reservations WHERE userId = " + std::to_string(user_id);

    sqlite3_stmt* stmt;
    int retCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (retCode == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            int napSpotId = sqlite3_column_int(stmt, 1);
            int userId = sqlite3_column_int(stmt, 2);
            int time = sqlite3_column_int(stmt, 3);
            std::string status = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)); // what does this line do

            Reservations reservation(napSpotId, userId, time, status); // creates reservation objectg
            reservations.push_back(reservation);
        }
    } else {
        std::cerr << "Error fetching reservations: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);

    return reservations;
}


// Fetch user reservations by user ID
std::vector<int> UserDB::fetchUserReservationsById(int userId) {
    std::vector<int> reservations;
    std::string query = "SELECT id FROM reservations WHERE userId = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(curr_db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, userId);
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            reservations.push_back(sqlite3_column_int(stmt, 0));
        }
        sqlite3_finalize(stmt);
    }

    return reservations;
}


void UserDB::insert_user(const std::string &userName, const std::string &password) {
    if (!curr_db) {
        std::cerr << "Database not open. Call open() first." << std::endl;
        return;
    }

    std::string sql = "INSERT INTO users (userName, password) VALUES (?, ?);";
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stm, nullptr);

    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return;
    }

    // Bind parameters
    sqlite3_bind_text(stm, 1, userName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stm, 2, password.c_str(), -1, SQLITE_TRANSIENT);

    // Execute the statement
    retCode = sqlite3_step(stm);
    if (retCode != SQLITE_DONE) {
        std::cerr << "Error inserting user: " << sqlite3_errmsg(curr_db) << std::endl;
    } else {
        std::cout << "User inserted successfully!" << std::endl;
    }

    // Reset the statement for future use
    sqlite3_reset(stm);

}





//std::vector<Reservations> fetch_reservations(int user_id, sqlite3* db) {
//    std::vector<Reservations> reservations;
//
//    std::string sql = "SELECT id, napSpotId, userId, time, status FROM reservations WHERE userId = " + std::to_string(user_id);
//
//    sqlite3_stmt* stmt;
//    int retCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
//
//    if (retCode == SQLITE_OK) {
//        while (sqlite3_step(stmt) == SQLITE_ROW) {
//            int id = sqlite3_column_int(stmt, 0);
//            int napSpotId = sqlite3_column_int(stmt, 1);
//            int userId = sqlite3_column_int(stmt, 2);
//            int time = sqlite3_column_int(stmt, 3);
//            std::string status = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)); // what does this line do
//
//            Reservations reservation(napSpotId, userId, time, status); // creates reservation objectg
//            reservations.push_back(reservation);
//        }
//    } else {
//        std::cerr << "Error fetching reservations: " << sqlite3_errmsg(db) << std::endl;
//    }
//
//    sqlite3_finalize(stmt);
//
//    return reservations;
//}