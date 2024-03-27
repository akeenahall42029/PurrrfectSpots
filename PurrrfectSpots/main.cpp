#include <iostream>
#include "Demo.cpp"
#include "Reservations.h"

void linkRes(int napSpotID, int userId, std::string& userName, int time, const std::string& status){
    Reservations example_res(napSpotID,userId,userName,time,status);
    example_res.storeData();
}
int main() {
    // prompt user for input
    std::string lineBreak = " ";
    std::string reviews= "\033[1;96mReviews:\033[0m";
    std::string tags1= "\033[1;34m#comfy #warm #chic\033[0m";
    std::string tags2= "\033[1;34m#cool #cozy #cute\033[0m";
    std::string tags3= "\033[1;34m#justokay #addictive\033[0m";
    std::string tags4= "\033[1;34m#comfy #cozy\033[0m";
    std::string aveRating1= "\033[1;96mAverage Rating:\033[0m 3 Stars";
    std::string aveRating2= "\033[1;96mAverage Rating:\033[0m 4 Stars";
    std::string aveRating3= "\033[1;96mAverage Rating:\033[0m 5 Stars";


//sunny spot (faliero palace)
    std::string r1a = "kittyluvrxox: Pawsitively Perfect Sunbathing Spot-- ";
    std::string r1b = "'My kitty, Whiskers, gives this sunny patch of hardwood two paws up! It's the ultimate spot ";
    std::string r1c = "for soaking up rays while dreaming of chasing butterflies. A purr-fect way to start the day!'";

    std::string r2a = "sebastianthecat08: Sunbeam Heaven-- ";
    std::string r2b = "'Meow! This spot is the cat's meow! With the sun streaming in just right, it's like a warm hug from ";
    std::string r2c = "Mother Nature herself. My fur feels like it's glowing after a nap here!'";

    std::string r3a = "catmom12345: Cat's Paradise, Human's Nightmare-- ";
    std::string r3b = "'While Fluffy adores this sunny patch, I must say, the constant basking leads to relentless";
    std::string r3c = "demands for treats and belly rubs. I haven't had a moment's peace since she discovered it! Send help... and more treats.'";

    std::string r10a="Available times (A) 1.pm,(B) 2p.m,(C) 3p.m (note all reservation last an Hour)";




//bookbag (akeena saga)
    std::string r4a = "meowsalot09: Bagged My Heart-- ";
    std::string r4b = "'Who needs fancy beds when you have a cozy bookbag? My feline friend, Mittens, has claimed this humble spot";
    std::string r4c = "as her throne. She reigns supreme, surveying her kingdom from atop the bag. Long live the queen of comfort!'";

    std::string r5a = "catdad84: Adventure Awaits-- ";
    std::string r5b = "'This bookbag-turned-nap spot is like a magic carpet ride for Whiskers. One minute he's curled up, dreaming";
    std::string r5c = "of distant lands, the next he's off on imaginary adventures, chasing mice through ancient libraries. A must for any cat with an adventurous spirit!'";

    std::string r6a = "angrycatmom: Baggage Claim-- ";
    std::string r6b = "'Do not be fooled by the innocent appearance of this bookbag nap spot. It's a trap! Once Fluffy settles in, she";
    std::string r6c = "becomes one with the bag, rendering it unusable for any human endeavor. I fear we may need an intervention... and a new bag.'";


//laundry (sanaa suite)
    std::string r7a = "whiskersmomma: Laundry Day Delight: ";
    std::string r7b = "'The scent of fresh laundry is like catnip to Whiskers. He can't resist diving headfirst into the warm pile,";
    std::string r7c = "claiming it as his own personal nest. It's a joy to watch him snuggle into the soft fabrics, dreaming of a world filled with endless treats.'";

    std::string r8a = "sanaasuitecleaner: Laundry Day Disaster: ";
    std::string r8b = "'Just when I thought my laundry woes couldn't get any worse, along comes Fluffy, turning my freshly-folded clothes into her own personal playground. The pile of freshly-washed";
    std::string r8c = "laundry has become her kingdom, and I, a humble servant to her fur-covered whims.'";

    std::string r9a = "catdad84: Fabric Fantasy-- ";
    std::string r9b = "'This pile of freshly-washed laundry is like a cloud of comfort for Mittens. She spends hours";
    std::string r9c = "kneading the soft fabrics, lost in a sea of blissful dreams. Who needs cat beds when you have a mountain of warm laundry to conquer?'";


    std::string napSpotSelection = "\033[1;95mTo select a NapSpot, please type the number associated with the spot you would like to inspect:\033[0m";
    std::string suite = "\033[1;32m1.\033[0m The Hines Suite";
    std::string saga = "\033[1;32m2.\033[0m The Hall Saga";
    std::string palace = "\033[1;32m3.\033[0m The Faliero Palace";

    std::cout << lineBreak << std::endl;
    std::cout << lineBreak << std::endl;
    // prompt for userName
    std::cout <<"Hello Happy Napper, please enter your user name!: " <<std::endl;
    std::cout << lineBreak << std::endl;
    std::string userName;
    std::cin >> userName; // store userName as user's input

    // Display napSpot options
    std::cout << napSpotSelection << std::endl;
    std::cout << lineBreak << std::endl;
    std::cout << suite << std::endl;
    std::cout << saga << std::endl;
    std::cout << palace << std::endl;
    std::cout << lineBreak << std::endl;

    //time method

    // Read user input
    int num;
    //const char * abc;
    std::cin >> num;
    //std::cin >> abc;

    // Process input
    int napSpot = num;

    //const char * napSpotTime = abc;

    // Variables for reservation object parameters
    int napSpotId;
    int time;


    // Output result
    if (napSpot == 1) {
        napSpotId = 999999999;
        std::cout << lineBreak << std::endl;
        std::cout << "\033[1;95mYou have selected the Hines Suite!\033[0m" << std::endl;
        std::cout << lineBreak << std::endl;
        std::string hinesLoc = "\033[1;96mSpot Specification:\033[0m pile of freshly-washed laundry :)";
        std::cout << hinesLoc << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << reviews << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << r7a << std::endl;
        std::cout << r7b << std::endl;
        std::cout << r7c << std::endl;
        std::cout << tags1 << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << r8a << std::endl;
        std::cout << r8b << std::endl;
        std::cout << r8c << std::endl;
        std::cout << tags3 << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << r9a << std::endl;
        std::cout << r9b << std::endl;
        std::cout << r9c << std::endl;
        std::cout << tags2 << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << aveRating2 << std::endl;
        std::cout << lineBreak << std::endl;

       // PROMPT TIME
        // Print three different times
        std::cout << "\033[34mSelect a reservation time\n\033[0m";
        std::cout << "1. 1pm\n";
        std::cout << "2. 2pm\n";
        std::cout << "3. 3pm\n";

        // Prompt user to enter their choice
        std::cout << "Enter your choice (1, 2, or 3): ";
        std::cin >> time;

        // Validate user input
        if (time >= 1 && time <= 3) {
            // Process the selected time
            std::cout << "You selected " << time << "pm.\n";
            std::cout << " "<< std::endl;
            std::cout <<"Reservation Summary : Hines Suite at " << time<<"pm.";
            std::cout << lineBreak << std::endl;
        } else {
            // Invalid input
            std::cout << "Invalid input. Please enter 1, 2, or 3.\n";
        }

        // LINK EVERYTHING

        linkRes(napSpotId,123456789,userName, time,"Booked");


    }

    if (napSpot == 2) {
        napSpotId = 222222222;
        std::cout << lineBreak << std::endl;
        std::cout << "\033[1;95mYou have selected the Hall Saga!\033[0m" << std::endl;
        std::cout << lineBreak << std::endl;
        std::string hallLoc = "\033[1;96mSpot Specification:\033[0m bookbag on the floor :)";
        std::cout << hallLoc << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << reviews << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << r4a << std::endl;
        std::cout << r4b << std::endl;
        std::cout << r4c << std::endl;
        std::cout << tags4 << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << r5a << std::endl;
        std::cout << r5b << std::endl;
        std::cout << r5c << std::endl;
        std::cout << tags1 << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << r6a << std::endl;
        std::cout << r6b << std::endl;
        std::cout << r6c << std::endl;
        std::cout << tags3 << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << aveRating1 << std::endl;
        std::cout << lineBreak << std::endl;

        // Print three different times
        std::cout << "\033[34mSelect a reservation time\n\033[0m";
        std::cout << "1. 1pm\n";
        std::cout << "2. 2pm\n";
        std::cout << "3. 3pm\n";

        // Prompt user to enter their choice
        std::cout << "Enter your choice (1, 2, or 3): ";
        std::cin >> time;

        // Validate user input
        if (time >= 1 && time <= 3) {
            // Process the selected time
            std::cout << "You selected " << time << "pm.\n";
            std::cout << " "<< std::endl;
            std::cout <<"Reservation Summary : Hall Saga at "  << time<<"pm.";
            std::cout << lineBreak << std::endl;
        } else {
            // Invalid input
            std::cout << "Invalid input. Please enter 1, 2, or 3.\n";
        }

        // LINK EVERYTHING
        linkRes(napSpotId,123456789,userName, time,"Booked");

    }

    if (napSpot == 3) {
        napSpotId = 333333333;
        std::cout << lineBreak << std::endl;
        std::cout << "\033[1;95mYou have selected the Faliero Palace!\033[0m" << std::endl;
        std::cout << lineBreak << std::endl;
        std::string falieroLoc = "\033[1;96mSpot Specification:\033[0m sunny patch of hardwood :)";
        std::cout << falieroLoc << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << reviews << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << r1a << std::endl;
        std::cout << r1b << std::endl;
        std::cout << r1c << std::endl;
        std::cout << tags2 << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << r2a << std::endl;
        std::cout << r2b << std::endl;
        std::cout << r2c << std::endl;
        std::cout << tags4 << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << r3a << std::endl;
        std::cout << r3b << std::endl;
        std::cout << r3c << std::endl;
        std::cout << tags3 << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << lineBreak << std::endl;
        std::cout << aveRating3 << std::endl;
        std::cout << lineBreak << std::endl;

        // PROMPT TIME


        // Print three different times
        std::cout << "\033[34mSelect a reservation time\n\033[0m";
        std::cout << "1. 1pm\n";
        std::cout << "2. 2pm\n";
        std::cout << "3. 3pm\n";

        // Prompt user to enter their choice
        std::cout << "Enter your choice (1, 2, or 3): ";
        std::cin >> time;

        // Validate user input
        if (time >= 1 && time <= 3) {
            // Process the selected time
            std::cout << "You selected " << time << "pm.\n";
            std::cout << " "<< std::endl;
            std::cout <<"Reservation Summary : Faliero Palace at "  << time<<"pm.";
            std::cout << lineBreak << std::endl;
        } else {
            // Invalid input
            std::cout << "Invalid input. Please enter 1, 2, or 3.\n";
        }

        // LINK EVERYTHING
        linkRes(napSpotId,123456789,userName, time,"Booked");
    }



}






