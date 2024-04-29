//
// Created by Summer Faliero on 4/29/24.
//

#ifndef PURRRFECTSPOTS_RATING_H
#define PURRRFECTSPOTS_RATING_H



#include <gtkmm.h>
#include <vector>

class Rating : public Gtk::Box {
public:
    Rating();

    void set_rating(int rating); // Set the current rating
    int get_rating() const;      // Get the current rating

private:
    int current_rating;
    std::vector<Gtk::Button*> heart_buttons;
    Glib::RefPtr<Gdk::Pixbuf> filled_heart;
    Glib::RefPtr<Gdk::Pixbuf> empty_heart;

    void update_hearts(); // Update the star images based on the current rating
};


#endif //PURRRFECTSPOTS_RATING_H
