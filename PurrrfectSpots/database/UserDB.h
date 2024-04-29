//
// Created by Akeena on 4/22/2024.
//

#ifndef PURRRFECTSPOTS_USERDB_H
#define PURRRFECTSPOTS_USERDB_H
#include <iostream>
#include "Database.h"
#include <sqlite3.h>
#include <string>
#include <vector> // For std::vector

class UserDB {
public:
    // Constructor to initialize the database connection
    UserDB();

    // Destructor to close the database connection
    ~UserDB();

    // Method to open the database
    void open(const std::string& db_path);

    // Method to close the database
    void close();

    // Method to insert a new user into the database
    void insert_user(const std::string& userName, const std::string& password);

    // Method to verify a user in the database
    void verify_user(const std::string& userName, const std::string& password);

    // Fetch user information (dummy methods, could be placeholders for future implementation)
    void fetch_userName();
    void fetch_userPassword();
    void fetch_user();

    // Method to execute an SQL query and return results
    std::vector<std::string> results(const std::string& query);

private:
    sqlite3* curr_db; // SQLite database connection
    sqlite3_stmt* stmt; // SQLite prepared statement
    int retCode; // Return code for error handling
};

#endif //PURRRFECTSPOTS_USERDB_H
