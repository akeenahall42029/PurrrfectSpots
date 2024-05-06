//
// Created by Akeena on 4/28/2024.
//

#include "Napspots.h"

Napspots::Napspots(int id, std::string hostName, std::string address, std::string review, std::string time) {

}

void Napspots::createNapSpot() {

}

void Napspots::deleteNapSpot() {

}




////
/**
 * Constructs a Napspots object with the given location and user ID.
 *
 * @param location The location of the nap spot.
 * @param userId The ID of the user who owns the nap spot.
 */
//Napspots::Napspots(std::string location, int userId) : location(location), userId(userId){
//    id = generateId();
//
//}
//
///**
// * Constructs a Napspots object with the given location, user ID, and initial review.
// *
// * @param location The location of the nap spot.
// * @param userId The ID of the user who owns the nap spot.
// * @param review The initial review for the nap spot.
// */
//Napspots::Napspots(std::string location, int userId, std::string review) : location(location), userId(userId){
//    id = generateId();
//    reviews.push_back(review);
//}
///**
// *  Constructs a Napspots object with the given location, user ID, and list of reviews. This constructor will be
// *  used to hardcode napspots
// *
// * @param location The location of the nap spot.
// * @param userId The ID of the user who owns the nap spot.
// * @param reviews The list of reviews for the nap spot.
// */
//Napspots::Napspots(std::string location, int userId, std::vector<std::string> reviews) : location(location), userId(userId), reviews(reviews){
//    id= generateId();
//}
///**
// * Constructs a Napspots object with the given location and initial review.
// *
// * @param location The location of the nap spot.
// * @param review The initial review for the nap spot.
// */
//Napspots::Napspots(std::string location, std::string review) : location(location) {
//    id = generateId();
//    reviews.push_back(review);
//
//}
//
//Napspots::~Napspots(){
//
//}
//
//
//
//
//// MOVE TO MANAGER
//void Napspots::createNapSpot() {
//
//}
//
//void Napspots::deleteNapSpot() {
//
//}
////
//int Napspots::generateId() {
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> distrib(100000000, 999999999);
//
//    return distrib(gen);
//}
//
//int Napspots::getId() {
//    return id;
//}
//
//
//
//std::string Napspots::getLocation() {
//    return location;
//}
//
//std::vector<std::string> Napspots::getReviews() {
//    return reviews;
//}
//
//std::vector<std::time_t> Napspots::getAvailableTimes() {
//    return avaliableTimes;
//}
//
//int Napspots::getAverageStarRating() {
//    return averageStarRating;
//}
//
//void Napspots::setId(int id) {
//    id = id;
//
//}











///