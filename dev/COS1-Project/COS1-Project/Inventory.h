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

	
	//==============================================
	// CONSTRUCTOR
	// 
	// Constructor to initialize starting inventory
	//===============================================
	Inventory();

	//==============================================
	// ADD ITEM
	// 
	// Add or increase item or its quantity
	//===============================================
	void AddItem(const std::string& itemName, int quantity);

	//==============================================
	// REMOVE ITEM
	// 
	// Remove a specific quantity of an item
	//===============================================
	bool RemoveItem(const std::string& itemName, int quantity);

	
	//==============================================
	// HAS ITEM (check)
	// 
	// Check if item has enough quantity
	//===============================================
	bool HasItem(const std::string& itemName, int quantity = 1) const;


	//==============================================
	//  DISPLAY INVENTORY
	// 
	// Display all inventory Items
	//===============================================
	void DisplayInventory() const;

	
	//==============================================
	//  GET ITEM QUANTITY
	// 
	// Get quantity of an item 
	//===============================================
	int GetItemQuantity(const std::string& itemName) const;

	//==============================================
	//  GET ITEM COUNT
	// 
	// Get the total number of distinct item types 
	//===============================================
	int GetItemCount() const;

	//==============================================
	//  RESET JOURNEYS
	// 
	// Get the total number of distinct item types 
	//===============================================
	void ResetInventory();

	//==============================================
	// LOAD INVENTORY
	// 
	// restores inventory from saved game data 
	//===============================================
	void LoadInventory(const std::vector<std::string>&
		savedNames, const std::vector<int>& savedQuantities
	);

};

