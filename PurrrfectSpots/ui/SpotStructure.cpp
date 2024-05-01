//
// Created by Summer Faliero on 4/29/24.
//

#include "SpotStructure.h"
#include "MyButton.h"
#include <gtkmm.h>

// Constructor to initialize with a name, description, and image path
SpotStructure::SpotStructure(const std::string& name, const std::string& description, const std::string& image_path)
        : name(name), description(description), image_path(image_path) {}

// Getter methods for name, description, and image path
std::string SpotStructure::get_name() const {
    return name;
}

std::string SpotStructure::get_description() const {
    return description;
}

std::string SpotStructure::get_image_path() const {
    return image_path;
}

int SpotStructure::getNapSpotId() {
    return 0;
}
