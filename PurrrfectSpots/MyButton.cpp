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
    }
}

void MyButton::openSignUpPage() {
    // creating sign up page content
    Gtk::Box* signup_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
    Gtk::Label* signup_label = Gtk::manage(new Gtk::Label("Sign Up Page"));
    Gtk::Button* backButton = Gtk::manage(new Gtk::Button("BACK"));
    Gtk::Entry* username_entry = Gtk::manage(new Gtk::Entry()); // Add Gtk::Entry for username input


    // Connect back button click event
    backButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));

    // Add widgets to the sign-up page content
    signup_box->pack_start(*signup_label);
    signup_box->pack_start(*username_entry); // Add the username entry field
    signup_box->pack_start(*backButton);

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
            container->add(*signup_box); // Add sign-up page content
            window->show_all();
        }
    }
}