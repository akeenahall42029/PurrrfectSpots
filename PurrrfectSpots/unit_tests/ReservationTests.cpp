//
// Created by Akeena on 4/24/2024.
//

//#include "ReservationTests.h"
//#include <gtest/gtest.h>
////#include "Reservations.h"
//#include "../Reservations.h"
//#include <gtest/gtest.h>
//
//
//// Define a fixture for the unit tests
////class ReservationsTest : public ::testing::Test {
////protected:
////    virtual void SetUp() {
////        // Initialize any resources needed for the tests
////    }
////
////    virtual void TearDown() {
////        // Clean up any resources allocated in SetUp()
////    }
////
////    // Declare any member variables needed for the tests
////};
////
////// Test case for the storeData() method
////TEST_F(ReservationsTest, StoreDataTest) {
////    // Arrange: Create a Reservations object with test data
////    int id = 1;
////    int napSpotId = 2;
////    int userId = 3;
////    int time = 123456789;
////    std::string status = "Booked";
////    Reservations reservation(id, napSpotId, userId, time, status);
////
////    // Act: Call the storeData() method
////    reservation.storeData();
////
////    // Assert: Check if the data was successfully stored
////    // Add your assertions here based on the expected behavior of storeData()
////    // For example, you could check if the return code indicates success
////    ASSERT_EQ(reservation.getRetCode(), SQLITE_OK);
////}
////
////// Entry point for running the tests
////int main(int argc, char** argv) {
////    ::testing::InitGoogleTest(&argc, argv);
////    return RUN_ALL_TESTS();
////}
//#include <gtest/gtest.h>
//#include "../Reservations.h" // Assuming Reservations.h contains the declaration of Reservations class
//
//// Test case for the generateID() method
//TEST(ReservationsTest, GenerateIDTest) {
//    // Arrange: Create a Reservations object
//    Reservations reservation;
//
//    // Act: Call the generateID() method
//    int id = reservation.generateID();
//
//    // Assert: Check if the generated ID is within the expected range
//    ASSERT_GE(id, 100000000); // Check if id is greater than or equal to 100000000
//    ASSERT_LE(id, 999999999); // Check if id is less than or equal to 999999999
//}
//
//// Entry point for running the tests
//int main(int argc, char** argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}