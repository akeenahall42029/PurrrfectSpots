//
// Created by Akeena on 4/24/2024.
//

#include "Profile.h"

    Profile::Profile(std::string username, std::vector<std::string> reviews, std::vector<std::string> createdNapspots)
            : username(username), reviews(reviews), createdNapspots(createdNapspots) {
        // Allocate the Gtk::Window on the heap

        window->set_title("User Profile");
        window->set_default_size(400, 300);

        Gtk::Grid* mainGrid = Gtk::manage(new Gtk::Grid());
        mainGrid->set_column_homogeneous(true); // Columns have the same width
        window->add(*mainGrid);

        Gtk::Label* usernameLabel = Gtk::manage(new Gtk::Label("Username: " + username));
        mainGrid->attach(*usernameLabel, 0, 0, 1, 1);

        Gtk::Label* reviewsLabel = Gtk::manage(new Gtk::Label("Reviews:"));
        mainGrid->attach(*reviewsLabel, 0, 1, 1, 1);

        // MODIFY THIS METHOD TO GO TO THROUGH EACH REVIEW OBJECT AND CALL THEIR GET.
        int row = 2;
        for (const auto& review : reviews) {
            Gtk::Label* reviewLabel = Gtk::manage(new Gtk::Label("- " + review));
            mainGrid->attach(*reviewLabel, 0, row++, 1, 1);
        }

        Gtk::Label* napspotsLabel = Gtk::manage(new Gtk::Label("Created Napspots:"));
        mainGrid->attach(*napspotsLabel, 1, 1, 1, 1);

        row = 2;
        for (const auto& napspot : createdNapspots) {
            Gtk::Label* napspotLabel = Gtk::manage(new Gtk::Label("- " + napspot));
            mainGrid->attach(*napspotLabel, 1, row++, 1, 1);
        }

        // Show the window
        window->show_all_children();
    }

//int main(int argc, char* argv[]) {
//    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
//
//    std::vector<std::string> reviews = {"Great place!", "Beautiful view!"};
//    std::vector<std::string> createdNapspots = {"Park", "Beach"};
//
//    Profile profilePage = Profile("User123", reviews, createdNapspots);
//
//    // Run the application
//    int result = 0;
//            //app->run(profilePage);
//
//
//    return result;
//}