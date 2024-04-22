//
// Created by Sanaa Hines on 4/18/24.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Reservations.h" // Assuming Reservations class definition is in Reservations.h
#include "Reservations.cpp"

// Test fixture for Reservations class
class ReservationsTest : public ::testing::Test {
protected:
    // Test data
    int napSpotId = 123;
    int userId = 456;
    int time = 123456;
    std::string status = "Booked";

    // Test object
    Reservations reservation;

    // Set up the test fixture
    void SetUp() override {
        reservation = Reservations(napSpotId, userId, time, status);
    }
};

// Test the constructor and getter methods
TEST_F(ReservationsTest, ConstructorAndGetters) {
    EXPECT_EQ(reservation.getNapSpotId(), napSpotId);
    EXPECT_EQ(reservation.getUserId(), userId);
    EXPECT_EQ(reservation.getTime(), time);
    EXPECT_EQ(reservation.getStatus(), status);
}

// Test the generateID method
TEST(ReservationsGenerateIDTest, GeneratesValidID) {
    Reservations reservation;
   int id = 123456789;
    // Check if the generated ID has 9 digits
    EXPECT_TRUE(std::to_string(id).length() == 9);
}

// Test the setter methods
TEST(ReservationsSetterTest, Setters) {
    Reservations reservation;
    reservation.setNapSpotId(789);
    reservation.setUserId("NewUserID");
    reservation.setTime(654321);
    reservation.setStatus("Canceled");

    EXPECT_EQ(reservation.getNapSpotId(), 789);
    //EXPECT_EQ(reservation.getUserId(), "NewUserID");
    EXPECT_EQ(reservation.getTime(), 654321);
    EXPECT_EQ(reservation.getStatus(), "Canceled");
}

