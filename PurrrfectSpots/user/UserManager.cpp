/**
 * The UserManager class handles user verification and database interaction.
 * It provides methods to verify user credentials against a database and update
 * user account information.
 * @author Akeena Hall
 * @date 04/22/2024
 */

#include "UserManager.h"

#include <utility>

UserManager::UserManager() {}

/**
* Constructs a new UserManager instance with a specified UserDB object.
*
* @param db The UserDB object used for database interaction.
*/
UserManager::UserManager(UserDB *db) : db(db){}

/**
    * Verifies the user credentials against the database.
    * Retrieves the user information from the database and updates the UserAccount object
    * with the user ID if the verification is successful.
    *
    * @param a The UserAccount object representing the user whose credentials need to be verified.
    * @param password The password provided for verification.
    * @return Returns 1 if the verification is successful, 0 otherwise.
    */
int UserManager::verify(UserAccount &a, std::string password) {
    // Construct thr SQL query to verify user credentials
    std::string query = "SELECT id FROM users WHERE username = '" + a.get_username() + "' AND password = '" + password + "';";

    // Verify user credentials with the database
    db->verify_user(a.get_username(), password);

    // Check if the database query returned any results
    std::vector<std::string> results = db->results(query);
    if (!results.empty()) {
        // Extract the user ID from the results and set it in the UserAccount object
        a.set_id(std::stoi(results[0])); // Assuming the user ID is the first result
        return 1; // Verification successful
    } else {
        return 0; // Verification failed
    }
}