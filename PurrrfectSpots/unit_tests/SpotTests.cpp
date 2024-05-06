//
// Created by Sanaa Hines on 5/4/24.
//
#include "../ui/SpotStructure.h"
#include <gtest/gtest.h>

// Test fixture for SpotStructure class
class SpotStructureTest : public ::testing::Test {
protected:
    // Set up before each test
    void SetUp() override {
        // Initialize SpotStructure object
        spot = new SpotStructure("Park", "A beautiful park", "park.jpg");
    }

    // Tear down after each test
    void TearDown() override {
        delete spot;
    }

    // SpotStructure object for testing
    SpotStructure* spot;
};

// Test get_name method
TEST_F(SpotStructureTest, GetName) {
    EXPECT_EQ("Park", spot->get_name());
}

// Test get_description method
TEST_F(SpotStructureTest, GetDescription) {
    EXPECT_EQ("A beautiful park", spot->get_description());
}

// Test get_image_path method
TEST_F(SpotStructureTest, GetImagePath) {
    EXPECT_EQ("park.jpg", spot->get_image_path());
}


