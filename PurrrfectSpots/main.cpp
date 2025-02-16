#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/stack.h>
#include <vector>
#include "ui/MyButton.h"
#include <gtkmm/image.h>
#include <gdkmm/pixbuf.h>
#include "user/UserManager.h"
int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    //Create a UserManager object to testing login functionality
    UserManager login_tester;

    // Hard-coded user credentials
    std::string username = "akeena_demo";
    std::string password = "demo123";

    // Create the user
    login_tester.create_user(username, password);



    Gtk::Window window;
    window.set_default_size(800, 600); // made the window bigger
    window.set_border_width(100);
    window.set_resizable(false);
    window.override_background_color(Gdk::RGBA("#F5F5DC"));

    Gtk::VBox vbox;
    window.add(vbox);

   //  Load the original image
    Glib::RefPtr<Gdk::Pixbuf> originalPixbuf = Gdk::Pixbuf::create_from_file("../images/LOGIN.png");

    // Resize the image to the desired width and height
    int desiredWidth = 300; // Set your desired width
    int desiredHeight = 300; // Set your desired height
    Glib::RefPtr<Gdk::Pixbuf> resizedPixbuf = originalPixbuf->scale_simple(desiredWidth, desiredHeight, Gdk::INTERP_BILINEAR);



    // Create a Gtk::Image widget and set the resized image
    Gtk::Image image;
    image.set(resizedPixbuf);

    MyButton button1("LOG IN");
    MyButton button2("SIGN UP");
    button1.override_background_color(Gdk::RGBA("#FF0000"));
    button2.override_background_color(Gdk::RGBA("#FF0000"));

 //   vbox.pack_start(image, Gtk::PACK_EXPAND_PADDING, 10); // Add the image to the VBox
    vbox.pack_start(button1, Gtk::PACK_EXPAND_PADDING, 5);
    vbox.pack_start(button2, Gtk::PACK_EXPAND_PADDING, 5);
//    // files moving
//        std::ifstream file("../images/cloud.jpeg");
//    if (file.is_open()) {
//        std::cout << "File opened successfully!" << std::endl;
//        // Further operations with the file
//    } else {
//        std::cerr << "Failed to open file!" << std::endl;
//    }
    window.show_all();

    return app->run(window);
}