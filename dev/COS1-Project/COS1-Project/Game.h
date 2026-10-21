#pragma once
#include "Player.h"
#include "Traveler.h"
#include "Location.h"
#include "SaveSystem.h"
//==================================================
//   GAME CLASS 
// 
//  Controls the main game flow, menu nav,
// player informationa and journey systems
//==================================================
class Game 
{
  private:
	  Player player;
	  Location currentLocation;
	  Traveler traveler;
	  SaveSystem  saveSystem;
	  bool isRunning;

  public:
	  Game();
	  void StartGame();
	  void DisplayMainMenu();
	  void DisplayInstructions();
	  void StartJourney();
	  void SaveCurrentJourney();
	  void ExitGame();
};
