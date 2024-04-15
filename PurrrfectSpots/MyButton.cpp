//
// Created by Summer Faliero on 4/1/24.
//

#include <gtkmm/stack.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include "MyButton.h"
#include "Reservations.h"

MyButton::MyButton(Glib::ustring s) {
    button_label = s;
// This function will add a label to the button using the passed value.
    add_label(s);
// This connects the button widget (referenced by this) to a pointer of
// the on_button_clicked method.
    signal_clicked().connect(
            sigc::mem_fun(*this, &MyButton::on_button_clicked) );
}
MyButton::MyButton()
{
    button_label = "test Button";
// This function will add a label to the button using a default value.
    add_label(button_label);
// This connects the button widget (referenced by this) to a pointer of
// the on_button_clicked method.
    signal_clicked().connect(
            sigc::mem_fun(*this, &MyButton::on_button_clicked) );
}
// This is a destructor that does nothing in this case.
MyButton::~MyButton() { }
// A method that connected to the button by the command above.

void MyButton::openSignUpPage() {
    std::cout <<  " is this working" << std::endl;
    // Create widgets for the sign-up page
    Gtk::Window signup_window;
    Gtk::Box signup_box;
    Gtk::Label signup_label("Sign Up Page");

    // Add widgets to the sign-up page
    signup_box.pack_start(signup_label);

    // Show the sign-up page and window
    signup_window.add(signup_box);
    signup_window.show_all();
}

void MyButton::on_button_clicked()
{
    std::cout << button_label << " was clicked." << std::endl;

    if (button_label == "SIGN UP") {
        // Code to open the sign-up page and handle its functionality
        openSignUpPage();
    }

    int napSpotID = 100;
    int userId = 1200;
    std::string userName = "summer";
    int time = 30;
    std::string status = "booked";

    Reservations tester(napSpotID, userId, userName, time, status);

    tester.getNapSpotId();
        //this is where i change the page or code what happens after clicking a button
}
