//
// Created by Summer Faliero on 4/29/24.
//

#ifndef PURRRFECTSPOTS_SPOTSTRUCTURE_H
#define PURRRFECTSPOTS_SPOTSTRUCTURE_H
#include <string>

    class SpotStructure {
    public:
        // Constructor to initialize the SpotStructure with required attributes
        SpotStructure(const std::string& name, const std::string& description, const std::string& image_path)
                : name(name), description(description), image_path(image_path) {}

        // Getters for the attributes
        std::string get_name() const { return name; }
        std::string get_description() const { return description; }
        std::string get_image_path() const { return image_path; }

    private:
        // Attributes for the SpotStructure
        std::string name;
        std::string description;
        std::string image_path;

    };

#endif //PURRRFECTSPOTS_SPOTSTRUCTURE_H