//
// Created by Akeena on 4/24/2024.
//

#ifndef PURRRFECTSPOTS_PROFILE_H
#define PURRRFECTSPOTS_PROFILE_H

#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <vector>

class Profile : Gtk::Window{
public:
    Profile(std::string username, std::vector<std::string> reviews,  std::vector<std::string> createdNapspots);
    Gtk::Window* window = new Gtk::Window();

private:
    std::string username;
    std::vector<std::string> reviews; // this may need to change to a vector of Review objects
    std::vector<std::string> createdNapspots; // this may need to change to a vector of NapSpot objects
};


#endif //PURRRFECTSPOTS_PROFILE_H
