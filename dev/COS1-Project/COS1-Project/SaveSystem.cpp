#include "SaveSystem.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

//==================================================
// SAVE SYSTEM IMPLEMENTATION
//
// File saving and loading functionality 
//==================================================
bool SaveSystem::SaveGame(
	const std::string& fileName,
	const Player& player, 
	const Traveler& traveler) 
{
	std::ofstream file(fileName);

	if (!file.is_open())
	{
		std::cout << "Unable to open save file.\n";
		return false;
	}

	//==================================================
	// SAVE PLAYER INFORMATION
	//==================================================
	file << player.GetName() << '\n';
	file << player.GetHealth() << '\n';
	file << player.GetFood() << '\n';
	file << player.GetWater() << '\n';
	file << player.GetSupplies() << '\n';
	file << player.GetMorale() << '\n';

	//==================================================
	// SAVE JOURNEY PROGRESS
	//==================================================
	file << traveler.GetCurrentDay() << '\n';
	file << traveler.GetCurrentLocation() << '\n';

	//==================================================
	// SAVE INVENTORY ITEMS/QTYS
	//==================================================
	const Inventory& inventory = traveler.GetInventory();

	file << inventory.GetItemCount() << '\n';

	for (int i = 0; i < inventory.GetItemCount(); ++i)
	{
	
	file << inventory.GetItemName(i) << '\n';		
	file << inventory.GetItemQuantity(inventory.GetItemName(i)) << '\n';

	}

	if (!file)
	{
		std::cout << "Error writing saved file\n";
		return false;
	}

	file.close();
	std::cout << "Game saved successfully!\n";
	return true;

}



//==================================================
// LOAD GAME
//
// Reads and restores a previously saved journey
//==================================================
bool SaveSystem::LoadGame(const std::string& fileName, 
	Player& player, Traveler& traveler) 
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cout << "No saved journey could be open\n";
		return false;
	}


	//==================================================
	// READ PLAYER INFORMATION
	//==================================================
	std::string playerName;
	int health, food, water, supplies, morale;
	int savedDay;
	std::string savedLocation;

	if (!std::getline(file, playerName) || 
		!(file >> health >> food >>
			water >> supplies >> morale))
	{
		std::cout << "Save file is invalid or incomplete.\n";
		return false;
	}

	file.ignore(10000, '\n');

	if (!(file >> savedDay))
	{
		std::cout << "Save file is invalis or incomplete.\n";
		return;
	}

	file.ignore(10000, '\n');

	if (!std::getline(file, savedLocation))
	{
		std::cout << "Save file is invalis or incomplete.\n";
		return;
	}

	//==================================================
	// READ INVENTORY
	//==================================================
	int itemCount;

	if (!(file >> itemCount) || itemCount < 0 || itemCount > 100 )
	{
		std::cout << "Invalid inventory data in save file.\n";
		return false;
	}

	file.ignore(10000, '\n');

	std::vector<std::string> itemNames;
    std::vector<int> itemQuantities;

	for (int i = 0; i < itemCount; ++i)
	{
		std::string itemName;
		int quantity;

		if (!std::getline(file, itemName) ||
			!(file >> quantity) || itemName.empty()
			|| quantity < 0)
		{
			std::cout << "Invalid inventory data in save file\n";
			return false;
		}

		file.ignore(10000, '\n');

		itemNames.push_back(itemName);
		itemQuantities.push_back(quantity);
	}
		//==================================================
		// VALIDATE PLAYER STATS BEFORE APPLYING 
		//==================================================
		if (playerName.empty() ||
			health < 0 || health > 60 ||
			food < 0 || food > 60 ||
			water < 0 || water > 60 ||
			supplies < 0 || supplies > 100 ||
			morale < 0 || morale > 100 ||
			savedDay < 1)
		{
			std::cout << "Saved file contains invalid player data.\n";
			return false;
		}
		//==================================================
		// RESTORE JOURNEY LOCATION AND DAY FIRST
		//==================================================
		if (!traveler.LoadJourney(savedDay, savedLocation))
		{
			std::cout << "Saved location not recognized.\n";
			return false;
		}

		//==================================================
		// RESTORE PLAYER AND INVENTORY
		//==================================================
		player.SetName(playerName);
		player.LoadStats(health, food, water, supplies, morale);

		traveler.LoadSavedInventory(itemNames, itemQuantities);

		std::cout << "Journey loaded!\n";
		return true;
}