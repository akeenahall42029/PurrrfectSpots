//
// Created by Akeena on 4/22/2024.
//

#include "UserDB.h"
#include "../Reservations.h"

void UserDB::fetch_userName() {


}

void UserDB::fetch_userPassword() {

}

void UserDB::fetch_user() {

}

void UserDB::verify_user(const std::string& userName, const std::string& password) {
    if (!curr_db) {
        std::cerr << "Database not open. Call open() first." << std::endl;
        return;
    }

    std::string sql = "SELECT id FROM users WHERE userName = '" + userName + "' AND password = '" + password + "';";
    int retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, nullptr);

    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return;
    }

    retCode = sqlite3_step(stmt);
    if (retCode == SQLITE_ROW) {
        std::cout << "User verified successfully!" << std::endl;
    } else {
        std::cout << "Invalid username or password." << std::endl;
    }

    sqlite3_finalize(stmt); // Finalize the statement
}

std::vector<std::string> UserDB::results(const std::string& query) {
    std::vector<std::string> result_list;

    if (!curr_db) {
        std::cerr << "Database not open. Call open() first." << std::endl;
        return result_list;
    }

    int retCode = sqlite3_prepare_v2(curr_db, query.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return result_list;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* result = sqlite3_column_text(stmt, 0);
        if (result) {
            result_list.push_back(reinterpret_cast<const char*>(result));
        }
    }

    sqlite3_finalize(stmt); // Finalize the statement
    return result_list;
}

std::vector<Reservations> fetch_reservations(int user_id, sqlite3* db) {
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
            std::string status = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

            Reservations reservation(napSpotId, userId, time, status);
            reservation.setUserId(reinterpret_cast<const char *>(id)); // Make sure you have a set_id function
            reservations.push_back(reservation);
        }
    } else {
        std::cerr << "Error fetching reservations: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);

    return reservations;
}