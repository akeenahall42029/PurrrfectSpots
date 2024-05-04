//
// Created by Akeena on 4/22/2024.
//

#ifndef PURRRFECTSPOTS_DATABASE_H
#define PURRRFECTSPOTS_DATABASE_H
#include <sqlite3.h>
#include <iostream>
#include <vector>

class Database {
protected:
    int retCode;
    sqlite3_stmt* stmt;
    char* zErrMsg;
public:
    Database(); // default constructor to open database
    ~Database();

    /**
     * Returns the results of the query
     * @return
     */
    // std::vector<std::string> results();

    std::vector<std::string> results(const std::string &query);

    sqlite3* curr_db;
};

#endif //PURRRFECTSPOTS_DATABASE_H