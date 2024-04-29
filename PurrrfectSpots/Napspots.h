//
// Created by Akeena on 4/28/2024.
//

#ifndef PURRRFECTSPOTS_NAPSPOTS_H
#define PURRRFECTSPOTS_NAPSPOTS_H
#include <iostream>
#include <vector>
#include <string>
class Napspots {
private:
    int id;
    std::string hostName;
    std::string address;
    std::vector<std::string> reviews;
    std::vector<std::string> avaliableTimes; // ex/ 12: 00 PM ...
    int generateId();
public:
    Napspots(int id, std::string hostName, std::string address, std::string review, std::string time);
    //these may be moved into the napSpotDB class that handles the functionality of our software
    void createNapSpot();
    void deleteNapSpot();

    // Getter methods
    int getId();
    std::string getHostName();
    std::string getAddress();
    std::vector<std::string> getReviews();
    std::vector<std::string> getAvailableTimes();

    // Setter methods
    void setId(int id);
    void setHostName(std::string hostName);
    void setAddress(std::string address);
    void addReview(std::string review);
    void addAvailableTime(std::string time);

};


#endif //PURRRFECTSPOTS_NAPSPOTS_H
