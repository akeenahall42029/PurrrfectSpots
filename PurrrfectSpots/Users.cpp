//
// Created by Akeena on 4/17/2024.
//

#include "Users.h"

class User {
public:
    // Constructor
    User(const std::string& username, const std::string& password)
            : username(username), password(password) {}

    // Method to save user data to the database
    bool save_to_database(const std::string& db_path) {
        sqlite3* db;
        int rc = sqlite3_open(db_path.c_str(), &db);

        if (rc != SQLITE_OK) {
            std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
            return false;
        }

        std::string sql = "INSERT INTO users (username, password) VALUES (?, ?)";
        sqlite3_stmt* stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

        if (rc == SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_TRANSIENT);

            rc = sqlite3_step(stmt);
            if (rc == SQLITE_DONE) {
                sqlite3_finalize(stmt);
                sqlite3_close(db);
                return true; // Successful insertion
            } else {
                std::cerr << "Error inserting user: " << sqlite3_errmsg(db) << std::endl;
            }
        } else {
            std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        }

        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false; // Failed insertion
    }

private:
    std::string username;
    std::string password;
};

int Users::generateID() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(100000000, 999999999);

    return distrib(gen);
}

void Users::storeData() {
    // sql = "INSERT INTO reservations(id, napSpotId, userId, userName, time, status) VALUES (?, ?, ?, ?, ?, ? )";

    //Initialize local vars
    retCode = 0;
    zErrMsg = 0;

    int size_value = 0;
    // Construct the SQL query for INSERT INTO reservations
    //std::string
    sql = "INSERT INTO reservations";
    sql += "(id, name, password) ";
    sql += "VALUES (";
    sql += std::to_string(id);
    sql += ", ";
    // add userName
    sql += userName;
    sql += ", ";
    sql += password;
    sql += "');";
    // Execute the SQL query
    retCode = sqlite3_exec(curr_db, sql.c_str(), 0, 0, &zErrMsg);
    if (retCode != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Record inserted successfully!" << std::endl;
    }

    // Close the database
    sqlite3_close(curr_db);

}