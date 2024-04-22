//
// Created by Sanaa Hines on 4/18/24.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Reservations.h"



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


//// The fixture for testing class Foo.
//class FooTest : public ::testing::Test {
//protected:
//    // You can remove any or all of the following functions if its body
//    // is empty.
//    FooTest() {
//        // You can do set-up work for each test here.
//    }
//    virtual ~FooTest() {
//        // You can do clean-up work that doesn’t throw exceptions here.
//    }
//// If the constructor and destructor are not enough for setting up
//// and cleaning up each test, you can define the following methods:
//    virtual void SetUp() {
//        // Code here will be called immediately after the constructor (right
//        // before each test).
//    }
//    virtual void TearDown() {
//        // Code here will be called immediately after each test (right
//        // before the destructor).
//    }
//    // Objects declared here can be used by all tests in the test case for Foo.
//    std::string s1 = "test right";
//    std::string s2 = "test wrong";
//};
//TEST(general, TESTSIMPLE) {
//    /** test the local strings **/
//    std::string s3("test");
//    std::string s4("test");
//    ASSERT_EQ(s3, s4) << s3
//                      << " and "
//                      << s4
//                      << " should match!";
//}
//TEST_F(FooTest, TESTFIXTURE) {
//    /** test the fixture strings **/
//    ASSERT_EQ(s1, s2) << "These should match!";
//}
//int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
//}