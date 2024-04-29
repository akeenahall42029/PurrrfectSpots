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
#include "SpotStructure.h"


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

void MyButton::createNotebook() {
    g_print("Creating a new window with a notebook...\n");

    // creating a new Gtk::Window and add the notebook
    Gtk::Window* new_window = Gtk::manage(new Gtk::Window());
    new_window->set_title("Notebook Example");
    new_window->set_default_size(800, 600);

    // creating the notebook with tabs
    Gtk::Notebook* notebook = Gtk::manage(new Gtk::Notebook());

    Gtk::Box* profile_tab = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
    profile_tab->pack_start(*Gtk::manage(new Gtk::Label("Profile Information")));

    // creating the "Scrollable Page" tab
    Gtk::ScrolledWindow* scroll_tab = Gtk::manage(new Gtk::ScrolledWindow());
    Gtk::Box* scrollable_content = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

    for (int i = 0; i < 5; i++) { // reducing the number of items for simplicity
        Gtk::Button* image_button = Gtk::manage(new Gtk::Button());

        // using Gtk::Image to load the photo
        Gtk::Image* image = Gtk::manage(new Gtk::Image("images/pod.jpg")); //path
        image->set_pixel_size(200); // setting the desired size for the image

        Gtk::Label* title = Gtk::manage(new Gtk::Label("nap spot " + std::to_string(i+1)));

        // using a Gtk::Box for layout inside the button
        Gtk::Box* button_content = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
        button_content->pack_start(*image, Gtk::PACK_EXPAND_WIDGET); // adding the larger image
        button_content->pack_start(*title, Gtk::PACK_EXPAND_PADDING); // adding the title

        image_button->add(*button_content); // adding the box to the button
        image_button->set_size_request(220, 250); // setting a size to accommodate the image and label

        // connecting the click event to a function
        image_button->signal_clicked().connect([=] {

            g_print("Nap Spot %d clicked. Navigating...\n", i);

            Gtk::Box* new_tab = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

            // adding the image associated with the napspot
            Gtk::Image* new_image = Gtk::manage(new Gtk::Image("download.jpg")); // checking the image path
            new_tab->pack_start(*new_image, Gtk::PACK_EXPAND_WIDGET); // adding the image

            // add additional information - ADD TO THIS WITH INFO AB SPECIFIC NAP SPOTS
            Gtk::Label* new_label = Gtk::manage(new Gtk::Label("More information about NapSpot " + std::to_string(i+1)));
            new_tab->pack_start(*new_label);

            // appending the new tab to the notebook
            int new_page_index = notebook->append_page(*new_tab, "NapSpot " + std::to_string(i+1));

            if (new_page_index >= 0) { // ensuring the tab was successfully created
                notebook->set_current_page(new_page_index); // navigating to the new tab
            } else {
                g_print("Error: New tab creation failed.\n");
            }

            g_print("Navigated to SpotStructure %d.\n", i);
            notebook->set_current_page(new_page_index); // navigating to the new tab
            new_window->show_all(); // refreshing window
        });

        scrollable_content->pack_start(*image_button, Gtk::PACK_EXPAND_PADDING); // adding the button to the scrollable content
    }


    // adding the scrollable content to the ScrolledWindow
    scroll_tab->add(*scrollable_content);

    // appending the profile and scrollable tabs to the notebook
    notebook->append_page(*scroll_tab, "Home Page");
    notebook->append_page(*profile_tab, "Profile");


    new_window->add(*notebook); // adding notebook to the new window
    new_window->show_all(); // displaying the new window with notebook
}