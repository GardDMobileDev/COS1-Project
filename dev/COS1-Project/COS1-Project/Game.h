#pragma once
#include "Player.h"
#include "Traveler.h"
#include "Location.h"


//==================================================
//   WEEK 2 UPDATES:
// - Added the Game class to control console app 
// - This will connect: Player, Traveler, Location
//==================================================
class Game 
{
  private:
	  
	  //This will store information about the player 
	  Player player;

	  //Stores the current Genesis 
	  Location currentLocation;

	  //Store travlers that are with the player
	  Traveler traveler;

	  //This will determine if the game should still run
	  bool isRunning;

  public:
	
	  //Constructor 
	  Game();

	  //Starts game loop 
	  void StartGame();

	  //Display Main Menu
	  void DisplayMainMenu();

	  //Display Instructions
	  void DisplayInstructions();

	  //Start a new journey
	  void StartJourney();

	  //Exit Game
	  void ExitGame();
};
