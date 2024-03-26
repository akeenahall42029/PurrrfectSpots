//
// Created by Akeena on 3/25/2024.
//

#ifndef PURRRFECTSPOTS_RESERVATIONS_H
#define PURRRFECTSPOTS_RESERVATIONS_H
#include <string>

class Reservations {
private:
    int id;
    int napSpotId;
    int userId;
    int time ;
    std::string status;

    // Function to generate random id number for the reservation
    int generateID();
    void setNapSpotId(int napSpotId);
    void setUserId(std::string userId);
   //void resTime();


public:
    //Constructor
    Reservations(int napSpotID, int userId, int time, const std::string& status);

    // Getter functions, will be useful for SQL binding
    int getID() const; // Change the return type to int
    int getNapSpotId() const;
    int getUserId() const ;
    int getTime() const;
    std::string getStatus() const;






};


#endif //PURRRFECTSPOTS_RESERVATIONS_H
