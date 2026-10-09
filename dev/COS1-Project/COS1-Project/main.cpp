#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Player.h"
#include "Traveler.h"
#include "Location.h"
#include "GameUI.h"
#include "Game.h"

/*
FUNCTION DECLARATIONS Week 1
  - Functions to start The Bible Trail 

        - GetMenuChoice : menu choice from player
        - DisplayMainMenu : displays menu
        - DisplayInstructions : displays game instructions
        - StartJourney : Starts/controls journey of Player 

* WEEK 2 CODE MOVED INTO GAME CONTROLLER/UPDATED AS NEEDED
  The main:
    - This will be the control flow. This creates Player/Traveler objects.
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
        This will now only handle the start of Bible Trail
*/
int main()
{
    //Create Bible Trail and connect the objects
    Game game;

    //Start the Genesis Main Menu
    game.StartGame();

    //Return 0: Program ended as normal
    return 0;

  
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
