#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "Location.h"

/*
 This class will keeps track of all the travelers with the player.
   - The vector will store travelers : can be increased or reduced
   - Methods : addTraveler, Display and getTravelerSize 
*/

//================================
//  TRAVELER UPDATES 
// Tracks current day 
// Controls travel system 
// Connext Player/Location class
// Handle Managing Resources
//================================
class Traveler
{
private:
	//Traveler access to player information 
	Player& player;

	//Reference to curren location object
	Location& currentLocation;

	//Tracks number of days in the journey 
	int currentDay;

	//Is the journey active 
	bool journeyActive;

public: 
	//Constructor : Gets Location/Player objects
	Traveler(Player& player, Location& currentLocation);

	//Start Journey Menu 
	void StartJourney();

	//Will move player to next location 
	void TravelNext();

	//Displays Players current status 
	void DisplayStats();

	//Display Location
	void DisplayLocation();

	//Hanlds a selection at Genesis Location 
	void MakeLocationSelection();

	//End Current Journey 
	void EndJourney();

};