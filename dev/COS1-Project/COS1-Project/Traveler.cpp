#include "Traveler.h"
#include <iostream>
#include "GameUI.h"
#include <string>


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

		std::cout << "\n";
		DisplayDivider();
		DisplayHeader("YOUR JOURNEY");
		DisplayDivider();

		//==================================================
		//      YOUR JOURNEY MENU 
		//==================================================
		std::cout << "Day: " << currentDay << "\n";
		std::cout << "Location: " << currentLocation.GetName() << "\n";

		std::cout << "1. Travel to Next Location\n";
		std::cout << "2. View Player Stats\n";
		std::cout << "2. View Current Location\n";
		std::cout << "2. Make A Location Selection\n";
		std::cout << "2. End Journey \n";
		std::cout << "2. \nEnter your selection";

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

	std::cout << "\nYou travel for one day.\n";

	//Advance the day 
	++currentDay;

	//Consume resources : food and water 
	


}