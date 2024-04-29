//
// Created by Summer Faliero on 4/1/24.
//

// work on using a data structure to add unique data to each nap spot

#include "MyButton.h"
#include <gtkmm/window.h>
#include <gtkmm/container.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/notebook.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/overlay.h>
#include <gtkmm/comboboxtext.h>
#include "SpotStructure.h"
#include "../database/UserDB.h"
#include "../Reservations.h"


MyButton::MyButton(const Glib::ustring &label) : button_label(label) {
    set_label(label);
    signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));
}

MyButton::~MyButton() {
    // destructor implementation
}

void MyButton::on_button_clicked() {
    if (button_label == "SIGN UP") {
        openSignUpPage();
    } else if (button_label == "BACK") {
        // implement going back
    } else if(button_label == "LOG IN"){
        openLoginPage();
    }
}

bool check_credentials(const std::string& username, const std::string& password) {
    // Sample database check. Replace with actual database connection and query.
    // For demonstration, let's say the valid credentials are "admin" and "password123".

    // In a real-world scenario, you'd use a database library to query your database.
    if (username == "admin" && password == "password123") {
        return true;
    }
    return false;
}


void MyButton::openSignUpPage() {

    // creating sign up page content!

    //creating the sign-up page content container
    Gtk::Box* signup_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

    // creating and add the back button to the top-left corner -- its centered :(
    Gtk::Button* backButton = Gtk::manage(new Gtk::Button("BACK"));
    backButton->set_size_request(30, 30); // set button size
    signup_box->pack_start(*backButton, Gtk::PACK_START, 0);

    // Create the "SUBMIT" button and add it to the sign-up box
    Gtk::Button* submitButton = Gtk::manage(new Gtk::Button("SUBMIT"));
    submitButton->set_size_request(100, 30);
    submitButton->set_halign(Gtk::ALIGN_CENTER);
    submitButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_submit_button_clicked)); // Connect the signal
    signup_box->pack_end(*submitButton, Gtk::PACK_EXPAND_PADDING);

    // Get the top-level window and add the sign-up box

    //creating and add the sign-up label to the center of the container
    Gtk::Label* signup_label = Gtk::manage(new Gtk::Label("Sign Up Page"));
    signup_label->set_halign(Gtk::ALIGN_CENTER); // center-align the label
    signup_label->set_margin_top(50); // add top margin for spacing
    signup_label->set_margin_bottom(50); // add bottom margin for spacing
    signup_box->pack_start(*signup_label, Gtk::PACK_START, 0);

    //creating and add the username entry centered within the container
    Gtk::Entry* username_entry = Gtk::manage(new Gtk::Entry());
    username_entry->set_halign(Gtk::ALIGN_CENTER); // center-align the entry
    username_entry->set_placeholder_text("Username"); // set placeholder text
    username_entry->set_margin_bottom(20); // add bottom margin for spacing
    signup_box->pack_start(*username_entry, Gtk::PACK_START, 0);

    Gtk::Entry* password_entry = Gtk::manage(new Gtk::Entry());
    password_entry->set_halign(Gtk::ALIGN_CENTER); // center-align the entry
    password_entry->set_placeholder_text("Password"); // set placeholder text
    password_entry->set_visibility(false); // hide the password text
    password_entry->set_margin_bottom(20); // add bottom margin for spacing
    signup_box->pack_start(*password_entry, Gtk::PACK_START, 0);

    // connecting back button click event
    backButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));

    // adding widgets to the sign-up page content
    signup_box->pack_start(*signup_label, Gtk::PACK_START, 10);
    signup_box->pack_start(*password_entry, Gtk::PACK_START, 10); // adding the username entry field
    signup_box->pack_start(*username_entry, Gtk::PACK_START, 10); // adding the username entry field
    signup_box->pack_start(*backButton, Gtk::PACK_START, 0);
    signup_box->pack_end(*submitButton, static_cast<Gtk::PackOptions>(10)); // Packing the submit button at the bottom with margin


    // clearing existing content of the window
    Gtk::Window* window = dynamic_cast<Gtk::Window*>(get_toplevel());
    if (window) {
        Gtk::Container* container = dynamic_cast<Gtk::Container*>(window->get_child());
        if (container) {
            // removing all existing content
            auto children = container->get_children();
            for (auto& child : children) {
                container->remove(*child);
            }
            container->add(*signup_box); // adding sign-up page content
            window->show_all();
        }
    }
}

void MyButton::on_submit_button_clicked() {
    // not working. want to have it generate a message when submit is pressed, saying:
    // "Credentials have been verified and stored.
    // Please rerun the application and sign in with your new credentials."
    g_print("generating message\n");
    // when "SUBMIT" is clicked, show a verification message
    Gtk::Window* window = dynamic_cast<Gtk::Window*>(get_toplevel());
    if (window) {
        Gtk::Container* container = dynamic_cast<Gtk::Container*>(window->get_child());
        if (container) {
            //creating and add the sign-up label to the center of the container
            Gtk::Label* signup_label = Gtk::manage(new Gtk::Label("Sign Up Page"));
            signup_label->set_halign(Gtk::ALIGN_CENTER); // center-align the label
            signup_label->set_margin_top(50); // add top margin for spacing
            signup_label->set_margin_bottom(50); // add bottom margin for spacing

            container->add(*signup_label); // adding the label to the existing content
            window->show_all(); // refreshing the GUI
        }
    }
}

void MyButton::openLoginPage() {
    // creating login page content

    // creating login page content container
    Gtk::Box* login_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

    // creating and adding the back button to the top-left corner
    Gtk::Button* backButton = Gtk::manage(new Gtk::Button("BACK"));
    backButton->set_size_request(30, 30); // Set button size
    login_box->pack_start(*backButton, Gtk::PACK_START, 0);

    // creating and adding the login label to the center of the container
    Gtk::Label* login_label = Gtk::manage(new Gtk::Label("Login Page"));
    login_label->set_halign(Gtk::ALIGN_CENTER); // Center-align the label
    login_label->set_margin_top(50); // Add top margin for spacing
    login_label->set_margin_bottom(50); // Add bottom margin for spacing
    login_box->pack_start(*login_label, Gtk::PACK_START, 0);

    // creating and adding the username entry centered within the container
    Gtk::Entry* username_entry = Gtk::manage(new Gtk::Entry());
    username_entry->set_halign(Gtk::ALIGN_CENTER); // Center-align the entry
    username_entry->set_placeholder_text("Username"); // Set placeholder text
    username_entry->set_margin_bottom(20); // Add bottom margin for spacing
    login_box->pack_start(*username_entry, Gtk::PACK_START, 0);

    // creating and adding the password entry centered within the container
    Gtk::Entry* password_entry = Gtk::manage(new Gtk::Entry());
    password_entry->set_halign(Gtk::ALIGN_CENTER); // Center-align the entry
    password_entry->set_placeholder_text("Password"); // Set placeholder text
    password_entry->set_visibility(false); // Hide the password text
    password_entry->set_margin_bottom(20); // Add bottom margin for spacing
    login_box->pack_start(*password_entry, Gtk::PACK_START, 0);

    // creating and adding the login button centered within the container
    Gtk::Button* loginButton = Gtk::manage(new Gtk::Button("LOGIN"));
    loginButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::createNotebook));
    loginButton->set_halign(Gtk::ALIGN_CENTER); // Center-align the button
    login_box->pack_start(*loginButton, Gtk::PACK_START, 0);

    // connecting back button click event
    backButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));

    // adding widgets to the login page content
    login_box->pack_start(*login_label);
    login_box->pack_start(*username_entry); // adding the username entry field
    login_box->pack_start(*password_entry); // adding the password entry field
    login_box->pack_start(*loginButton); // adding the login button


    // clearing existing content of the window
    Gtk::Window* window = dynamic_cast<Gtk::Window*>(get_toplevel());
    if (window) {
        Gtk::Container* container = dynamic_cast<Gtk::Container*>(window->get_child());
        if (container) {
            // removing all existing content
            auto children = container->get_children();
            for (auto& child : children) {
                container->remove(*child);
            }
            container->add(*login_box); // adding login page content
            window->show_all();
        }
    }
}

// helper function to clear all children from a container
void clear_container(Gtk::Container* container) {
    if (container) {
        auto children = container->get_children();
        for (auto& child : children) {
            container->remove(*child); // ensuring all children are removed
        }
    }
}
std::vector<SpotStructure> spot_structures = {
        SpotStructure("Napspot 1", "Description of Napspot 1", "../images/cloud.jpeg"),
        SpotStructure("Napspot 2", "Description of Napspot 2", "../images/pod.jpeg"),
        SpotStructure("Napspot 3", "Description of Napspot 3", "../images/treehouse.jpeg"),
        SpotStructure("Napspot 4", "Description of Napspot 4", "../images/treebed.jpeg"),
        SpotStructure("Napspot 5", "Description of Napspot 5", "../images/strawberry.jpeg")

};

// New set of images to be displayed when a napspot is clicked
std::vector<std::string> tab_images = {
        "../images/cloudpage.png",
        "../images/podpage.png",
        "../images/treehousepage.png",
        "../images/picnicpage.png",
        "../images/strawberrypage.png"
};

void MyButton::createNotebook() {
    Gtk::Window* new_window = Gtk::manage(new Gtk::Window());
    new_window->set_default_size(800, 600);

    Gtk::Notebook* notebook = Gtk::manage(new Gtk::Notebook());
    Gtk::ScrolledWindow* scroll_tab = Gtk::manage(new Gtk::ScrolledWindow());
    Gtk::Box* scrollable_content = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

    for (int i = 0; i < spot_structures.size(); i++) {
        const SpotStructure& spot = spot_structures[i];

        Gtk::Button* image_button = Gtk::manage(new Gtk::Button());

        Glib::RefPtr<Gdk::Pixbuf> pixbuf = Gdk::Pixbuf::create_from_file(spot.get_image_path());
        pixbuf = pixbuf->scale_simple(200, 200, Gdk::INTERP_BILINEAR);
        Gtk::Image* image = Gtk::manage(new Gtk::Image(pixbuf));

        Gtk::Label* title = Gtk::manage(new Gtk::Label(spot.get_name()));

        Gtk::Box* button_content = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
        button_content->pack_start(*image, Gtk::PACK_SHRINK);
        button_content->pack_start(*title, Gtk::PACK_SHRINK);

        image_button->add(*button_content);
        image_button->signal_clicked().connect([=] {
            Gtk::Overlay* new_tab = Gtk::manage(new Gtk::Overlay());

            // Use a different image for the tab
            Glib::RefPtr<Gdk::Pixbuf> tab_pixbuf = Gdk::Pixbuf::create_from_file(tab_images[i]);
            tab_pixbuf = tab_pixbuf->scale_simple(800, 600, Gdk::INTERP_BILINEAR);
            Gtk::Image* tab_image = Gtk::manage(new Gtk::Image(tab_pixbuf));

            new_tab->add(*tab_image);

            // Create the "Favorite this spot" button and add it to the overlay
            Gtk::Button* favorite_button = Gtk::manage(new Gtk::Button("⭐favorite me!⭐"));
            favorite_button->set_size_request(30, 30); // Keep it small
            favorite_button->set_halign(Gtk::ALIGN_END); // Align it to the top-right
            favorite_button->set_valign(Gtk::ALIGN_START); // Align it to the top-right
            favorite_button->set_margin_top(85); // Set margin to move the button lower
            new_tab->add_overlay(*favorite_button); // Add the button on top
            favorite_button->signal_clicked().connect([=] {
                g_print("Added to favorites\n"); // This prints to the console
                // Additional code for handling the "favorite" action
            });

                // Create the "Reserve Spot" button in the center
            Gtk::Button* reserve_button = Gtk::manage(new Gtk::Button("reserve spot"));
            reserve_button->set_size_request(60, 30); // Smaller button
            reserve_button->set_halign(Gtk::ALIGN_CENTER); // Keep centered horizontally
            reserve_button->set_valign(Gtk::ALIGN_CENTER); // Keep centered vertically
            reserve_button->set_margin_bottom(150); // Move downward by 50 pixels
            reserve_button->set_margin_left(190);
            reserve_button->signal_clicked().connect([=] {
                // Open a new window to select a reservation time
                Gtk::Window* reservation_window = Gtk::manage(new Gtk::Window());
                reservation_window->set_default_size(300, 200);
                reservation_window->set_title("Reserve a Time");

                Gtk::Box* reservation_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

                Gtk::ComboBoxText* time_dropdown = Gtk::manage(new Gtk::ComboBoxText());
                time_dropdown->append("Morning");
                time_dropdown->append("Afternoon");
                time_dropdown->append("Evening");
                reservation_box->pack_start(*time_dropdown);

                Gtk::Button* confirm_button = Gtk::manage(new Gtk::Button("Confirm Reservation"));
                confirm_button->signal_clicked().connect([=] {
                    // Store the reservation data
                    std::string selected_time = time_dropdown->get_active_text();
                    Reservations new_reservation(0, 123, 0, "Reserved");
                    g_print("you have booked a nap spot!\n");


                    // Close the reservation window
                    reservation_window->close();
                });

                reservation_box->pack_start(*confirm_button);

                reservation_window->add(*reservation_box);
                reservation_window->show_all();
            });

            new_tab->add_overlay(*reserve_button); // Add the reserve button to the overlay

            int new_page_index = notebook->append_page(*new_tab, spot.get_name());

            if (new_page_index >= 0) {
                notebook->set_current_page(new_page_index);
            }

            new_window->show_all(); // Ensure all changes are displayed
        });

        scrollable_content->pack_start(*image_button, Gtk::PACK_EXPAND_PADDING);
    }

    scroll_tab->add(*scrollable_content);

    Gtk::Box* profile_tab = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
    Gtk::Label* profile_label = Gtk::manage(new Gtk::Label("Your Reservations"));
    profile_tab->pack_start(*profile_label, Gtk::PACK_EXPAND_WIDGET);


    notebook->append_page(*scroll_tab, "Home Page");
    notebook->append_page(*profile_tab, "Profile");

    new_window->add(*notebook); // Add the notebook to the new window
    new_window->show_all(); // Display the notebook
}
