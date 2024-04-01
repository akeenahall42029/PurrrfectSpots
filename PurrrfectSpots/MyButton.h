//
// Created by Summer Faliero on 4/1/24.
//

#ifndef PURRRFECTSPOTS_MYBUTTON_H
#define PURRRFECTSPOTS_MYBUTTON_H
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <iostream>

class MyButton : public Gtk::Button
{
public:
    MyButton();
    MyButton(Glib::ustring s);
    virtual ~MyButton();
protected:
//Signal handlers:
    void on_button_clicked();
//Child widgets:
    Glib::ustring button_label;
};


#endif //PURRRFECTSPOTS_MYBUTTON_H
