//
// Created by Sanaa Hines on 4/29/24.
//
#include <gtest/gtest.h>
#include "../database/Database.h"


// Test fixture for Database class
class DatabaseTest : public ::testing::Test {
protected:
    // SetUp method runs before each test
    void SetUp() override {
        // Create a Database object
        database = new Database();
    }

    // TearDown method runs after each test
    void TearDown() override {
        // Delete the Database object
        delete database;
    }

    // Pointer to a Database object
    Database* database;
};


// Test case for the results method
TEST_F(DatabaseTest, ResultsTest) {
    // Query the database to fetch some results
    std::vector<std::string> result = database->results("SELECT * FROM example_table");//ask about the name for the table

    // Check if the result is not empty
    ASSERT_FALSE(result.empty());
    // You can add more assertions based on the expected behavior of the results method
}

// Entry point for running the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}