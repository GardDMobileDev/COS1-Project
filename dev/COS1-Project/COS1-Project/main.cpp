#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Player.h"
#include "Traveler.h"
#include "Location.h"

/*
FUNCTION DECLARATIONS 
  - Functions to start The Bible Trail 

        - GetMenuChoice : menu choice from player
        - DisplayMainMenu : displays menu
        - DisplayInstructions : displays game instructions
        - StartJourney : Starts/controls journey of Player 
*/

//GetMenuChoice 
int GetMenuChoice(int min, int max);

//Display Main Menu 
void DisplayMainMenu();

//Display Instructions 
void DisplayInstructions();

//Start Journey 
void StartJourney(Player& player, Traveler& travelers, std::vector<Location> locations);


/*
  The main:
    - This will be the control flow. This creates Player/Travler objects.
    - This will store location in Genesis into a vector (REQUIREMENT)
    - This will use input validation check for user entry
    - The app should Display a menu for the player to start, view instructions
    of the game or exit.

   Program Runs:
       - Asks for name
       - Provides Options to
           - View Status
           - View Travelers
           - View Locations
           - Continue on Journey
 */
int main()
{

    //Create a Player 
    Player player;

    //Create a Traveler : starts the group
    Traveler travelers;

    //Create Locations : vector will store multiple objects
    std::vector<Location> locations;

    /*
       Books of Genesis Locations (Important Locations)
       
       1. Garden of Eden: God placed Adam and Eve to tend before banishing them for sin 

       2. Noahs Ark: God commands Noah to build, spare his family/animals before the flood 

       3. Tower of Babel: A tower built by people to be boastful, not for God, 
       because they spoke the same lanaguage they could continue to build so he 
       made them all speak different languages to cause confusion

       4. Abrahams Journey: The man who was the example of true fath, God made a promise
       to give him the Promise Land, bless his decendents, and all of his family line
       for his obedience

       5. Egypt: A journey in Egpty ( to be continued ) 
    
    */
    locations.push_back(Location("Garden of Eden", "The Garden Adam was suppose to tend to with Eve."));
    locations.push_back(Location("Noah's Ark", "The world is full of sin. Noah has been tasked to build an ark."));
    locations.push_back(Location("Tower of Babel", "People are gathered to build a great city and tower."));
    locations.push_back(Location("Abraham's Journey", "Abraham leaves home, packs up his family and God leads him to the Promise Land."));
    locations.push_back(Location("Egypt", "The Journey reach Egypt. This is a significant location."));
 
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
