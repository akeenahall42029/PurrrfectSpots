//
// Created by Akeena on 3/25/2024.
//

#include "Reservations.h"
#include <random>
int Reservations::generateID() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(100000000, 999999999);

    return distrib(gen);
}

Reservations::Reservations(const std::string &napSpotID, const std::string &userName) {
    id = generateID();

}

/* Creates a randomly generated 9-digit id number upon the creation of
 * a new reservation
 * @return randomly generated id number */

