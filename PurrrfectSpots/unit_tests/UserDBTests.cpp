////
//// Created by Sanaa Hines on 4/29/24.
////
#include <gtest/gtest.h>
#include "../database/Database.h"

#include <gtest/gtest.h>
#include "../database/UserDB.h"


class UserDBTest : public ::testing::Test {
protected:
    // Member variables for database and UserDB instance
    sqlite3* db;
    UserDB userDB;

    // Set up the database connection and create necessary tables
    void SetUp() override {
        // Open a connection to an in-memory SQLite database
        sqlite3_open(":memory:", &db);

        // Create tables if needed
        createTables();
    }

    // Close the database connection
    void TearDown() override {
        // Close the database connection
        sqlite3_close(db);
    }

    // Helper function to create necessary tables
    void createTables() {
        // Execute SQL statements to create tables
        sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT UNIQUE, password TEXT, reservation_id INT NOT NULL, review_id INT NOT NULL);", nullptr, nullptr, nullptr);

    }
};



// Test case for verify_user method
TEST_F(UserDBTest, VerifyUser) {
    // Insert a test user into the database
    sqlite3_exec(db, "INSERT INTO users (username, password, reservation_id, review_id) VALUES ('test_user', 'password123', 1, 1);", nullptr, nullptr, nullptr);

    // Call the verify_user method with correct username and password
    userDB.verify_user("test_user", "password123");

    // Add assertions here to check if the user was verified successfully
}

// Test case for fetch_reservations method
TEST_F(UserDBTest, FetchReservations) {
    // Insert test reservations into the database
    // Execute SQL statements to insert test reservations

    // Call the fetch_reservations method
    std::vector<Reservations> reservations = userDB.fetch_reservations(1, db); // Assuming user ID 1 has reservations

    // Add assertions here to check if reservations were fetched correctly
}

// Test case for insert_user method
TEST_F(UserDBTest, InsertUser) {
    // Call the insert_user method to insert a new user
    userDB.insert_user("new_user", "password456");

    // Add assertions here to check if the user was inserted successfully
}



