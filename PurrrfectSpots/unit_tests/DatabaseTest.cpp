
 //Created by Sanaa Hines on 4/29/24.

#include "../database/Database.h"
#include <gtest/gtest.h>
// Mock class to simulate sqlite3 database
 class MockDatabase : public Database {
 public:
     // Constructor to initialize base class
     MockDatabase() : Database() {}

     // Mock method to simulate results from the database
     std::vector<std::string> mockResults(const std::string& query) {
         return results(query);
     }
 };

// Test fixture for Database class
 class DatabaseTest : public ::testing::Test {
 protected:
     void SetUp() override {
         // Initialize a mock database object
         mock_db = std::make_unique<MockDatabase>();
     }

     void TearDown() override {}

     // Declare variables needed for the tests
     std::unique_ptr<MockDatabase> mock_db;
 };

// Test case to verify adding a new reservation with valid inputs
 TEST_F(DatabaseTest, AddNewReservation) {
     // Execute a query to add a new reservation
     std::string query = "INSERT INTO reservations (id, napSpotId, userId, userName, startTime, endTime, status) "
                         "VALUES (1, 101, 201, 'Akeena Hall', 12, 13, 'Booked');";
     std::vector<std::string> results = mock_db->mockResults(query);

     // Check if the query executed successfully (results vector should be empty)
     ASSERT_TRUE(results.empty());

     // Assert that the added reservation exists in the database
     query = "SELECT * FROM reservations WHERE id = 1;";
     results = mock_db->mockResults(query);
     ASSERT_EQ(results.size(), 1); // One reservation with ID 1 should exist
 }

// Test case to verify checking username of a reservation
 TEST_F(DatabaseTest, CheckUsername) {
     // Execute a query to add a new reservation with a specific username
     std::string query = "INSERT INTO reservations (id, napSpotId, userId, userName, startTime, endTime, status) "
                         "VALUES (2, 103, 203, 'Summer Falierio', 15, 16, 'Booked');";
     std::vector<std::string> results = mock_db->mockResults(query);

     // Check if the query executed successfully (results vector should be empty)
     ASSERT_TRUE(results.empty());

     // Assert that the added reservation with ID 2 has the correct username
     query = "SELECT userName FROM reservations WHERE id = 2;";
     results = mock_db->mockResults(query);
     ASSERT_EQ(results.size(), 1); // One result should be returned
     ASSERT_EQ(results[0], "Summer Falierio"); // Username should match
 }

// Test case to verify adding a reservation with invalid inputs
 TEST_F(DatabaseTest, AddReservationWithInvalidInputs) {
     // Execute a query to add a reservation with empty user ID
     std::string query = "INSERT INTO reservations (id, napSpotId, userId, userName, startTime, endTime, status) "
                         "VALUES (3, 104, NULL, 'Sanaa Hines', 15, 16, 'Booked');";
     std::vector<std::string> results = mock_db->mockResults(query);

     // Check if the query executed successfully (results vector should be empty)
     // Assert that no reservation with invalid inputs was added
     ASSERT_TRUE(results.empty());
 }

 int main(int argc, char** argv) {
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
 }