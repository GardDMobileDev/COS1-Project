#include "Inventory.h"
#include <iostream>
#include "GameUI.h"

//====================================================================================
//  WEEK 3:  CREATE INVENTORY CLASS.CPP
// 
// The purpose of this class: gives the player a small collection
// of supplies in the beginning of the journey
//====================================================================================
Inventory::Inventory() 
{
	//Starting items 
	AddItem("Sack of bread", 3);
	AddItem("Water container", 3);
	AddItem("Aloe for healing ", 1);

}

//============================================
//  ADD ITEM
// 
// Will check if item already exists 
// then increases quantity
// Or add a new item to inventory
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
// CHECK AVAILABILITY
//=============================================
