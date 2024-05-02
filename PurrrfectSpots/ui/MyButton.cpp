//
// Created by Summer Faliero on 4/1/24.
//

// work on using a data structure to add unique data to each nap spot

#include <gtkmm/messagedialog.h>
#include "MyButton.h"


//// #include "../user/UserAccount.h"
//#include "../user/UserManager.h"
MyButton::MyButton(const Glib::ustring &label) : button_label(label) {
    set_label(label);
    signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));

}

MyButton::~MyButton() {

}

void MyButton::on_button_clicked() {
    if (button_label == "SIGN UP") {
        current_page = "SIGN UP";
        openSignUpPage();
    } else if (button_label == "BACK") {
        if (current_page == "SIGN UP") {
            openLoginPage();
        } else if (current_page == "LOGIN") {
            // Implement navigation to the previous page if needed
            openLoginPage();
        }
    } else if(button_label == "LOG IN"){
        current_page = "LOG IN";
        openLoginPage();
    }
}

// Come back to this
bool check_credentials(const std::string& username, const std::string& password) {
    // Sample database check. Replace with actual database connection and query.
    // For demonstration, let's say the valid credentials are "admin" and "password123".

    // In a real-world scenario, you'd use a database library to query your database.
    if (username == "admin" && password == "password123") {
        return true;
    }
    return false;
}


void MyButton::openSignUpPage() {

    // creating sign up page content!

    //creating the sign-up page content container
    Gtk::Box* signup_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

    // creating and add the back button to the top-left corner -- its centered :(
    Gtk::Button* backButton = Gtk::manage(new Gtk::Button("BACK"));
    backButton->set_size_request(30, 30); // set button size
    signup_box->pack_start(*backButton, Gtk::PACK_START, 0);

    // Create the "SUBMIT" button and add it to the sign-up box
    Gtk::Button* submitButton = Gtk::manage(new Gtk::Button("SUBMIT"));
    submitButton->set_size_request(100, 30);
    submitButton->set_halign(Gtk::ALIGN_CENTER);
    submitButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_submit_button_clicked)); // Connect the signal
    signup_box->pack_end(*submitButton, Gtk::PACK_EXPAND_PADDING);

    // Get the top-level window and add the sign-up box

    //creating and add the sign-up label to the center of the container
    Gtk::Label* signup_label = Gtk::manage(new Gtk::Label("Sign Up Page"));
    signup_label->set_halign(Gtk::ALIGN_CENTER); // center-align the label
    signup_label->set_margin_top(50); // add top margin for spacing
    signup_label->set_margin_bottom(50); // add bottom margin for spacing
    signup_box->pack_start(*signup_label, Gtk::PACK_START, 0);

    //creating and add the username entry centered within the container
    username_entry = Gtk::manage(new Gtk::Entry());
    username_entry->set_halign(Gtk::ALIGN_CENTER); // center-align the entry
    username_entry->set_placeholder_text("Username"); // set placeholder text
    username_entry->set_margin_bottom(20); // add bottom margin for spacing
    signup_box->pack_start(*username_entry, Gtk::PACK_START, 0);

    password_entry = Gtk::manage(new Gtk::Entry());
    password_entry->set_halign(Gtk::ALIGN_CENTER); // center-align the entry
    password_entry->set_placeholder_text("Password"); // set placeholder text
    password_entry->set_visibility(false); // hide the password text
    password_entry->set_margin_bottom(20); // add bottom margin for spacing
    signup_box->pack_start(*password_entry, Gtk::PACK_START, 0);

    // connecting back button click event
    backButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));

    // adding widgets to the sign-up page content
    signup_box->pack_start(*signup_label, Gtk::PACK_START, 10);
    signup_box->pack_start(*password_entry, Gtk::PACK_START, 10); // adding the username entry field
    signup_box->pack_start(*username_entry, Gtk::PACK_START, 10); // adding the username entry field
    signup_box->pack_start(*backButton, Gtk::PACK_START, 0);
    signup_box->pack_end(*submitButton, static_cast<Gtk::PackOptions>(10)); // Packing the submit button at the bottom with margin


    // clearing existing content of the window
    Gtk::Window* window = dynamic_cast<Gtk::Window*>(get_toplevel());
    if (window) {
        Gtk::Container* container = dynamic_cast<Gtk::Container*>(window->get_child());
        if (container) {
            // removing all existing content
            auto children = container->get_children();
            for (auto& child : children) {
                container->remove(*child);
            }
            container->add(*signup_box); // adding sign-up page content
            window->show_all();
        }
    }
}

/**This method is called when the submit button is clicked. It retrieves the username and password
 * entered by the user from the username and password entry fields, respectively. Then, it calls the
 * UserManager to create a new user account using the provided username and password. Finally, it
 * calls the createNotebook method to initialize the notebook for the newly created user.
 */
void MyButton::on_submit_button_clicked() {

    // Get the username and password entered by the user
    std::string username = username_entry->get_text();
    std::string password = password_entry->get_text();

    // Call UserManager to create a new user account
    user_manager.create_user(username, password);

    createNotebook();

}

void MyButton::openLoginPage() {
//    // Create a UserDB object for database interaction (assuming you have one)
//    UserDB userDB;
//
//    // UserAccount manager object to verify user credentials
//    UserManager manager(&userDB);

    // creating login page content container
    Gtk::Box* login_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

    // creating and adding the back button to the top-left corner
    Gtk::Button* backButton = Gtk::manage(new Gtk::Button("BACK"));
    backButton->set_size_request(30, 30); // Set button size
    login_box->pack_start(*backButton, Gtk::PACK_START, 0);

    // creating and adding the login label to the center of the container
    Gtk::Label* login_label = Gtk::manage(new Gtk::Label("Login Page"));
    login_label->set_halign(Gtk::ALIGN_CENTER); // Center-align the label
    login_label->set_margin_top(50); // Add top margin for spacing
    login_label->set_margin_bottom(50); // Add bottom margin for spacing
    login_box->pack_start(*login_label, Gtk::PACK_START, 0);

    // creating and adding the username entry centered within the container
    username_entry = Gtk::manage(new Gtk::Entry());
    username_entry->set_halign(Gtk::ALIGN_CENTER); // Center-align the entry
    username_entry->set_placeholder_text("Username"); // Set placeholder text
    username_entry->set_margin_bottom(20); // Add bottom margin for spacing
    login_box->pack_start(*username_entry, Gtk::PACK_START, 0);

    // creating and adding the password entry centered within the container
    password_entry = Gtk::manage(new Gtk::Entry());
    password_entry->set_halign(Gtk::ALIGN_CENTER); // Center-align the entry
    password_entry->set_placeholder_text("Password"); // Set placeholder text
    password_entry->set_visibility(false); // Hide the password text
    password_entry->set_margin_bottom(20); // Add bottom margin for spacing
    login_box->pack_start(*password_entry, Gtk::PACK_START, 0);

    // creating and adding the login button centered within the container
    Gtk::Button* loginButton = Gtk::manage(new Gtk::Button("LOGIN"));
    // TRYING TO VERIFY USERNAME
    loginButton->signal_clicked().connect([this]() {
        std::string username = username_entry->get_text(); // Retrieve the username entered by the user
        std::string password = password_entry->get_text(); // Retrieve the password entered by the user
        // might need to fix this logic 
        UserAccount user(username, password); // Create a UserAccount object with the entered username

        if (user_manager.verify(user, password) == 1) {
            // Verification successful
            createNotebook();
        } else {
            // Verification failed
            // Prompt the user to try again
            Gtk::MessageDialog dialog(*dynamic_cast<Gtk::Window*>(get_toplevel()), "Login Failed");
            dialog.set_secondary_text("Please try again.");
            dialog.run();
        }
    });


//    loginButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::createNotebook));
    loginButton->set_halign(Gtk::ALIGN_CENTER); // Center-align the button
    login_box->pack_start(*loginButton, Gtk::PACK_START, 0);

    // connecting back button click event
    backButton->signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));

    // adding widgets to the login page content
    login_box->pack_start(*login_label);
    login_box->pack_start(*username_entry); // adding the username entry field
    login_box->pack_start(*password_entry); // adding the password entry field
    login_box->pack_start(*loginButton); // adding the login button


    // clearing existing content of the window
    Gtk::Window* window = dynamic_cast<Gtk::Window*>(get_toplevel());
    if (window) {
        Gtk::Container* container = dynamic_cast<Gtk::Container*>(window->get_child());
        if (container) {
            // removing all existing content
            auto children = container->get_children();
            for (auto& child : children) {
                container->remove(*child);
            }
            container->add(*login_box); // adding login page content
            window->show_all();
        }
    }
}

// helper function to clear all children from a container
void clear_container(Gtk::Container* container) {
    if (container) {
        auto children = container->get_children();
        for (auto& child : children) {
            container->remove(*child); // ensuring all children are removed
        }
    }
}
std::vector<SpotStructure> spot_structures = {
        SpotStructure("Cloud-9", "Markle Admissions Building", "../images/cloud.jpeg"),
        SpotStructure("Dream Pod", "Outside of Farber Hall", "../images/pod.jpeg"),
        SpotStructure("Sleepy Canopy", "Oak Tree Outside of Ruef Hall", "../images/treehouse.jpeg"),
        SpotStructure("Honk Shoo Pad", "Tree on the Academic Quad", "../images/treebed.jpeg"),
        SpotStructure("Strawberry Siesta", "Second Floor of Skillman Library", "../images/strawberry.jpeg")

};

// New set of images to be displayed when a napspot is clicked
std::vector<std::string> tab_images = {
        "../images/cloudpage.png",
        "../images/podpage.png",
        "../images/treehousepage.png",
        "../images/picnicpage.png",
        "../images/strawberrypage.png"
};

std::vector<std::string> profile_images = {
        "../prof1.png"
        "../prof2.png"
        "../prof3.png"
        "../prof4.png"
        "../prof5.png"
};

// Helper function to get the absolute path for a given relative path
std::string getAbsolutePath(const std::string& relativePath) {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        return std::string(cwd) + "/" + relativePath;
    }
    return relativePath; // Fallback to relative path if error
}
// -------------------------------------------------------------------
// AKEENA NEEDS TO REVIEW THESE METHODS ~ akeena

// Function to read reviews from a given file
std::vector<std::string> readReviews(const std::string& napSpotName) {
    std::vector<std::string> reviews;
    std::string fileName = "reviews_" + napSpotName + ".txt";
    std::string filePath = getAbsolutePath(fileName); // Ensure the file path is correct

    std::ifstream infile(filePath);
    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {
            reviews.push_back(line); // Store each review in the vector
        }
        infile.close();
    } else {
        std::cerr << "Error: Could not open file: " << filePath << std::endl;
    }
    return reviews;
}


// Function to save a review to a unique file for a given nap spot
void saveReview(const std::string& napSpotName, const std::string& reviewContent) {
    // Create a unique filename based on the nap spot name
    std::string fileName = "reviews_" + napSpotName + ".txt";
    std::string filePath = getAbsolutePath(fileName); // Get the absolute path

    std::ofstream outfile(filePath, std::ios::app); // Open in append mode

    if (outfile.is_open()) {
        outfile << reviewContent << "\n"; // Write the review content
        outfile.close(); // Close the file
        std::cout << "Review saved successfully for " << napSpotName << " at: " << filePath << std::endl;
    } else {
        std::cerr << "Error: Could not open the file for writing at: " << filePath << std::endl;
    }
}

// Function to save a review to a unique file for a given nap spot
void saveReport(const std::string& napSpotName, const std::string& reviewContent) {
    // Create a unique filename based on the nap spot name
    std::string fileName = "reports_" + napSpotName + ".txt";
    std::string filePath = getAbsolutePath(fileName); // Get the absolute path

    std::ofstream outfile(filePath, std::ios::app); // Open in append mode

    if (outfile.is_open()) {
        outfile << reviewContent << "\n"; // Write the review content
        outfile.close(); // Close the file
        std::cout << "Report saved successfully for " << napSpotName << " at: " << filePath << std::endl;
    } else {
        std::cerr << "Error: Could not open the file for writing at: " << filePath << std::endl;
    }
}


// Function to apply CSS from a file to a GTK widget
void apply_css(Gtk::Widget& widget, const std::string& css_filename) {
    Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();
    try {
        css_provider->load_from_path(css_filename); // Load the CSS file
    } catch (const Glib::Error& ex) {
        std::cerr << "Error loading CSS: " << ex.what() << std::endl;
        return;
    }

    Glib::RefPtr<Gtk::StyleContext> style_context = widget.get_style_context();
    style_context->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER); // Add the CSS provider
}

// Create a custom slider with CSS applied
Gtk::Scale* create_custom_slider(const std::string& css_path) {
    Gtk::Scale* scale = Gtk::manage(new Gtk::Scale(Gtk::ORIENTATION_HORIZONTAL)); // Create the slider
    scale->set_range(1, 5); // Set range
    scale->set_increments(1, 1); // Set increments
    scale->set_value_pos(Gtk::POS_TOP); // Position of the value

    apply_css(*scale, css_path); // Apply the custom CSS

    return scale;
}

void createProfileTab(Gtk::Notebook* notebook) {
    // Create an overlay to set the background image
    Gtk::Overlay* profile_overlay = Gtk::manage(new Gtk::Overlay());

    // Create an image to use as the background
    Glib::RefPtr<Gdk::Pixbuf> profile_background_pixbuf = Gdk::Pixbuf::create_from_file("../images/prof1.png");
    profile_background_pixbuf = profile_background_pixbuf->scale_simple(800, 600, Gdk::INTERP_BILINEAR); // Scale to the desired size
    Gtk::Image* profile_background_image = Gtk::manage(new Gtk::Image(profile_background_pixbuf));

    // Add the background image to the overlay
    profile_overlay->add(*profile_background_image);

    // Create a box to hold the content on top of the background
    Gtk::Box* profile_content = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
    profile_content->set_spacing(10); // Add some spacing between elements

    Gtk::Label* profile_label = Gtk::manage(new Gtk::Label("Your Reservations"));
    profile_content->pack_start(*profile_label, Gtk::PACK_SHRINK); // Pack the label

    // Add more content to the profile tab as needed (e.g., list of reservations)
    // Example: Adding a placeholder for reservation information
    Gtk::Label* reservation_placeholder = Gtk::manage(new Gtk::Label("Reservation details will be displayed here."));
    profile_content->pack_start(*reservation_placeholder, Gtk::PACK_EXPAND_WIDGET); // Pack additional content

    // Add the profile content box to the overlay, on top of the background image
    profile_overlay->add_overlay(*profile_content);

    // Add the profile tab to the notebook
    notebook->append_page(*profile_overlay, "Profile"); // Add the profile tab with the background
}

void MyButton::createNotebook() {
    Gtk::Window* new_window = Gtk::manage(new Gtk::Window());
    new_window->set_default_size(800, 600);

    Gtk::Notebook* notebook = Gtk::manage(new Gtk::Notebook());
    Gtk::ScrolledWindow* scroll_tab = Gtk::manage(new Gtk::ScrolledWindow());
    Gtk::Box* scrollable_content = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

    for (int i = 0; i < spot_structures.size(); i++) {
        const SpotStructure& spot = spot_structures[i];

        Gtk::Button* image_button = Gtk::manage(new Gtk::Button());

        Glib::RefPtr<Gdk::Pixbuf> pixbuf = Gdk::Pixbuf::create_from_file(spot.get_image_path());
        pixbuf = pixbuf->scale_simple(200, 200, Gdk::INTERP_BILINEAR);
        Gtk::Image* image = Gtk::manage(new Gtk::Image(pixbuf));

        Gtk::Label* title = Gtk::manage(new Gtk::Label(spot.get_name()));

        Gtk::Box* button_content = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
        button_content->pack_start(*image, Gtk::PACK_SHRINK);
        button_content->pack_start(*title, Gtk::PACK_SHRINK);

        image_button->add(*button_content);
        image_button->signal_clicked().connect([=] {
            Gtk::Overlay* new_tab = Gtk::manage(new Gtk::Overlay());

            // Use a different image for the tab
            Glib::RefPtr<Gdk::Pixbuf> tab_pixbuf = Gdk::Pixbuf::create_from_file(tab_images[i]);
            tab_pixbuf = tab_pixbuf->scale_simple(800, 600, Gdk::INTERP_BILINEAR);
            Gtk::Image* tab_image = Gtk::manage(new Gtk::Image(tab_pixbuf));
            new_tab->add(*tab_image);


            // Create the "Favorite this spot" button and add it to the overlay
            Gtk::Button* favorite_button = Gtk::manage(new Gtk::Button("⭐favorite me!⭐"));
            favorite_button->set_size_request(30, 30); // Keep it small
            favorite_button->set_halign(Gtk::ALIGN_END); // Align it to the top-right
            favorite_button->set_valign(Gtk::ALIGN_START); // Align it to the top-right
            favorite_button->set_margin_top(85); // Set margin to move the button lower
            new_tab->add_overlay(*favorite_button); // Add the button on top
            favorite_button->signal_clicked().connect([=] {
                g_print("Added to favorites\n"); // This prints to the console
                // Additional code for handling the "favorite" action
            });

            // Button to view previous reviews
            Gtk::Button* view_reviews_button = Gtk::manage(new Gtk::Button("view ratings and reviews"));
            view_reviews_button->set_size_request(60, 30); // Small size
            view_reviews_button->set_halign(Gtk::ALIGN_CENTER); // Center horizontally
            view_reviews_button->set_valign(Gtk::ALIGN_END);    // Align to the bottom
            view_reviews_button->set_margin_bottom(110); // Set margin to position it at the bottom
            view_reviews_button->set_margin_left(200); // Set margin to position it at the bottom

            view_reviews_button->signal_clicked().connect([=] {
                std::vector<std::string> reviews = readReviews(spot.get_name()); // Read the reviews

                // Create a pop-up window to display the reviews
                Gtk::Window* review_window = Gtk::manage(new Gtk::Window());
                review_window->set_default_size(300, 200);
                review_window->override_background_color(Gdk::RGBA("lavender"));

                Gtk::Box* review_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

                for (const auto& review : reviews) {
                    Gtk::Label* review_label = Gtk::manage(new Gtk::Label(review));
                    review_box->pack_start(*review_label, Gtk::PACK_EXPAND_PADDING); // Add each review
                }

                review_window->add(*review_box);
                review_window->show_all(); // Show all elements
            });

            new_tab->add_overlay(*view_reviews_button); // Add the button to the overlay


            // Add the slider (Gtk::Scale) to rate the nap spot
            Gtk::Scale* rating_slider = Gtk::manage(new Gtk::Scale(Gtk::ORIENTATION_HORIZONTAL));
            rating_slider->set_range(1, 5); // Range from 1 to 5
            rating_slider->set_increments(1, 1); // Increment by 1
            rating_slider->set_value_pos(Gtk::POS_TOP); // Position the value above the slider
            rating_slider->set_size_request(100, 30); // Set size
            rating_slider->set_halign(Gtk::ALIGN_CENTER); // Center horizontally
            rating_slider->set_valign(Gtk::ALIGN_END); // Align towards the bottom
            rating_slider->set_margin_bottom(250); // Move downward by 50 pixels
            rating_slider->set_margin_left(60);
            new_tab->add_overlay(*rating_slider); // Add the slider to the overlay

            // Create the "Submit Rating" button
            Gtk::Button* submit_rating_button = Gtk::manage(new Gtk::Button("submit rating"));
            submit_rating_button->set_halign(Gtk::ALIGN_CENTER); // Center horizontally
            submit_rating_button->set_valign(Gtk::ALIGN_END); // Align towards the bottom
            submit_rating_button->set_margin_bottom(215); // Move downward by 50 pixels
            submit_rating_button->set_margin_left(60);
            submit_rating_button->signal_clicked().connect([=] {
                int rating = static_cast<int>(rating_slider->get_value());
                g_print("Submitted rating for '%s': %d\n", spot.get_name().c_str(), rating);
                // Code to save the rating to a file or database
                std::ofstream outfile("../rating_data.txt", std::ios::app); // Open in append mode
                if (outfile.is_open()) {
                    outfile << spot.get_name() << ": " << rating << "\n"; // Write the rating to the file
                    outfile.close();
                } else {
                    g_print("Error: Could not open the file for writing.\n");
                }
            });

            new_tab->add_overlay(*rating_slider); // Add the slider to the overlay
            new_tab->add_overlay(*submit_rating_button); // Add the submit rating button to the overlay

            //adding location given description data from the SpotStructure struct
            //DO THIS TMM

            // Create the "Reserve Spot" button in the center
            Gtk::Button* reserve_button = Gtk::manage(new Gtk::Button("reserve spot"));
            reserve_button->set_size_request(60, 30); // Smaller button
            reserve_button->set_halign(Gtk::ALIGN_CENTER); // Keep centered horizontally
            reserve_button->set_valign(Gtk::ALIGN_CENTER); // Keep centered vertically
            reserve_button->set_margin_bottom(150); // Move downward by 50 pixels
            reserve_button->set_margin_left(190);
            reserve_button->signal_clicked().connect([=] {
                // Open a new window to select a reservation time
                Gtk::Window* reservation_window = Gtk::manage(new Gtk::Window());
                reservation_window->set_default_size(300, 200);
                reservation_window->set_title("Reserve a Time");
                reservation_window->override_background_color(Gdk::RGBA("lavender")); // Set background color to lavender


                Gtk::Box* reservation_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

                // AKEENA --> change this to
                // 1. pull reservation options to display
                // 2. remove the option that the user selected
                Gtk::ComboBoxText* time_dropdown = Gtk::manage(new Gtk::ComboBoxText());
                time_dropdown->append("Morning");
                time_dropdown->append("Afternoon");
                time_dropdown->append("Evening");
                reservation_box->pack_start(*time_dropdown);

                Gtk::Button* confirm_button = Gtk::manage(new Gtk::Button("Confirm Reservation"));
                confirm_button->signal_clicked().connect([=] {
                    // Store the reservation data
                    std::string selected_time = time_dropdown->get_active_text();
                    Reservations new_reservation(0, 123, 0, "Reserved");
                    g_print("you have booked a nap spot!\n");


                    // Close the reservation window
                    reservation_window->close();
                });

                reservation_box->pack_start(*confirm_button);

                reservation_window->add(*reservation_box);
                reservation_window->show_all();
            });

            new_tab->add_overlay(*reserve_button); // Add the reserve button to the overlay



            // New "Report" button to open a lavender window with a text box
            Gtk::Button* report_button = Gtk::manage(new Gtk::Button("got an issue?"));
            report_button->set_size_request(30, 30); // Small size
            report_button->set_halign(Gtk::ALIGN_CENTER); // Keep centered horizontally
            report_button->set_valign(Gtk::ALIGN_CENTER); // Keep centered vertically
            report_button->set_margin_top(555); // Move downward by 50 pixels
            report_button->set_margin_left(690);

            report_button->signal_clicked().connect([=] {
                Gtk::Window* report_window = Gtk::manage(new Gtk::Window());
                report_window->set_default_size(300, 200);
                report_window->override_background_color(Gdk::RGBA("red")); // Set background color to red

                Gtk::Box* report_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
                Gtk::Entry* report_text = Gtk::manage(new Gtk::Entry()); // Text box for the review
                report_text->set_placeholder_text("Write your report here..."); // Placeholder text

                Gtk::Button* submit_button_report = Gtk::manage(new Gtk::Button("Submit"));
                submit_button_report->signal_clicked().connect([=] {

                    std::string review_content = report_text->get_text();
                    saveReport(spot.get_name(), review_content); // Save with the spot name

                    g_print("Report Submitted for %s: %s\n", spot.get_name().c_str(), review_content.c_str());
                    report_window->close(); // Close the review window
                });

            report_box->pack_start(*report_text, Gtk::PACK_EXPAND_PADDING); // Add text box
                report_box->pack_start(*submit_button_report, Gtk::PACK_EXPAND_PADDING); // Add submit button
                report_window->add(*report_box); // Add box to the review window
                report_window->show_all(); // Show all elements in the review window
            });

            new_tab->add_overlay(*report_button); // Add the review button to the overlay



            // New "Review" button to open a lavender window with a text box
            Gtk::Button* review_button = Gtk::manage(new Gtk::Button("write a review"));
            review_button->set_size_request(60, 55); // Small size
            review_button->set_halign(Gtk::ALIGN_CENTER); // Keep centered horizontally
            review_button->set_valign(Gtk::ALIGN_CENTER); // Keep centered vertically
            review_button->set_margin_top(110); // Move downward by 50 pixels
            review_button->set_margin_left(335);

            review_button->signal_clicked().connect([=] {
                Gtk::Window* review_window = Gtk::manage(new Gtk::Window());
                review_window->set_default_size(300, 200);
                review_window->override_background_color(Gdk::RGBA("lavender")); // Set background color to lavender

                Gtk::Box* review_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
                Gtk::Entry* review_text = Gtk::manage(new Gtk::Entry()); // Text box for the review
                review_text->set_placeholder_text("Write your review here..."); // Placeholder text

                Gtk::Button* submit_button = Gtk::manage(new Gtk::Button("Submit"));
                submit_button->signal_clicked().connect([=] {

                    std::string review_content = review_text->get_text();
                    saveReview(spot.get_name(), review_content); // Save with the spot name

                    g_print("Review Submitted for %s: %s\n", spot.get_name().c_str(), review_content.c_str());
                    review_window->close(); // Close the review window
                });

                review_box->pack_start(*review_text, Gtk::PACK_EXPAND_PADDING); // Add text box
                review_box->pack_start(*submit_button, Gtk::PACK_EXPAND_PADDING); // Add submit button
                review_window->add(*review_box); // Add box to the review window
                review_window->show_all(); // Show all elements in the review window
            });

            new_tab->add_overlay(*review_button); // Add the review button to the overlay

            int new_page_index = notebook->append_page(*new_tab, spot.get_name());

            if (new_page_index >= 0) {
                notebook->set_current_page(new_page_index);
            }

            new_window->show_all(); // Ensure all changes are displayed
        });

        scrollable_content->pack_start(*image_button, Gtk::PACK_EXPAND_PADDING);
    }

//    // Create star rating
//    Rating* heart_rating = Gtk::manage(new Rating());
//    heart_rating->set_halign(Gtk::ALIGN_CENTER); // Center horizontally
//    heart_rating->set_valign(Gtk::ALIGN_END); // Align towards the bottom
//    new_tab->add_overlay(*heart_rating); // Overlay the heart rating
//
//    new_tab->add_overlay(*reserve_button); // Add the reserve button to the overlay


    scroll_tab->add(*scrollable_content);


    notebook->append_page(*scroll_tab, "Home Page");
   // notebook->append_page(*profile_tab, "Profile");
    createProfileTab(notebook);

    new_window->add(*notebook); // Add the notebook to the new window
    new_window->show_all(); // Display the notebook
}

