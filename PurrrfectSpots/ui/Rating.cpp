//
// Created by Summer Faliero on 4/29/24.
//

#include "Rating.h" // The corresponding header file for your implementation
#include <gtkmm/button.h> // Include for Gtk::Button
#include <gtkmm/image.h>  // Include for Gtk::Image
#include <gdkmm/pixbuf.h> // Include for Gdk::Pixbuf

Rating::Rating() : Gtk::Box(Gtk::ORIENTATION_HORIZONTAL), current_rating(0) {
    // Load heart images
    auto filled_heart = Gdk::Pixbuf::create_from_file("../images/fullheart.png");
    auto empty_heart = Gdk::Pixbuf::create_from_file("../images/emptyheart.png");

    // Create 5 heart buttons
    for (int i = 1; i <= 5; ++i) {
        Gtk::Button* heart_button = Gtk::manage(new Gtk::Button());

        // Create Gtk::Image from Gdk::Pixbuf
        auto empty_heart_image = Gtk::manage(new Gtk::Image(empty_heart));
        heart_button->set_image(*empty_heart_image);

        heart_button->signal_clicked().connect(sigc::bind<int>(
                sigc::mem_fun(*this, &Rating::set_rating), i
        ));

        heart_buttons.push_back(heart_button);
        pack_start(*heart_button, Gtk::PACK_SHRINK);
    }
}

void Rating::set_rating(int rating) {
    current_rating = rating;
    update_hearts(); // Update the heart images based on the current rating
}

void Rating::update_hearts() {
    // Update heart images based on the current rating
    auto filled_heart = Gdk::Pixbuf::create_from_file("../images/fullheart.png");
    auto empty_heart = Gdk::Pixbuf::create_from_file("../images/emptyheart.png");

    for (int i = 0; i < heart_buttons.size(); ++i) {
        auto heart_image = Gtk::manage(new Gtk::Image(i < current_rating ? filled_heart : empty_heart));
        heart_buttons[i]->set_image(*heart_image); // Set the correct heart image
    }
}

int Rating::get_rating() const {
    return current_rating;
}