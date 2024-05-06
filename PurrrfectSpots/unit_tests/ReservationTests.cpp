////
//// Created by Akeena on 4/24/2024.
////
//

#include "../reservation/Reservations.h"
#include <gtest/gtest.h>

class ReservationsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up any state specific to the test fixture
    }

    void TearDown() override {
        // Tear down any state specific to the test fixture
    }

};

// Test the constructor
TEST_F(ReservationsTest, Constructor) {
    Reservations reservation(123, 456, 789, "confirmed");
    ASSERT_EQ(123, reservation.getNapSpotId());
    ASSERT_EQ(456, reservation.getUserId());
    ASSERT_EQ(789, reservation.getTime());
    ASSERT_EQ("confirmed", reservation.getStatus());
}

// Test the generateID method
TEST_F(ReservationsTest, GenerateID) {
    Reservations reservation(123, 456, 789, "confirmed");
    int id = reservation.getID();
    ASSERT_GE(id, 100000000); // Ensure id is at least 9 digits long
    ASSERT_LE(id, 999999999); // Ensure id is at most 9 digits long
}

//// Test setters and getters
TEST_F(ReservationsTest, SettersAndGetters) {
    Reservations reservation(0, 0, 0, "");

    reservation.setNapSpotId(123);
    reservation.setUserId(456);
    reservation.setTime(789);
    reservation.setStatus("confirmed");

    ASSERT_EQ(123, reservation.getNapSpotId());
    ASSERT_EQ(456, reservation.getUserId());
    ASSERT_EQ(789, reservation.getTime());
    ASSERT_EQ("confirmed", reservation.getStatus());
}



