#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "Location.h"
#include "Inventory.h"
#include "Event.h"
#include <functional>

//==================================================
//   TRAVELER CLASS
//
// Manages the player's journey, Genesis locations,
// travel progression, resources, inventory, and 
// events
//==================================================
class Traveler
{
private:
//==================================================
//   PLAYER REFERENCE
//
// Provides access to the players information 
// and stats
//==================================================
	Player& player;

//==================================================
//   CURRENT LOCATION REFERENCE 
//
// Provides access to the current location object
//==================================================
	Location& currentLocation;

	
//==================================================
//  GENESIS LOCATION
//
// Stores locations in travel order 
//==================================================
	std::vector<Location> locations;

//==================================================
//  CURRENT DAY 
//
// Tracks the number of days in the journey
//==================================================
	int currentDay;

//==================================================
//  JOURNEY STATUS
// 
// Indicates whether the journey is active 
//==================================================

	bool journeyActive;

//==================================================
//  INVENTORY 
// 
// Manages the items available to the traveler
//==================================================
	Inventory inventory;

//==================================================
//  EVENT 
// 
// Manages  events encountered during the journey 
//==================================================
	Event event;


//==================================================
//  GET MENU SELECTION 
// 
// Validates user input and returns a valid selection 
// within the specified range
//==================================================

	bool GetMenuSelection(const std::string& prompt, int minSelection, 
		int maxSelection, int& selection);

//==================================================
//   SAVE CALL BACK
//
//Function used to save the current journey 
//==================================================
std::function<void()> saveCallBack;

public: 
//==================================================
//  TRAVELER CONSTRUCTOR 
// 
// Initializes the traveler using references 
// to the player and current location
//==================================================

	Traveler(Player& player, Location& currentLocation);


//==================================================
//  START JOURNEY 
// 
// Starts the journey and displays its menu
//==================================================

	void StartJourney();

//==================================================
//   SAVE CALL BACK
//
//Function used to save the current journey 
//==================================================
void SetSaveCallback(std::function<void()>  callback);

//==================================================
//  TRAVEL NEXT 
// 
// advances the journye and displays its ment
//==================================================

	void TravelNext();

//==================================================
//  END JOURNEY 
// 
// Ends the current journey 
//==================================================

	void EndJourney();

//==================================================
//  RESET JOURNEY 
// 
// Resets journey progress 
//==================================================
	void ResetJourney();

//==================================================
//  LOAD JOURNEY 
// 
// Restores journey progress from a saved game
//==================================================
	bool LoadJourney(int savedDay, const std::string&
	savedLocation);

//==================================================
//  GETS THE CURRENT JOURNEY DAY
//  GETS THE CURRENT LOCATION
//  GETS THE CURRENT INVENTORY
// 
// 	Allows other function to read journey info
// 	without accessing private vars
//==================================================
	int GetCurrentDay() const;
	std::string GetCurrentLocation() const;
	const Inventory& GetInventory() const;


//==================================================
//  LOAD SAVED INVENTORY
// 
// Restores inventory from a saved game
//==================================================
void LoadSavedInventory(const std::vector<std::string>&
	savedNames, const std::vector<int>& savedQuantities);


//==================================================
//  DISPLAY STATS 
// 
// Methods for displaying player, location, and 
// 	   inventory information
//==================================================
	void DisplayStats();

//==================================================
//  DISPLAY LOCATION
// 
// Displays information about the current location
//==================================================
	void DisplayLocation();


//==================================================
//  DISPLAY INVENTORY 
// 
// Displays the available inventory items
//==================================================
	void DisplayInventory();


//==================================================
//  MAKE LOCATION SELECTION
// 
// Process the players choice at a location
//==================================================

	void MakeLocationSelection();

//==================================================
//  USE INVENTORU ITEM
// 
// Allows the player to use an inventory item
//==================================================
	
	void UseInventoryItem();
	
};