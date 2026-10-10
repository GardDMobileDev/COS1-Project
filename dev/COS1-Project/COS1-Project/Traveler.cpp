#include "Traveler.h"
#include "Player.h"
#include <iostream>
#include "GameUI.h"
#include <string>
#include <vector>
#include <limits>


/*
 This will show what to do with the information from Traveler.h
  - holds the travelers that will be from the book of Genesis
*/

/*
Constructor
  Adam: first human created to tend to Gods Creation
  Noah: Chose to preserve human/animal life during the flood because of his faith
  Abraham: father of a great nation: Called by God because of his faith and God would
  allow his generations to inherit land and be blessed through him
*/


//==================================================
// WEEK 2 UPDATES:
// Added continuous journey menu 
// Added Day Counter 
// Added Travel between locations 
// Added food and water consumption
// Added location selections 
// Updated required getline/try/catch
//==================================================
Traveler::Traveler(Player& player, Location& currentLocation) :
	player(player), currentLocation(currentLocation), currentDay(1), 
	journeyActive(false)
{

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
		std::cout << "4. Make A Location Selection\n";
		std::cout << "5. End Journey \n";
		std::cout << "\nEnter your selection: ";

		std::getline(std::cin, input);

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

			if (selection < 1 || selection > 5)
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
	//Locations from previous vector : Name/Description 
	static const std::vector<Location> locations =
	{
		Location("Garden of Eden", "Adam and Eve were placed to attend the Garden."),
		Location("Noah's Ark", "Noah builds the Ark for the flood."),
		Location("Tower of Babel", "Tower of Babel built to reach the Heavens."),
		Location("Abraham's Journey", "Abraham leaves his home on God's command."),
		Location("Egypt", "Joseph's story begins.")

	};

	//Find current location 
	int currentIndex = 0;

	for (int i = 0; i < locations.size(); i++)
	{ 
		if (locations[i].GetName() == currentLocation.GetName())
		{
			currentIndex = static_cast<int>(i);
			break;
		}

	}

	//This Locatfion completes journey 
	if (currentIndex == static_cast<int>(locations.size() -1))
	{
		std::cout << "\nYou reached the final location: Egypt.\n";
		std::cout << "\nYour Journey is complete!\n";

		journeyActive = false;
		return;

	}

	//Advance the day 
	++currentDay;

	//Consume resources : food and water 
	std::cout << "\nYou traveled for one day.\n";
    
	player.ChangeFood(-5);
	player.ChangeWater(-5);

	//Move to next location 
	currentLocation = locations[currentIndex + 1];

	std::cout << "You have arrive at " << currentLocation.GetName() << "\n";
	std::cout << "Day: " << currentDay << "\n";
	std::cout << currentLocation.GetDescription() << "\n";

}


//==================================================
//    DISPLAY PLAYER STATS
//==================================================
void Traveler::DisplayStats() 
{
	std::cout << "\n";
	DisplayDivider();
	DisplayHeader("PLAYER STATS");
	DisplayDivider();

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
	DisplayDivider();

	std::cout << currentLocation.GetDescription();

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
	DisplayDivider();

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
// This allows user to confirm if they are ending
// the journey
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
