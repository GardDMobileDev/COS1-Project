#include "Inventory.h"
#include <iostream>
#include "GameUI.h"

//====================================================================================
//  WEEK 3:  CREATE INVENTORY CLASS.CPP
// 
// The purpose of this class: gives the player a small collection
// of supplies in the beginning of the journey
// 
// ULTIMATE GOAL DISPLAY:
// 
// Sack of bread       x3 
// Water container     x3
// Aloe for healing    x1
//====================================================================================
Inventory::Inventory() 
{
	//Starting items 
	AddItem("Sack of bread", 3);
	AddItem("Water container", 3);
	AddItem("Aloe for healing", 1);

}

//============================================
//  ADD ITEM
// 
// Will check if item already exists 
//Adds a new item or increases existing qty
//=============================================
void Inventory::AddItem(const std::string& itemName, int quantity)
{
	//Reject invalid item names or quantities
	if (itemName.empty() || quantity <= 0)
	{
		std::cout << "Invalid item or quantity.\n";
		return;
	}

	for (int i = 0; i < itemNames.size(); i++)
	{
		if (itemNames[i] == itemName)
		{
			itemQuantity[i] += quantity;
			return;
		}
	}

	//Add A New Item
	itemNames.push_back(itemName);
	itemQuantity.push_back(quantity);
}


//============================================
//  REMOVE ITEM
// 
// Purpose will be to remove item 
// ONLY when enough quantity exists
// Returns true if yes or false of no
//=============================================
bool Inventory::RemoveItem(const std::string& itemName, int quantity) 
{
	//Rejects invalid amounts
	if (quantity <= 0 )
	{
		return false;
	}

	for (int i = 0; i < itemNames.size(); ++i)
	{
		if (itemNames[i] == itemName)
		{
			//Not enough items available 
			if (itemQuantity[i] < quantity)
			{
				return false;
			}

			//Remove the requested quantity 
			itemQuantity[i] -= quantity;

			//When quantity reaches 0 remove item
			if (itemQuantity[i] == 0)
			{
				itemNames.erase(itemNames.begin() + i);
				itemQuantity.erase(itemQuantity.begin() + i);

			}

			return true;
		}
	}

	//No item found 
	return false;

}

//============================================
// CHECK AVAILABILITY OF ITEM
// 
// Checlks whether an item is available
//============================================
bool Inventory::HasItem(const std::string& itemName, int quantity) const
{
	if (quantity <= 0)
	{
		return false;
	}

	return GetItemQuantity(itemName) >= quantity;

}

//============================================
// DISPLAY INVENTORY 
// 
// Shows all items and quantities 
//=============================================
void Inventory::DisplayInventory() const
{
	DisplayHeader("PLAYER INVENTORY");

	if (itemNames.empty())
	{
		std::cout << "Your inventory is empty.\n";
	}
	else
	{
		for (int i = 0; i < itemNames.size(); ++i)
		{
			std::cout << i + 1 << ". " << itemNames[i] << " x "
				<< itemQuantity[i] << '\n';
		}
	}

	DisplayDivider();
}

//============================================
// GET ITEM QUANTITY 
// 
// returns the quanitity of a specific item
//=============================================
int Inventory::GetItemQuantity(const std::string& itemName) const
{
	for (int i = 0; i < itemNames.size(); ++i)
	{
		if (itemNames[i] == itemName)
		{
			return itemQuantity[i];
		}
	}

	return 0;

}

//============================================
// GET ITEM COUNT
// 
// returns number of item types 
//=============================================
int Inventory::GetItemCount() const
{
	return static_cast<int>(itemNames.size());
}

//============================================
// RESET INVENTORY
//=============================================
void Inventory::ResetInventory() 
{
	//Need to use to reset : removes all elements from vector
	itemNames.clear();
	itemQuantity.clear();

	//Restore starting items
	AddItem("Sack of bread",3);
	AddItem("Water container", 3);
	AddItem("Aloe for healing", 1);

}

//==============================================
// LOAD INVENTORY
// 
// restores inventory from saved game data 
//===============================================
void Inventory::LoadInventory(const std::vector<std::string>&
	savedNames, const std::vector<int>& savedQuantities
) 
{

//==============================================
//  CLEAR THE CURRENT JOURNEY
//===============================================
itemNames.clear();
itemQuantity.clear();

//==============================================
//  MAKE SURE THE SAVED DATA MATCHES
//===============================================
if (savedNames.size() != savedQuantities.size())
{
	return;
}

//==============================================
//  RESTORE EACH SAVED ITEM
//===============================================
for (int i = 0; i < savedNames.size(); ++i)
{
	if (!savedNames[i].empty() && savedQuantities[i] > 0)
	{
		AddItem(savedNames[i], savedQuantities[i]);
	}
}

}

//===============================================
// GET ITEM NAME
//
// Get the name of an inventory item by index
//===============================================
std::string Inventory::GetItemName(int index) const 
{
	if (index <0 || index >= static_cast<int>(itemNames.size()))
	{
		return "";
	}

	return itemNames[index];

}