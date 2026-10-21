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

	Player& player;
	Location& currentLocation;
	std::vector<Location> locations;
	int currentDay;
	bool journeyActive;
	Inventory inventory;
	Event event;

	bool GetMenuSelection(const std::string& prompt, int minSelection, 
		int maxSelection, int& selection);

    std::function<void()> saveCallBack;

public: 

	Traveler(Player& player, Location& currentLocation);
	void StartJourney();
    void SetSaveCallback(std::function<void()>  callback);
	void TravelNext();
	void EndJourney();
	void ResetJourney();
	bool LoadJourney(int savedDay, const std::string&
	savedLocation);

	int GetCurrentDay() const;
	std::string GetCurrentLocation() const;
	const Inventory& GetInventory() const;

    void LoadSavedInventory(const std::vector<std::string>&
	savedNames, const std::vector<int>& savedQuantities);

	void DisplayStats();
	void DisplayLocation();
	void DisplayInventory();

	void MakeLocationSelection();
	void UseInventoryItem();
	
};