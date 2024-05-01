//
// Created by Summer Faliero on 4/1/24.
//

#ifndef PURRRFECTSPOTS_MYBUTTON_H
#define PURRRFECTSPOTS_MYBUTTON_H

#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/stack.h>
#include <vector>
#include <string>
#include "../database/UserDB.h"
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
#include <fstream>
#include <gtkmm/scale.h>
#include <gtkmm/cssprovider.h>
#include "SpotStructure.h"
#include "../database/UserDB.h"
#include "../Reservations.h"
#include "Rating.h"
// #include "../user/UserAccount.h"
#include "../user/UserManager.h"
class MyButton : public Gtk::Button {
private:
    //Glib::ustring currentPage;
    UserDB userdb;
public:
    // constructor to initialize with a label and optional reference to a stack and history
    MyButton(const Glib::ustring &label);

    // destructor
    virtual ~MyButton();

    //helper
    void clear_container();

protected:
    // event handler for button clicks
    void on_button_clicked();
    void on_submit_button_clicked();

    // methods to open the respective pages
    void openSignUpPage();
    void openLoginPage();

    // creating tabbed structure once logged in
    void createNotebook();


private:
    // member variables for button label and window/stack handling
    Glib::ustring button_label;  // Label for the button
    Gtk::Entry* username_entry;
    Gtk::Entry* password_entry;
};


#endif //PURRRFECTSPOTS_MYBUTTON_H
