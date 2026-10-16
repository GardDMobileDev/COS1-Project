#include "Traveler.h"
#include "GameUI.h"
#include <iostream>
#include <string>

//==================================================
//   TRAVELER CONSTRUCTOR 
// 
// Initializes the player and location references, 
// Genesis locations, inventoru, and journey state
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
     //Set the starting location if it is uknown
	if (currentLocation.GetName() == "God is creating the Heavens and Earth. You are at the beginning.")
	{
		currentLocation = locations.front();
	}

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
        std::cout << "7. End Journey \n";

		if (!GetMenuSelection("\nEnter your selection: ", 1,7, selection))
		{
			if (!journeyActive)
			{
				break;
			}

			continue;
		}

		switch (selection)
		{

		case 1:TravelNext(); break;
        case 2:DisplayStats();break;
        case 3:DisplayLocation();break;
		case 4:MakeLocationSelection();break;
        case 5:DisplayInventory();break;
        case 6:UseInventoryItem();break;
		case 7:EndJourney();break;
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
		std::cout << "Unable to location current location";
		return;
	}

	//Check if final location was reached 
	if (currentIndex == static_cast<int>(locations.size()) - 1)
	{
		DisplayHeader("JOURNEY COMPLETE");

		std::cout << "Your party has reached Egypt!\n";
		std::cout << "Your journey through Genesis is complete\n";
		std::cout << "\nYOU WIN!\n";

		journeyActive = false;
		return;
	}

	++currentDay;

	player.ChangeFood(-5);
	player.ChangeWater(-5);

	std::cout << "You traveled for one day.\n";

	currentLocation = locations[currentIndex + 1];

	std::cout << "You have arrived at " << currentLocation.GetName() << "\n";
	std::cout << "Day: " << currentDay << "\n";
	std::cout << currentLocation.GetDescription() << "\n";

	
	//Checks whether journey can continue
	if (player.GetHealth() <= 0 ||
		player.GetFood() <= 0 ||
		player.GetWater() <= 0)
	{
		DisplayHeader("GAME OVER");
		std::cout << "Your journey has come to an end.\n";
		journeyActive = false;
		return;
	}

//==================================================
// SET LOCATION EVENT 
//
// Selects an event based on current location
//==================================================

	if (currentLocation.GetName() == "Noah's Ark")
	{
		event.SetEvent("Preparing for the flood ", "Your group hears news of the flood" 
			" You must decide how to prepare!");
	}
	else if (currentLocation.GetName() == "Tower of Babel")
	{
		event.SetEvent("The Tower of Babel ", "Your group encounters people building a tower " 
			" You must decide how to use your resources");

	}
	else if (currentLocation.GetName() == "Abraham's Journey")
	{
		event.SetEvent("Abrahams Journey ", "Your group has traveled for several days " 
			" Your supplies are getting low");
	}
	else if (currentLocation.GetName() == "Egypt")
	{
		event.SetEvent("Arrival in Egypt ", "Your group has reached Egpty, your group "
		" is suffering from famine.");
	}
	else
	{
		return;
	}

	event.StartEvent(player, currentLocation);

	//Check whether the event caused the journey to end
	if (player.GetHealth() <= 0 ||
		player.GetFood() <= 0 ||
		player.GetWater() <= 0)
	{
		DisplayHeader("GAME OVER");
		std::cout << "Your journey has come to an end.\n";
		journeyActive = false;
		return;
	}
}


//==================================================
// DISPLAYS THE PLAYERS STATS
//
// Displays the players current stats
//==================================================
void Traveler::DisplayStats() 
{
	std::cout << "\n";
	DisplayDivider();
	DisplayHeader("PLAYER STATS");

	//Get name from player object
	std::cout << "Traveler Name: " << player.GetName() << "\n";
	player.DisplayStats();

	
}

//==================================================
//    DISPLAY CURRENT LOCATION 
// 
//  Displays the current locations name and 
// description
//==================================================
void Traveler::DisplayLocation() 
{
	std::cout << "\n";
	DisplayDivider();
	DisplayHeader(currentLocation.GetName());
	std::cout << currentLocation.GetDescription();

}

//==================================================
//    DISPLAY INVENTORY
// 
// Displays the available inventory items
// and their quantities
//==================================================
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

		//Remove item ONLY after confirming availability 
		inventory.RemoveItem("Sack of bread", 1);

		player.ChangeFood(10);
		std::cout << "You used a sack of bread.\n";
		std::cout << "Food increased by 10.\n";

	}
	else if (selection == 2)
	{ 
		//Water container 
		if (!inventory.HasItem("Water container"))
		{
			std::cout << "You dont have any water containers.\n";
			return;
		}

		inventory.RemoveItem("Water container", 1);
		player.ChangeWater(10);

		std::cout << "You used water container\n";
		std::cout << "Water increased by 10\n";
	
	}
	else if (selection == 3)
	{
		//Aloe for healing 
		if (!inventory.HasItem("Aloe for healing"))
		{
			std::cout << "You do not have any aloe for healing.\n";
			return;

		}

		//Avoid consuming healing items at full health
		if (player.GetHealth() >= 100)
		{
			std::cout << "Your health is already at it's max.\n";
			std::cout << "Save your aloe for when you need it.\n";
			return;
		}

		inventory.RemoveItem("Aloe for healing", 1);
		player.ChangeHealth(20);

		std::cout << "You used aloe for healing\n";
		std::cout << "Health increased by 20, up to a maximum of 100.\n";

	}

	//Display updated stats 
	std::cout << "\nUpdated Resources\n";
	std::cout << "Health: " << player.GetHealth() << "\n";
	std::cout << "Food: " << player.GetFood() << "\n";
	std::cout << "Water: " << player.GetWater() << "\n";

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
		std::cout << "Your group will continue to travel\n";
	}
	else if (selection == 2)
	{
		//If they explore result is 5 supplies consumed
		player.ChangeSupplies(-5);

		std::cout << "Your group explored the surrounding area.\n";
		std::cout << "You used 5 supplies.\n";
	}
	else if (selection == 3)
	{
		//Encourage group increases morale
		player.ChangeMorale(5);

		std::cout << "You encouraged your travlers.\n";
		std::cout << "Morale increased by 5!\n";
	}

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

	if (input == "y" || input == "Y")
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
		std::cout << "Invalid selection. Select " << minSelection
			<< maxSelection << ".\n";
		return false;
	}
	//When input is valid
	return true;
}
