//
// Created by Akeena on 4/24/2024.
//

#include "ReservationTests.h"
#include <gtest/gtest.h>
//#include "Reservations.h"
#include "../Reservations.h"


// Test fixture for Reservations class
class ReservationsTest : public ::testing::Test {
protected:
    void SetUp() override {
        reservation = std::make_unique<Reservations>(1, 12345, 1, "Pending");
    }

    void TearDown() override {

    }

    // Declare any variables needed for the tests
    std::unique_ptr<Reservations> reservation;
};

// Test case to verify the constructor
TEST_F(ReservationsTest, Constructor) {
    // Check if the object is constructed correctly
    ASSERT_EQ(reservation->getNapSpotId(), 1);
    ASSERT_EQ(reservation->getUserId(), 12345);
    ASSERT_EQ(reservation->getTime(), 1);
    ASSERT_EQ(reservation->getStatus(), "Pending");
    // Add more assertions as needed
}

// Test case to verify the generateID method
TEST_F(ReservationsTest, GenerateID) {
    // Check if the generated ID is within the expected range
    int id = reservation->generateID();
    ASSERT_GE(id, 100000000);
    ASSERT_LE(id, 999999999);

}



