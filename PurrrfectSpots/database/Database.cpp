//
// Created by Akeena on 4/22/2024.
//

#include "Database.h"

Database::Database() {
// Open the database

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
        exit(0);
    }else{
        std::cerr << "Opened database successfully\n";
    }
}

std::vector<std::string> Database::results() {
    std::vector<std::vector<std::string>> resultSet;

    while ((retCode = sqlite3_step(stmt)) == SQLITE_ROW) {
        std::vector<std::string> row;
        int numColumns = sqlite3_column_count(stmt);
        for (int i = 0; i < numColumns; ++i) {
            const unsigned char* columnValue = sqlite3_column_text(stmt, i);
            row.push_back(reinterpret_cast<const char*>(columnValue));
        }
        resultSet.push_back(row);

        // Convert resultSet to a vector of strings and return
        std::vector<std::string> resultStrings;
        for (const auto& row : resultSet) {
            for (const auto& value : row) {
                resultStrings.push_back(value);
            }
        }
        return resultStrings;
    }
}