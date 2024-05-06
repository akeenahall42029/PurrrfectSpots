//
// Created by Akeena on 3/25/2024.
//
#include "Reservations.h"
#include <string>


// constructor
Reservations::Reservations(int napSpotID, int userId, int time,  std::string status)
        : napSpotId(napSpotID), userId(userId), time(time), status(status) {

 id = generateID(); // generate a random 9 digit ID number



}

Reservations::Reservations(int napSpotID, int userId, std::time_t startTime, std::time_t endTime, std::string status) {
    id = generateID(); // generate a random 9 digit ID number
}


/* Creates a randomly generated 9-digit id number upon the creation of
 * a new reservation
 * @return randomly generated id number */

int Reservations::generateID() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(100000000, 999999999);

    return distrib(gen);
}

int Reservations::getNapSpotId() const {
    // std::cout << "\033[1;95mYour nap spot ID is: \033[0m" << napSpotId << std::endl;
    return napSpotId;
}



int Reservations::getTime() const{
    return time;
}

int Reservations::getID()  {
    return id; // id is defined as a private variable in the header, return to this if this causes problems

}
int Reservations::getUserId()  const{
    return userId;
}


std::string Reservations::getStatus() const {
    return status;
}



void Reservations::setNapSpotId(int napSpotId)  {
    this->napSpotId = napSpotId;
}



void Reservations::setUserId(int userId) {
    this->userId = userId;
}
void Reservations::setTime(int time) {
    this->time=time;
}
void Reservations::setStatus(std::string status)  {
    this->status=status;
}


std::time_t Reservations::getStartTime() {
    return startTime;
}

std::time_t Reservations::getEndTime() {
    return endTime;
}

void Reservations::setStartTime(std::time_t newStart) {
   startTime = newStart;
}
void Reservations::setEndTime(std::time_t newEnd) {
    endTime = newEnd;
}




