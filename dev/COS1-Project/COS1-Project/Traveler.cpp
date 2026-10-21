#include "Traveler.h"
#include "GameUI.h"
#include <iostream>
#include <string>

//==================================================
//   TRAVELER CONSTRUCTOR 
// 
// Initializes the player and location references, 
// Genesis locations, inventory, and journey state
//==================================================
Traveler::Traveler(Player& player, Location& currentLocation) :
	player(player), currentLocation(currentLocation),
	//Week 3 Updates
	locations{
	Location("Garden of Eden", "Adam and Eve were placed to attend the Garden."),
	Location("Noah's Ark", "Noah builds the Ark in preparation for the flood."),
	Location("Tower of Babel", "Tower of Babel built to reach the Heavens."),
	Location("Abraham's Journey", "Abraham leaves his home on God's command."),
	Location("Egypt", "Joseph's story begins in Egypt.")
    },
	inventory(),
	currentDay(1), 
	journeyActive(false)
{
     //Set the starting location 
	 currentLocation = locations.front();
}


//==================================================
// START JOURNEY 
//
// Displays the journey menu and processes player
// selections until the journey ends
//==================================================
void Traveler::StartJourney()
{
	journeyActive = true;

	while (journeyActive)
	{
		//If event occurs blocks players from performing selection if they fail : Week 3 feedback uodate
		if (player.GetHealth() <= 0)
		{
			DisplayHeader("GAME OVER");
			std::cout << "Your journey has come to end.\n";
			journeyActive = false;
			break;

		}

		int selection = 0;
		DisplayHeader("YOUR JOURNEY");

		//==================================================
		//      YOUR JOURNEY MENU 
		//==================================================
		std::cout << "Day: " << currentDay << "\n";
		std::cout << "Location: " << currentLocation.GetName() << "\n";

		std::cout << "\n1. Travel to Next Location\n";
		std::cout << "2. View Player Stats\n";
		std::cout << "3. View Current Location\n";
		std::cout << "4. Make A Location Selection\n"; //update
		std::cout << "5. View Inventory\n"; 
		std::cout << "6. Use an Inventory Item\n";
		std::cout << "7. Save Journey\n";
        std::cout << "8. End Journey \n";

		if (!GetMenuSelection("\nEnter your selection: ", 1,8, selection))
		{
			if (!journeyActive)
			{
				break;
			}

			continue;
		}

		DisplayDivider();

		switch (selection)
		{

		case 1:TravelNext(); break;
        case 2:DisplayStats();break;
        case 3:DisplayLocation();break;
		case 4:MakeLocationSelection();break;
        case 5:DisplayInventory();break;
        case 6:UseInventoryItem();break;
		case 7:
			if (saveCallBack)
			{
				saveCallBack();
			}
			else
			{
				std::cout << "Save system is unavailable.\n";
			}
			break;

		case 8:EndJourney();break;
		default: std::cout << "Invalid selection. Please try again.\n"; break;
		}

	}
}

//==================================================
// TRAVEL TO NEXT LOCATION
//
// Advances the journey by one day, consumes food 
// and water, and processes location events
//==================================================
void Traveler::TravelNext()
{
	//Prevents players from bypassing survival conditions by travel next 
	if (player.GetHealth() <= 0)
	{
		std::cout << "\n You cannont travel, you dont have the resources or heakth to move on!";
		return;
	}


	//Find the current location
	int currentIndex = -1;
	for (int i = 0; i < locations.size(); ++i)
	{
		if (locations[i].GetName() == currentLocation.GetName())
		{
			currentIndex = i;
			break;
		}
	}

	//Verify that current location exists
	if (currentIndex == -1)
	{
		std::cout << "Unable to locate current location\n";
		return;
	}

	//Check if player is already in Egypt
	if (currentLocation.GetName() == "Egypt")
	{
		DisplayHeader("JOURNEY COMPLETE");

		std::cout << "Your group has reached Egypt!\n";
		std::cout << "Your journey through Genesis is complete\n";
		std::cout << "\nYOU WIN!\n";
		journeyActive = false;
		return;
	}

	++currentDay;

	player.ChangeFood(-5);
	player.ChangeWater(-5);
	player.ChangeHealth(-10);

	std::cout << "You traveled for one day.\n\n";
	std::cout << "Food decreased by 5.\n";
	std::cout << "Water decreased by 5.\n\n";
	std::cout << "You all are exhausted. You lost 10 health.\n\n";

	//Update: apply health damage if food runs out
	if (player.GetFood() == 0)
	{
		player.ChangeHealth(-20);
		std::cout << "Your group is starving! You lost 20 health\n";
	}
	else if (player.GetFood() <= 20)
	{
		player.ChangeHealth(-10);
		std::cout << "Famine! You lost 10 health\n";

	}

	//Update: apply health damage if food runs out
	if (player.GetWater() == 0)
	{
		player.ChangeHealth(-25);
		std::cout << "Your group is dehydrated! You lost 25 health\n";
	}
	else if (player.GetWater() <= 20)
	{
		player.ChangeHealth(-10);
		std::cout << "Warning! Your group is facing dehydration. You lost 10 health\n";

	}

	//Display updated health 
	std::cout << "\nCurrent health: " << player.GetHealth() << "\n\n";

	//Checks for defeat BEFORE moving to location
	if (player.GetHealth() <= 0)
	{
		DisplayHeader("GAME OVER");
		std::cout << "YOU LOST! God is still with you but you have no health.\n";
		std::cout << "Put your trust in God and play again. He has given you what you need.\n";


		journeyActive = false;
		return;
	}

	currentLocation = locations[currentIndex + 1];

	std::cout << "You have arrived at " << currentLocation.GetName() << "\n";
	std::cout << "Day: " << currentDay << "\n";
	std::cout << currentLocation.GetDescription() << "\n";

	//Players wins when reaching Egypt
	if (currentLocation.GetName() == "Egypt")
	{
		DisplayHeader("JOURNEY COMPLETE");

		std::cout << "Your group has reached Egypt!\n";
		std::cout << "Your journey through Genesis is complete\n";
		std::cout << "\nYOU WIN!\n";

		journeyActive = false;
		return;
	}

	if (currentLocation.GetName() == "Noah's Ark")
	{
		event.SetEvent(
			"Preparing for the flood",
			"Your group hears news of the flood."
			"You must decide how to prepare!"
		);
	}
	else if (currentLocation.GetName() == "Tower of Babel")
	{
		event.SetEvent(
			"The Tower of Babel",
			"Your group encounters people building a tower."
			"You must decide how to use your resources."
		);
	}
	else if (currentLocation.GetName() == "Abraham's Journey")
	{
		event.SetEvent(
			"Abrahma's Journey",
			"Your group has traveled for several days."
			"Your supplies are getting low."
		);
	}
	else
	{
		return;
	}

	//Start the event 
	event.StartEvent(player, currentLocation);

	//Check for defeat after the event 
	if (player.GetHealth() <= 0)
	{

		DisplayHeader("GAME OVER");
		std::cout << "Your journey has come to an end.\n";

		journeyActive = false;
		return;
	}

}

void Traveler::DisplayStats() 
{
	std::cout << "\n";
	DisplayDivider();
	DisplayHeader("PLAYER STATS");
	player.DisplayStats();

	
}

void Traveler::DisplayLocation() 
{
	std::cout << "\n";
	DisplayDivider();
	DisplayHeader(currentLocation.GetName());
	std::cout << currentLocation.GetDescription();

}

void Traveler::DisplayInventory() 
{
	inventory.DisplayInventory();
}

//==================================================
//    USE INVENTORY ITEM
// 
// Allows the player to consume resources 
// 
// Sack of bread: +10 food 
// Water container: +10 water
// Aloe for healing: +20 health, maximum 100
//==================================================
void Traveler::UseInventoryItem() 
{
	int selection = 0;

	DisplayHeader("USE INVENTORY ITEM");

	std::cout << "Choose an item to use:\n\n";
	std::cout << "1. Sack of bread(Restore 10 food)\n";
	std::cout << "2. Water Container(Restore 10 water)\n";	
	std::cout << "3. Aloe for healing (Restore 20 health)\n";
	std::cout << "4. Cancel\n\n";

	if (!GetMenuSelection("Enter your selection: ", 1, 4, selection))
	{
		return;
	}

	//Cancel item usage
	if (selection == 4)
	{
		std::cout << "Item usage cancelled.\n";
		return;
	}

	//Sack of bread 
	if (selection == 1)
	{
		if (!inventory.HasItem("Sack of bread"))
		{
			std::cout << "You have no sacks of bread.\n";
			return;
		}

		if (player.GetFood() >= 60)
		{
			std::cout << "Your group is already completely full! You decide not to waste the flood.\n";
			return;
		}

		player.ChangeFood(10);
		inventory.RemoveItem("Sack of bread", 1);
		std::cout << "You consumed a Sack of bread. Food restored!";
	
	}
	else if (selection == 2)
	{ 
		//Water container 
		if (!inventory.HasItem("Water container"))
		{
			std::cout << "You dont have any water containers.\n";
			return;
		}

		if (player.GetWater() >= 60)
		{
			std::cout << "Your group is already fully hydrated! Your water container is full\n";
			return;
		}
		
		player.ChangeWater(10);
		inventory.RemoveItem("Water Container", 1);
		std::cout << "You hydrated! Water restored!\n";
	
	}
	else if (selection == 3)
	{
		//Aloe for healing 
		if (!inventory.HasItem("Aloe for healing"))
		{
			std::cout << "You do not have any aloe for healing.\n";
			return;
		}

		if (player.GetHealth() >= 100)
		{
			std::cout << "You do not have any aloe for healing.\n";
			return;

		}

		//Avoids using healing items at full health
		if (player.GetHealth() >= 100)
		{
			std::cout << "Your health is already at its max.\n";
			return;
		}

		player.ChangeHealth(20);
		inventory.RemoveItem("Aloe for healing", 1);
		std::cout << "you used the Aloe. Health restored!\n";

		//Display updated stats 
		std::cout << "\nUpdated Resources\n";
		std::cout << "Health: " << player.GetHealth() << "\n";
		std::cout << "Food: " << player.GetFood() << "\n";
		std::cout << "Water: " << player.GetWater() << "\n";
		std::cout << "Supplies: " << player.GetSupplies() << "\n";
		std::cout << "Morale: " << player.GetMorale() << "\n";

		//Check defeat conditions after item usage
		if (player.GetHealth() <= 0 ||
			player.GetFood() <= 0 ||
			player.GetWater() <= 0)
		{
			DisplayHeader("GAME OVER");
			std::cout << "Your journey has come to an end\n";

			journeyActive = false;

		}
	}

	
}


//==================================================
//    MAKE A LOCATION SELECTION
// 
// Allows the player to continue traveling,
// explore the location or encourage the group
//==================================================
void Traveler::MakeLocationSelection() 
{
	int selection = 0;

	std::cout << "\n";
	DisplayDivider();
	DisplayHeader(currentLocation.GetName());

	std::cout << currentLocation.GetDescription() << "\n\n";
	std::cout << "What would you like to do?\n";
	std::cout << "1. Continue the journey\n";
	std::cout << "2. Explore the location\n";
	std::cout << "3. Encourage the group\n";

	if (!GetMenuSelection("Enter your selection: ", 1, 3, selection))
	{
		return;
	}

	//Players Choice 
	if (selection == 1)
	{
		TravelNext();
	}
	else if (selection == 2)
	{
		if (player.GetSupplies() < 5)
		{
		 //If user has less than 5 supplies this will prevent them from exploring
		 std::cout << "Your dont have enough supplies to explore.\n";
		 return;
		}
		//If they explore result is 5 supplies consumed
		player.ChangeSupplies(-5);

		std::cout << "Your group explored the surrounding area.\n";
		std::cout << "You used 5 supplies.\n";

		//Reward exploration
		int reward = (currentDay % 3) + 1;

		if (reward == 1)
		{
			player.ChangeFood(10);
			std::cout << "You discovered food! Food increased by 10!\n";
		}
		else if (reward == 2)
		{
			player.ChangeWater(10);
			std::cout << "You found fresh water! Water increased by10!";
				
		}
		else
		{
			player.ChangeMorale(10);
			std::cout << "Your group found encouragement! Morale increased by 10!\n";
		}
	}
	else if (selection == 3)
	{
		int moraleBefore = player.GetMorale();

		player.ChangeMorale(5);

		if (player.GetMorale() == moraleBefore)
		{
			std::cout << "Your groups morale is already at the max\n";
		}
		else
		{
			std::cout << "You encouraged your travelers\n";
			std::cout << "Morale increased by 5!\n";
		}	
	}

	//Display updated resources 
	DisplayHeader("UPDATED RESOURCES");
	std::cout << "Health: " << player.GetHealth() << "\n";
	std::cout << "Food: " << player.GetFood() << "\n";
	std::cout << "Water: " << player.GetWater() << "\n";
	std::cout << "Supplies: " << player.GetSupplies() << "\n";
	std::cout << "Morale: " << player.GetMorale() << "\n";

}

//==================================================
//       END JOURNEY
// 
//Asks the player to confirm whether the current
// journey should end
//==================================================
void Traveler::EndJourney()
{
	std::string input;

	std::cout << "Are you sure you want to end your journey?(YES/NO): ";

	std::getline(std::cin, input);

	if (input == "y" || input == "Y" || input == "YES" || input == "yes")
	{
		journeyActive = false;

		std::cout << "You ended your journey.\n";
	}
	else
	{
		std::cout << "Your journey will continue.";
	}

}

//==================================================
// RESET JOURNEY
// 
// Restores the starting location, day counter, 
// player stats and inventory for a new journey
//==================================================
void Traveler::ResetJourney() 
{
	currentDay = 1;
	journeyActive = false;

	//reset the starting locaiton 
	currentLocation = locations.front();

	player.ResetStats();

	inventory.ResetInventory();

}

//==================================================
//  LOAD JOURNEY 
// 
// Checks for valid saved data
// Searched locations for saved name
// Restores teh location/day when match found 
// returns false if saved location doesnt exist
//==================================================
bool Traveler::LoadJourney(int savedDay, const std::string&
	savedLocation) 
{

	//==================================================
	//  VALIDATE SVED DAY
	//==================================================
	if (savedDay < 1)
	{
		return false;
	}

	//==================================================
	//  FIND SAVED LOCATION
	//==================================================
	for (const Location& location : locations)
	{
		if (location.GetName() == savedLocation)
		{
			currentLocation = location;
			currentDay = savedDay;
			journeyActive = false;

			return true;
		}
	}

	//==================================================
	//  SAVED LOCATION WAS NOT FOUND
	//==================================================
	return false;
}


//==================================================
// GET MENU SELECTION 
// 
// Validates menu input and returns whether the
// selecton falls within specified range
//==================================================
bool Traveler::GetMenuSelection(const std::string& prompt, 
	int minSelection,
	int maxSelection, 
	int& selection) 
{
	std::string input;

	//Display prompt and read users input
	std::cout << prompt;

	if (!std::getline(std::cin, input))
	{
		journeyActive = false;
		return false;
	}

	//Dont allow blank entries
	if (input.empty())
	{
		std::cout << "Input cant be blank. Please try again.\n";
		return false;
	}

	//Only allow one digit 
	if (input.size() != 1 ||
		input[0] < '0' ||
		input[0] > '9')
	{
		std::cout << "Invalid input. Enter a single number from the menu.\n";
		return false;
	}

	//Convert value to int
	selection = input[0] - '0';

	//Make sure selection is within range
	if (selection < minSelection || selection > maxSelection)
	{
		std::cout << "Invalid selection. Select " << minSelection << " to "
			<< maxSelection << ".\n";
		return false;
	}
	//When input is valid
	return true;
}


//==================================================
//  GETS THE CURRENT JOURNEY DAY
//  GETS THE CURRENT LOCATION
//  GETS THE CURRENT INVENTORY
// 
// 	Allows other function to read journey info
// 	without accessing private vars
//==================================================
int Traveler::GetCurrentDay() const { return currentDay; }
std::string Traveler::GetCurrentLocation() const { return currentLocation.GetName(); }
const Inventory& Traveler::GetInventory() const { return inventory; }

//==================================================
//  LOAD SAVED INVENTORY
// 
// Restores inventory from a saved game
//==================================================
void Traveler::LoadSavedInventory(const std::vector<std::string>&
	savedNames, const std::vector<int>& savedQuantities) 
{
	inventory.LoadInventory(savedNames, savedQuantities);
}

//==================================================
//   SAVE CALL BACK
//
// This stores the func the Traveler will call 
// when the player chooses to save 
//==================================================
void Traveler::SetSaveCallback(std::function<void()>  callback) 
{
	saveCallBack = callback;
}