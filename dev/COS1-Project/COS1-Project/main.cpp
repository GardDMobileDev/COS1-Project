#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Player.h"
#include "Traveler.h"
#include "Location.h"
#include "GameUI.h"
#include "Game.h"
#include "Inventory.h"

//==================================================
//   MAIN FUNCTION GAME 
//
//   Creates the game object and starts Bible Trail
//==================================================

int main()
{
    
    //==================================================
    //  INITIALIZE
    //
    //   Creates the game object and starts Bible Trail
    //==================================================
    Game game;

   
    //==================================================
    //  START GAME 
    //
    //  Launches the main menu and game flow
    //  Return 0: Program ended as normal
    //==================================================
    game.StartGame();

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
