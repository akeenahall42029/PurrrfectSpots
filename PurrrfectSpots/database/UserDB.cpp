//
// Created by Akeena on 4/22/2024.
//

#include "UserDB.h"


void UserDB::fetch_userName() {


}

void UserDB::fetch_userPassword() {

}

void UserDB::fetch_user() {

}

// call this method on thw login page to verify user credentials. If
/** Verifies user credientials
 * @return true if the userName and password match a result in the database, false otherwise
 *
 * */
bool UserDB::verify_user(std::string userName, std::string password) {
    std::string sql = "SELECT id FROM users WHERE userName = '" + userName + "' AND password = '" + password + "';";


    retCode = sqlite3_prepare_v2(curr_db, sql.c_str(), -1, &stmt, NULL);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        sqlite3_close(curr_db);

    }

    // Execute the statement
    retCode = sqlite3_step(stmt);
    if (retCode == SQLITE_ROW) {
        // User exists
        std::cout << "User verified successfully!" << std::endl;
        // You can fetch the user ID from the result if needed
        return true;
    } else {
        // User not found or incorrect credentials
        std::cout << "Invalid username or password." << std::endl;
        return false;
    }

}
