#pragma once
#include <string>
#include <vector>

//====================================================================================
//  WEEK 3:  CREATE INVENTORY CLASS 
// 
// The purpose of this class is to track individual items used on the journey
// Right now everything is just Food/Water (This is not the same as Player supplies)
// 
// Responsible for: 
// Storing item names/quantities
// Add items to inventory
// Remove/Use items
// Display current inventory
// Check items availability
//====================================================================================
class Inventory 
{
private:
	//Store the names of items
	std::vector<std::string> itemNames;

	//Stores quantity of each item : index will match the itemNames vector
	std::vector<int> itemQuantity;

public: 

	//Constructor to initialize starting inventory
	Inventory();

	//Add or increase item or its quantity
	void AddItem(const std::string& itemName, int quantity);

	//Remove a specific quantity of an item
	bool RemoveItem(const std::string& itemName, int quantity);

	//Get the total number of distinct item types 
	int GetItemCount() const;

};

