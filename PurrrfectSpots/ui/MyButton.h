//
// Created by Summer Faliero on 4/1/24.
//

#ifndef PURRRFECTSPOTS_MYBUTTON_H
#define PURRRFECTSPOTS_MYBUTTON_H

#include <gtkmm/button.h>

class MyButton : public Gtk::Button {
public:
    MyButton(const Glib::ustring& label);
    virtual ~MyButton();

protected:
    void on_button_clicked();
    void openSignUpPage();

private:
    Glib::ustring button_label;

    void openLoginPage();
};


#endif //PURRRFECTSPOTS_MYBUTTON_H
