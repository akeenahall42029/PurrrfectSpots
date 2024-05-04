//
// Created by Akeena on 4/22/2024.
//

#include "Database.h"

Database::Database() {
//    // open the database to prepare to pass queries

    retCode = 0;
    zErrMsg = 0;
    //location and name of the database
    std::string db_name = "example.sqlite";
    std::string db_location = "../database";


    std::string full_name = db_location + "/" + db_name;

    // open the database and check return codes

    retCode = sqlite3_open(full_name.c_str(),&curr_db);
    if( retCode ){
        std::cerr << "Database does not open -- "
                  << sqlite3_errmsg(curr_db)
                  << std::endl;
        std::cerr << " File -- " << full_name << std::endl;

    }else{
        std::cerr << "Opened database successfully\n";
    }


}

Database::~Database() {
    // Close the database
    if (curr_db) {
        sqlite3_close(curr_db);
        curr_db = nullptr;
    }
}
/**
 * Executes the given SQL query and returns the results as a vector of strings.
 * Prepares and executes the provided SQL query on the currently open database connection.
 * It retrieves the results of the query, if any, and stores them in a vector of strings.
 * Each element in the vector represents a single result from the query.
 *
 * @param query The SQL query to execute.
 * @return A vector of strings containing the results of the query.
 */
std::vector<std::string> Database::results(const std::string& query) {
    std::vector<std::string> result_list;

    if (!curr_db) {
        std::cerr << "Database not open. Call open() first." << std::endl;
        return result_list;
    }

    int retCode = sqlite3_prepare_v2(curr_db, query.c_str(), -1, &stmt, nullptr);
    if (retCode != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(curr_db) << std::endl;
        return result_list;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* result = sqlite3_column_text(stmt, 0);
        if (result) {
            result_list.push_back(reinterpret_cast<const char*>(result));
        }
    }

    sqlite3_finalize(stmt); // Finalize the statement
    return result_list;
}
