//
// Created by Akeena on 4/22/2024.
//

#include "UserManager.h"

#include <utility>

UserManager::UserManager() {}

UserManager::UserManager(UserDB *db) : db(db){}

int UserManager::verify(UserAccount &a, std::string password) {
    // Verify user credentials with the database
    db->verify_user(a.get_username(), password);

    // Check if the database query returned any results
    std::vector<std::string> results = db->results();
    if (!results.empty()) {
        // Extract the user ID from the results and set it in the UserAccount object
        a.set_id(std::stoi(results[0])); // Assuming the user ID is the first result
        return 1; // Verification successful
    } else {
        return 0; // Verification failed
    }
}