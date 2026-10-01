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


int main()
{
  
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
