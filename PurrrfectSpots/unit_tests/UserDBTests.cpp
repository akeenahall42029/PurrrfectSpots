////
//// Created by Sanaa Hines on 4/29/24.
////

#include "../database/UserDB.h"
#include <gtest/gtest.h>
#include <sqlite3.h>

class UserDBTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Open an in-memory database for testing
        int rc = sqlite3_open(":memory:", &db);
        ASSERT_EQ(SQLITE_OK, rc) << "Database connection failed: " << sqlite3_errmsg(db);

        userDB.curr_db = db; // Set the current database connection for testing
    }

    void TearDown() override {
        sqlite3_close(db); // Close the database after each test
    }

    sqlite3* db;
    UserDB userDB;
};

// Test fetching a username by user ID
TEST_F(UserDBTest, FetchUsernameByID) {
    sqlite3_exec(db, "CREATE TABLE users (id INTEGER PRIMARY KEY, userName TEXT);", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "INSERT INTO users (id, userName) VALUES (1, 'testUser');", nullptr, nullptr, nullptr);

    std::string username = userDB.fetch_userName(1);

    ASSERT_EQ("testUser", username);
}

// Test inserting a user
TEST_F(UserDBTest, InsertUser) {
    sqlite3_exec(db, "CREATE TABLE users (userName TEXT, password TEXT);", nullptr, nullptr, nullptr);

    userDB.insert_user("testUser", "testPassword");

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, "SELECT COUNT(*) FROM users WHERE userName = 'testUser'", -1, &stmt, nullptr);
    int count = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        count = sqlite3_column_int(stmt, 0);
    }
    sqlite3_finalize(stmt);

    ASSERT_EQ(1, count);
}

// Test verifying user credentials
TEST_F(UserDBTest, VerifyUser) {
    sqlite3_exec(db, "CREATE TABLE users (id INTEGER PRIMARY KEY, userName TEXT, password TEXT);", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "INSERT INTO users (userName, password) VALUES ('testUser', 'testPassword');", nullptr, nullptr, nullptr);

    testing::internal::CaptureStdout();
    userDB.verify_user("testUser", "testPassword");
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_NE(std::string::npos, output.find("User verified successfully"));
}

// Test fetching user reservations by user ID
TEST_F(UserDBTest, FetchUserReservationsById) {
    sqlite3_exec(db, "CREATE TABLE reservations (id INTEGER PRIMARY KEY, userId INTEGER);", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "INSERT INTO reservations (id, userId) VALUES (1, 1);", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "INSERT INTO reservations (id, userId) VALUES (2, 1);", nullptr, nullptr, nullptr);

    std::vector<int> reservations = userDB.fetchUserReservationsById(1);

    ASSERT_EQ(2, reservations.size());
    ASSERT_EQ(1, reservations[0]);
    ASSERT_EQ(2, reservations[1]);
}

