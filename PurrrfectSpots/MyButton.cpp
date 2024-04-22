//
// Created by Summer Faliero on 4/1/24.
//

#include "MyButton.h"
#include <gtkmm/window.h>  // Add this include for Gtk::Window
#include <gtkmm/container.h>  // Add this include for Gtk::Container
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>


MyButton::MyButton(const Glib::ustring& label) : button_label(label) {
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

void MyButton::openSignUpPage() {

    // creating sign up page content!

    //creating the sign-up page content container
    Gtk::Box* signup_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

    // creating and add the back button to the top-left corner -- its centered :(
    Gtk::Button* backButton = Gtk::manage(new Gtk::Button("BACK"));
    backButton->set_size_request(30, 30); // Set button size
    signup_box->pack_start(*backButton, Gtk::PACK_START, 0);

    //creating and add the sign-up label to the center of the container
    Gtk::Label* signup_label = Gtk::manage(new Gtk::Label("Sign Up Page"));
    signup_label->set_halign(Gtk::ALIGN_CENTER); // Center-align the label
    signup_label->set_margin_top(50); // Add top margin for spacing
    signup_label->set_margin_bottom(50); // Add bottom margin for spacing
    signup_box->pack_start(*signup_label, Gtk::PACK_START, 0);

    //creating and add the username entry centered within the container
    Gtk::Entry* username_entry = Gtk::manage(new Gtk::Entry());
    username_entry->set_halign(Gtk::ALIGN_CENTER); // Center-align the entry
    username_entry->set_placeholder_text("Username"); // Set placeholder text
    username_entry->set_margin_bottom(20); // Add bottom margin for spacing
    signup_box->pack_start(*username_entry, Gtk::PACK_START, 0);


    // connecting back button click event
    backButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));

    // adding widgets to the sign-up page content
    signup_box->pack_start(*signup_label);
    signup_box->pack_start(*username_entry); // adding the username entry field
    signup_box->pack_start(*backButton);

    // clearing existing content of the window
    Gtk::Window* window = dynamic_cast<Gtk::Window*>(get_toplevel());
    if (window) {
        Gtk::Container* container = dynamic_cast<Gtk::Container*>(window->get_child());
        if (container) {
            // Remove all existing content
            auto children = container->get_children();
            for (auto& child : children) {
                container->remove(*child);
            }
            container->add(*signup_box); // adding sign-up page content
            window->show_all();
        }
    }
}

void MyButton::openLoginPage() {
    // Create login page content

    // Create login page content container
    Gtk::Box* login_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

    // Create and add the back button to the top-left corner
    Gtk::Button* backButton = Gtk::manage(new Gtk::Button("BACK"));
    backButton->set_size_request(30, 30); // Set button size
    login_box->pack_start(*backButton, Gtk::PACK_START, 0);

    // Create and add the login label to the center of the container
    Gtk::Label* login_label = Gtk::manage(new Gtk::Label("Login Page"));
    login_label->set_halign(Gtk::ALIGN_CENTER); // Center-align the label
    login_label->set_margin_top(50); // Add top margin for spacing
    login_label->set_margin_bottom(50); // Add bottom margin for spacing
    login_box->pack_start(*login_label, Gtk::PACK_START, 0);

    // Create and add the username entry centered within the container
    Gtk::Entry* username_entry = Gtk::manage(new Gtk::Entry());
    username_entry->set_halign(Gtk::ALIGN_CENTER); // Center-align the entry
    username_entry->set_placeholder_text("Username"); // Set placeholder text
    username_entry->set_margin_bottom(20); // Add bottom margin for spacing
    login_box->pack_start(*username_entry, Gtk::PACK_START, 0);

    // Create and add the password entry centered within the container
    Gtk::Entry* password_entry = Gtk::manage(new Gtk::Entry());
    password_entry->set_halign(Gtk::ALIGN_CENTER); // Center-align the entry
    password_entry->set_placeholder_text("Password"); // Set placeholder text
    password_entry->set_visibility(false); // Hide the password text
    password_entry->set_margin_bottom(20); // Add bottom margin for spacing
    login_box->pack_start(*password_entry, Gtk::PACK_START, 0);

    // Create and add the login button centered within the container
    Gtk::Button* loginButton = Gtk::manage(new Gtk::Button("LOGIN"));
    loginButton->set_halign(Gtk::ALIGN_CENTER); // Center-align the button
    login_box->pack_start(*loginButton, Gtk::PACK_START, 0);

    // Connect back button click event
    backButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));

    // Add widgets to the login page content
    login_box->pack_start(*login_label);
    login_box->pack_start(*username_entry); // Add the username entry field
    login_box->pack_start(*password_entry); // Add the password entry field
    login_box->pack_start(*loginButton); // Add the login button

    // Clear existing content of the window
    Gtk::Window* window = dynamic_cast<Gtk::Window*>(get_toplevel());
    if (window) {
        Gtk::Container* container = dynamic_cast<Gtk::Container*>(window->get_child());
        if (container) {
            // Remove all existing content
            auto children = container->get_children();
            for (auto& child : children) {
                container->remove(*child);
            }
            container->add(*login_box); // Add login page content
            window->show_all();
        }
    }
}