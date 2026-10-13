#include "Traveler.h"
#include "Player.h"
#include "Location.h"
#include "Inventory.h"
#include <iostream>
#include "GameUI.h"
#include <string>
#include <vector>
#include <limits>
#include <cctype>

//==================================================
//   TRAVELER CONSTRUCTOR 
// 
// Connects Player, Locatoin and Inventory
// Initialized the Bible Trail Journey
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
//          START JOURNEY 
// Will run until player ends game
//==================================================
void Traveler::StartJourney()
{
	journeyActive = true;

	while (journeyActive)
	{
		std::string input;
		int selection = 0;

		DisplayDivider();
		DisplayHeader("YOUR JOURNEY");
		DisplayDivider();

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
		std::cout << "\nEnter your selection: ";

		if (!std::getline(std::cin, input))
		{
			journeyActive = false;
			break;
		}


		try
		{
			//Handle blank input 
			if (input.empty())
			{
				std::cout << "Cannot be blank. Please try again.\n";
				continue;
			}

			//Convert to integer
			selection = std::stoi(input);

			if (selection < 1 || selection > 7)
			{
				std::cout << "Please select a number from the menu.\n";
				continue;
			}
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "Invalid input. Please enter a number.\n";
			continue;
		}
		catch (const std::out_of_range&)
		{
			std::cout << "Number is too large. Try again..\n";
			continue;
		}

		//Selections 
		if (selection == 1)
		{
			TravelNext();
		}
		else if (selection == 2)
		{
			DisplayStats();
		}
		else if (selection == 3)
		{
			DisplayLocation();
		}
		else if (selection == 4)
		{
			MakeLocationSelection();
		}
		else if (selection == 5)
		{
			DisplayInventory();
		}
		else if (selection == 6)
		{
			UseInventoryItem();
		}
		else if (selection == 7)
		{
			EndJourney();
		}

	}
}


//==================================================
//      TRAVEL TO NEXT LOCATION
// 
// Traveling takes 1 Day
// Resources will decrease by 5
//==================================================
void Traveler::TravelNext() 
{

	//Find the current location
	int currentIndex = 0;

	for (int i = 0; i < locations.size(); ++i)
	{
		if (locations[i].GetName() == currentLocation.GetName())
		{
			currentIndex = i;
			break;
		}
	}

	//Check if final location was reached 
	if (currentIndex == static_cast<int>(locations.size()) - 1)
	{
		DisplayHeader("JOURNEY COMPLETE");

		std::cout << "Your party has reached Egypt!\n";
		std::cout << "Your journey through Genesis is complete\n";
		std::cout << "\N YOU WIN!\n";

		journeyActive = false;
		return;
	}

	//Advvance the day 
	++currentDay;

	//Consume resources 
	player.ChangeFood(-5);
	player.ChangeWater(-5);

	std::cout << "You traveled for one day.\n";

	//Move to the next location
	currentLocation = locations[currentIndex + 1];

	std::cout << "You have arrived at " << currentLocation.GetName() << "\n";
	std::cout << "Day: " << currentDay << "\n";
	std::cout << currentLocation.GetDescription() << "\n";

	//WEEK 3 UPDATES
	
	//Checks for defeat 
	if (player.GetHealth() <= 0 ||
		player.GetFood() <= 0 ||
		player.GetWater() <= 0)
	{
		DisplayHeader("GAME OVER");
		std::cout << "Your journey has come to an end.\n";
		journeyActive = false;
		return;
	}

	//Set the event for the current location
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

	//This will start the event and apply player selection
	event.StartEvent(player, currentLocation);

	//Check for defeat 
	if (player.GetHealth() <= 0 ||
		player.GetFood() <= 0 ||
		player.GetWater())
	{
		DisplayHeader("GAME OVER");
		std::cout << "Your journey has come to an end.\n";
		journeyActive = false;
	}
}


//==================================================
//    DISPLAY PLAYER STATS
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
//==================================================
void Traveler::DisplayLocation() 
{
	std::cout << "\n";
	DisplayDivider();
	DisplayHeader(currentLocation.GetName());
	std::cout << currentLocation.GetDescription();

}

//==================================================
//    DISPLAY CURRENT LOCATION 
// Week 3 Update : Shows all items/quantities 
//==================================================
void Traveler::DisplayInventory() 
{
	inventory.DisplayInventory();
}

//==================================================
//    USE INVENTORY ITEM
// Week 3 Update
// Sack of bread: +10 food 
// Water container: +10 water
// Aloe for healing: +20 health, maximum 100
//==================================================
void Traveler::UseInventoryItem() 
{
	std::string input;
	int selection = 0;

	DisplayHeader("USE INVENTORY ITEM");

	std::cout << "Choose an item to use:\n\n";
	std::cout << "1. Sack of bread(Restore 10 food)\n";
	std::cout << "2. Water Container(Restore 10 water)\n";	
	std::cout << "3. Aloe for healing (Restore 20 health)\n";
	std::cout << "4. Cancel\n\n";

	std::cout << "Enter your selection: ";

	if (!std::getline(std::cin, input))
	{
		journeyActive = false;
		return;
	}

	try
	{
		if (input.empty())
		{
			std::cout << "Input cant be blank. Try again.\n";
			return;
		}

		
	}
	catch (const std::invalid_argument&)
	{
		std::cout << "Number too large.\n";
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
		if (inventory.HasItem("Aloe for healing"))
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
// Will add additional consequences in Week 3
//==================================================
void Traveler::MakeLocationSelection() 
{
	std::string input;
	int selection = 0;

	std::cout << "\n";
	DisplayDivider();
	DisplayHeader(currentLocation.GetName());

	std::cout << currentLocation.GetDescription() << "\n\n";
	std::cout << "What would you like to do?\n";
	std::cout << "1. Continue the journey\n";
	std::cout << "2. Explore the location\n";
	std::cout << "3. Encourage the group\n";
	std::cout << "4. Enter your selection: \n";

	std::getline(std::cin, input);

	try
	{
		if (input.empty())
		{
			std::cout << "Input cannont be blank.\n";
		}

		//Convert input string to int
		selection = std::stoi(input);

		if (selection < 1 || selection > 3)
		{
			std::cout << "Please enter 1, 2, or 3.\n";
			return;
		}

	}
	catch (const std::invalid_argument&)
	{
		std::cout << "Input is invalid. Please enter a number.";
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
// Week 2 Updates: input and getline
// Accepts Yes or y to end the journeys
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
// Resets the game state for a new journey.
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
