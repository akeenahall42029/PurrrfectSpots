//
// Created by Akeena on 3/25/2024.
//

#ifndef PURRRFECTSPOTS_RESERVATIONS_H
#define PURRRFECTSPOTS_RESERVATIONS_H
#include <string>

class Reservations {
private:
    int id;
    std::string napSpotId; // matches name in reservations database
    std::string userId;
    std::string userName;

    // Function to generate random id number for the reservation
    int generateID();

public:
    //Constructor
    Reservations(const std:: string& napSpotID, const std::string& userName);





};


#endif //PURRRFECTSPOTS_RESERVATIONS_H
