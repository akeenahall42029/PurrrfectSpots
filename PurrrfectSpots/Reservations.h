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
    int time ;
    std::string status;

    // Function to generate random id number for the reservation
    int generateID();
    void setNapSpotId(int napSpotId);
    void setUserName(std::string userName);
    void setUserId(std::string userId);

public:
    //Constructor
    Reservations(const std:: string& napSpotID, const std::string& userName);
    // Getter functions, will be useful for SQL binding
    int getID() const; // Change the return type to int
    std::string getNapSpotId() const;
    std::string getUserName() const;
    std::string getUserId() const;
    int getTime();
    std::string getStatus();






};


#endif //PURRRFECTSPOTS_RESERVATIONS_H
