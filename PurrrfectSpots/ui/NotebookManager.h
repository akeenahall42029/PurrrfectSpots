//
// Created by Summer Faliero on 4/29/24.
//

#ifndef PURRRFECTSPOTS_NOTEBOOKMANAGER_H
#define PURRRFECTSPOTS_NOTEBOOKMANAGER_H
#include <gtkmm.h>
#include "SpotStructure.h"
#include "../reservation/Reservations.h"
#include "Rating.h"

class NotebookManager {
public:
    NotebookManager(); // Constructor

    Gtk::Notebook* create_notebook(); // Create the notebook with all tabs

private:
    void create_home_tab(Gtk::Box* parent); // Creates the "Home" tab
    void create_profile_tab(Gtk::Box* parent); // Creates the "Profile" tab
    void create_spot_tab(Gtk::Overlay* overlay, int index); // Creates a tab for a nap spot

    std::vector<SpotStructure> spot_structures; // Nap spots data
    std::vector<std::string> tab_images; // Images for the tabs
};


#endif //PURRRFECTSPOTS_NOTEBOOKMANAGER_H
