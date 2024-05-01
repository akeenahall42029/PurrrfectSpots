//
// Created by Summer Faliero on 4/29/24.
//

#include "NotebookManager.h"

//NotebookManager::NotebookManager() {
//    spot_structures = {
//            SpotStructure("Napspot 1", "Description of Napspot 1", "../images/cloud.jpeg"),
//            SpotStructure("Napspot 2", "Description of Napspot 2", "../images/pod.jpeg"),
//            SpotStructure("Napspot 3", "Description of Napspot 3", "../images/treehouse.jpeg"),
//            SpotStructure("Napspot 4", "Description of Napspot 4", "../images/treebed.jpeg"),
//            SpotStructure("Napspot 5", "Description of Napspot 5", "../images/strawberry.jpeg")
//    };
//
//    tab_images = {
//            "../images/cloudpage.png",
//            "../images/cloudpage.png",
//            "../images/cloudpage.png",
//            "../images/cloudpage.png",
//            "../images/cloudpage.png"
//    };
//}
//
//Gtk::Notebook* NotebookManager::create_notebook() {
//    Gtk::Notebook* notebook = Gtk::manage(new Gtk::Notebook());
//
//    Gtk::Box* home_tab = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
//    create_home_tab(home_tab);
//    notebook->append_page(*home_tab, "Home Page");
//
//    Gtk::Box* profile_tab = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
//    create_profile_tab(profile_tab);
//    notebook->append_page(*profile_tab, "Profile");
//
//    return notebook; // Return the notebook with all tabs
//}
//
//void NotebookManager::create_home_tab(Gtk::Box* parent) {
//    Gtk::ScrolledWindow* scroll_tab = Gtk::manage(new Gtk::ScrolledWindow());
//    Gtk::Box* scrollable_content = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
//
//    for (int i = 0; i < spot_structures.size(); i++) {
//        const SpotStructure& spot = spot_structures[i];
//
//        Gtk::Button* image_button = Gtk::manage(new Gtk::Button());
//
//        Glib::RefPtr<Gdk::Pixbuf> pixbuf = Gdk::Pixbuf::create_from_file(spot.get_image_path());
//        pixbuf = pixbuf->scale_simple(200, 200, Gdk::INTERP_BILINEAR);
//        Gtk::Image* image = Gtk::manage(new Gtk::Image(pixbuf));
//
//        Gtk::Label* title = Gtk::manage(new Gtk::Label(spot.get_name()));
//
//        Gtk::Box* button_content = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
//        button_content->pack_start(*image, Gtk::PACK_SHRINK);
//        button_content->pack_start(*title, Gtk::PACK_SHRINK);
//
//        image_button->add(*button_content);
//
//        image_button->signal_clicked().connect([=] {
//            Gtk::Overlay* new_tab = Gtk::manage(new Gtk::Overlay());
//
//            // Add different image for the tab
//            Glib::RefPtr<Gdk::Pixbuf> tab_pixbuf = Gdk::Pixbuf::create_from_file(tab_images[i]);
//            tab_pixbuf = tab_pixbuf->scale_simple(800, 600, Gdk::INTERP_BILINEAR);
//            Gtk::Image* tab_image = Gtk::manage(new Gtk::Image(tab_pixbuf));
//            new_tab->add(*tab_image);
//
//            // Add other buttons like "Favorite" and "Reserve Spot"
//            Gtk::Button* favorite_button = Gtk::manage(new Gtk::Button("⭐favorite me!⭐"));
//            favorite_button->set_size_request(30, 30);
//            favorite_button->set_halign(Gtk::ALIGN_END);
//            favorite_button->set_valign(Gtk::ALIGN_START);
//            new_tab->add_overlay(*favorite_button);
//
//            Gtk::Button* reserve_button = Gtk::manage(new Gtk::Button("Reserve Spot"));
//            reserve_button->set_size_request(60, 30);
//            reserve_button->set_halign(Gtk::ALIGN_CENTER);
//            reserve_button->set_valign(Gtk::ALIGN_CENTER);
//            new_tab->add_overlay(*reserve_button);
//
//            Gtk::Button* review_button = Gtk::manage(new Gtk::Button("write a review"));
//            review_button->set_size_request(60, 30);
//            review_button->set_halign(Gtk::ALIGN_END);
//            review_button->set_valign(Gtk::ALIGN_END);
//            new_tab->add_overlay(*review_button);
//
//            // Add the new tab to the parent notebook
//            int new_page_index = parent->append_page(*new_tab, spot.get_name());
//            if (new_page_index >= 0) {
//                parent->set_current_page(new_page_index);
//            }
//        });
//
//        scrollable_content->pack_start(*image_button, Gtk::PACK_EXPAND_PADDING);
//    }
//
//    scroll_tab->add(*scrollable_content); // Add to scrolled window
//    parent->pack_start(*scroll_tab, Gtk::PACK_EXPAND_WIDGET);
//}
//
//void NotebookManager::create_profile_tab(Gtk::Box* parent) {
//    Gtk::Label* profile_label = Gtk::manage(new Gtk::Label("Your Reservations"));
//    parent->pack_start(*profile_label, Gtk::PACK_EXPAND_WIDGET);
//    // Add additional information like reservations or user data as needed
//}