#include "Demo.cpp"
#include "Reservations.h"
#include "MyButton.h"
#include <gtkmm.h>
#include "MyButton.h"
#include <gtkmm/application.h>
//#include <gtkmm-3.0/gtkmm.h>
//#include <gtkmm-3.0/gtkmm/application.h>




int main(int argc, char *argv[])
{
// Create the application.
    auto app =
            Gtk::Application::create(argc, argv,
                                     "something.more");
// Generate the widow and configure it by setting a size and creating a border.



//generating and configuring window
    Gtk::Window window;
    window.set_default_size(700, 500); // can we make this bigger
    window.set_border_width(10);
    window.set_resizable(false);
//setting background color
    window.override_background_color(Gdk::RGBA("#B0E0E6"));

//creating two buttons
    MyButton button1("LOG IN");
    MyButton button2("SIGN UP");
//trying to recolor the buttons to cream (not functional atm)
    button1.override_background_color(Gdk::RGBA("#ffefd5"));
    button2.override_background_color(Gdk::RGBA("#ffefd5"));

    Gtk::Box hbox1;
    hbox1.pack_start(button1, Gtk::PACK_EXPAND_PADDING, 5);
    hbox1.pack_start(button2,Gtk::PACK_EXPAND_PADDING, 5);


//creating vbox and packing above boxes
    Gtk::VBox vbox;
    vbox.pack_start(hbox1);
    window.add(vbox);

    window.show_all_children();

// Finally, this launches the program window.

//launching program window

    return app->run(window);



}






