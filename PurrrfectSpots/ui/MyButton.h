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

class MyButton : public Gtk::Button {
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
};


#endif //PURRRFECTSPOTS_MYBUTTON_H
