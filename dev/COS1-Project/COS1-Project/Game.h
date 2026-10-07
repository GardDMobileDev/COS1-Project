#pragma once
#include "Player.h"
#include "Traveler.h"
#include "Location.h"

/*
  This class controls the overall Genesis Journey. This will work with 
  Player, Traveler and Location classes. 
*/

class Game 
{
  private:
	  
	  //This will store information about the player 
	  Player player;

	  //Store travlers that are with the player
	  Traveler traveler;

	  //Stores the current Genesis 
	  Location currentLocation;

	  //This will determine if the game should still run
	  bool isRunning;

	 


};
