//
// Created by Summer Faliero on 4/1/24.
//

#include "MyButton.h"
#include "Reservations.h"

MyButton::MyButton(Glib::ustring s) {
    button_label = s;
// This function will add a label to the button using the passed value.
    add_label(s);
// This connects the button widget (referenced by this) to a pointer of
// the on_button_clicked method.
    signal_clicked().connect(
            sigc::mem_fun(*this, &MyButton::on_button_clicked) );
}
MyButton::MyButton()
{
    button_label = "test Button";
// This function will add a label to the button using a default value.
    add_label(button_label);
// This connects the button widget (referenced by this) to a pointer of
// the on_button_clicked method.
    signal_clicked().connect(
            sigc::mem_fun(*this, &MyButton::on_button_clicked) );
}
// This is a destructor that does nothing in this case.
MyButton::~MyButton() { }
// A method that connected to the button by the command above.
void MyButton::on_button_clicked()
{
    std::cout << button_label << " was clicked." << std::endl;
    int napSpotID = 100;
    int userId = 1200;
    std::string userName = "summer";
    int time = 30;
    std::string status = "booked";

    Reservations tester(napSpotID, userId, time, status);

    // Call the storeData method on the created Reservations object
    tester.getNapSpotId();
        //this is where i change the page or code what happens after clicking a button
}