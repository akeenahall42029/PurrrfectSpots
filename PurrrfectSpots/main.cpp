#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include "ui/MyButton.h"
#include <gtkmm.h>


int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");


    Gtk::Window window;
    window.set_default_size(1000, 1000); // made the window bigger
    window.set_border_width(10);
    window.set_resizable(false);
    window.override_background_color(Gdk::RGBA("#B0E0E6"));

    Gtk::VBox vbox;
    window.add(vbox);

    MyButton button1("LOG IN");
    MyButton button2("SIGN UP");
    button1.override_background_color(Gdk::RGBA("#ffefd5"));
    button2.override_background_color(Gdk::RGBA("#ffefd5"));

    vbox.pack_start(button1, Gtk::PACK_EXPAND_PADDING, 5);
    vbox.pack_start(button2, Gtk::PACK_EXPAND_PADDING, 5);



    window.show_all();

    return app->run(window);
}
