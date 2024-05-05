/**
 * The UserManager class handles user verification and database interactions.
 * It provides methods to verify user credentials against a database and update
 * user account information.
 * @author Akeena Hall
 * @date 04/22/2024
 */

#include "UserManager.h"
#include <utility>

UserManager::UserManager() : db(nullptr) {} // Default constructor

/**
* Constructs a new UserManager instance with a specified UserDB object.
*
* @param db The UserDB object used for database interaction.
*/
UserManager::UserManager(UserDB *db) : db(db) {} // Constructor with parameter

/**
    * Verifies the user credentials against the database.
    * Retrieves the user information from the database and updates the UserAccount object
    * with the user ID if the verification is successful.
    *
    * @param a The UserAccount object representing the user whose credentials need to be verified.
    * @param password The password provided for verification.
    * @return Returns 1 if the verification is successful, 0 otherwise.
    */
int UserManager::verify(UserAccount &a, const std::string &password) {
    // Construct a parameterized SQL query to verify user credentials
    std::string query = "SELECT id FROM users WHERE username = ? AND password = ?;"; // Parameterized query

    // Prepare the SQL statement
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(reinterpret_cast<sqlite3 *>(db), query.c_str(), -1, &stmt, nullptr);

    // Bind the username and password to the query
    sqlite3_bind_text(stmt, 1, a.get_userName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_TRANSIENT);

    int rc = sqlite3_step(stmt); // Execute the statement
    if (rc == SQLITE_ROW) {
        int user_id = sqlite3_column_int(stmt, 0); // Retrieve the user ID
        a.set_id(user_id); // Set the user ID in the UserAccount
        sqlite3_finalize(stmt); // Finalize the statement
        return 1; // Verification successful
    } else {
        sqlite3_finalize(stmt); // Finalize the statement
        return 0; // Verification failed
    }
}

// Method to create a new user
/** Creates a new user by using the UserAccount method. Will call the generateId method
 * to initilze the id of the user
 * */
void UserManager::create_user(const std::string &userName, const std::string &password) {
    try {
        std::string query = "INSERT INTO users (username, password) VALUES (?, ?);";

        sqlite3_stmt* stmt;
        int result = sqlite3_prepare_v2(reinterpret_cast<sqlite3 *>(db), query.c_str(), -1, &stmt, nullptr);
        if (result != SQLITE_OK) {
            throw std::runtime_error("Error preparing SQL statement: " + std::string(sqlite3_errmsg(
                    reinterpret_cast<sqlite3 *>(db))));
        }

        // Bind parameters
        sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_TRANSIENT);

        result = sqlite3_step(stmt); // Execute the query
        sqlite3_finalize(stmt); // Finalize the statement

        if (result != SQLITE_DONE) {
            throw std::runtime_error("Error inserting into the users table");
        }

    } catch (const std::exception &e) {
        std::cerr << "Exception during create_user: " << e.what() << std::endl;
        // Handle the exception or rethrow it
        throw; // Optional: rethrow the exception for higher-level handling
    }
}