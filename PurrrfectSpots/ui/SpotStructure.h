//
// Created by Summer Faliero on 4/29/24.
//

#ifndef PURRRFECTSPOTS_SPOTSTRUCTURE_H
#define PURRRFECTSPOTS_SPOTSTRUCTURE_H
#include <string>

class SpotStructure {
public:
    // Constructor to initialize with a name, description, and image path
    SpotStructure(const std::string& name, const std::string& description, const std::string& image_path);

    // Getter methods
    std::string get_name() const;
    std::string get_description() const;
    std::string get_image_path() const;

private:
    // Member variables for the name, description, and image path
    std::string name;
    std::string description;
    std::string image_path;
};

#endif //PURRRFECTSPOTS_SPOTSTRUCTURE_H