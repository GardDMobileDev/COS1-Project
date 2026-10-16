#pragma once
#include "Player.h"
#include "Traveler.h"
#include "Location.h"


//==================================================
//   GAME CLASS 
// 
//  Controls the main game flow, menu nav,
// player informationa and journey systems
//==================================================
class Game 
{
  private:
	  
	//==================================================
	//  PLAYER 
	// 
	//  Stores the players informaton and status
	//==================================================
	  Player player;


	//==================================================
	// CURRENT LOCATION 
	// 
	// Stores the current Genesis location
	//==================================================
	  Location currentLocation;

	
	//==================================================
	// TRAVELER 
	// 
	// Manages travel, journey progress and resources 
	//==================================================
	  Traveler traveler;


	//==================================================
	// RUNNING STATE 
	// 
	// Determins wheter the main game loop continues
	//==================================================
	  bool isRunning;

  public:
	
	//==================================================
	// GAME CONSTRUCTOR
	// 
	// Initializes the game and its member objects
	//================================================== 
	  Game();

	//==================================================
	// START GAME
	// 
	// Runs the main game loop
	//================================================== 
	  void StartGame();

	//==================================================
	// DISPLAYS MAIN MENU 
	// 
	// Displays the main menu and processes selections
	//================================================== 
	  void DisplayMainMenu();


	//==================================================
	// DISPLAYS INSTRUCTIONS
	// 
	// Displays the game instructions and features 
	//================================================== 
	  void DisplayInstructions();

	 
	//==================================================
	// STARY JOURNEY 
	// 
	// Initalizes and begins a new journey 
	//================================================== 
	  void StartJourney();

	//==================================================
	// EXIT GAME 
	// 
	// Stops the game loop and displays the exit message
	//================================================== 
	  void ExitGame();
};
