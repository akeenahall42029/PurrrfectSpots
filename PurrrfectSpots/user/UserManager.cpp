/**
 * The UserManager class handles user verification and database interactions.
 * It provides methods to verify user credentials against a database and update
 * user account information.
 * @author Akeena Hall
 * @date 04/22/2024
 */

#include "UserManager.h"
#include <utility>

//UserManager::UserManager() : db(nullptr) {} // Default constructor
UserManager::UserManager() {
    db = new UserDB();
}

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
 * to intialize the id of the user
 * @param
 * */
bool UserManager::create_user(const std::string &userName, const std::string &password) {
    // Create a new UserAccount object with the provided username and password
    UserAccount newUser(userName, password);

    // Get the generated user ID from the UserAccount object
    int userId = newUser.get_id();

    // Insert the new user into the database using the UserDB object, passing the user_id
    return db->insert_user(userId, userName, password);
}