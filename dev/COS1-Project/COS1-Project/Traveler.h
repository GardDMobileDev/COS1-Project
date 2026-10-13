#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "Location.h"
#include "Inventory.h"
#include "Event.h"

//================================
//  TRAVELER UPDATES 
// Tracks current day 
// Controls travel system 
// Connext Player/Location class
// Handle Managing Resources
// Declare travel, stats and location selection
// 
// Week 3 Updates:
// Manage Inventory and item usage
// Added Inventory inventory;
// Added DisplayInventory() 
//================================
class Traveler
{
private:
	//Traveler access to player information 
	Player& player;

	//Reference to curren location object
	Location& currentLocation;

	//Stores the Genesis locations in travel order
	std::vector<Location> locations;

	//Tracks number of days in the journey 
	int currentDay;

	//Is the journey active 
	bool journeyActive;

	//Stores the players individual inventory items/event management
	Inventory inventory;
	Event event;

	//Validation Helper Method
	bool GetMenuSelection(const std::string& prompt, int minSelection, 
		int maxSelection, int& selection);


public: 
	//Constructor : Gets Location/Player objects
	Traveler(Player& player, Location& currentLocation);


	//==================================================
	//          JOURNEY CONTROLS
	//==================================================

	//Start Journey Menu 
	void StartJourney();

	//Will move player to next location 
	void TravelNext();

	//End Current Journey 
	void EndJourney();

	//Issue Week 3: Need to create a method to "refresh journey, 
	//new journey started at end of last 
	void ResetJourney();


	//==================================================
	//          DISPLAY METHODS
	//==================================================
	//Displays Players current status 
	void DisplayStats();

	//Display Location
	void DisplayLocation();


	//Display Inventory 
	void DisplayInventory();



	//==================================================
	//          PLAYER CHOICES
	//==================================================

	//Hanlds a selection at Genesis Location 
	void MakeLocationSelection();

	
	//Allows player to use an inventory item
	void UseInventoryItem();
	
};