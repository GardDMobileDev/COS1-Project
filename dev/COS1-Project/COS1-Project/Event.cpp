#include <limits>
#include<iostream>
#include<string>
#include "Event.h"

//==================================================
//   EVENT.CPP 
// 
// implements event prompts, input validation and
// consequences
// 
// Event: handles the encounter
// Player: handles player stats
//==================================================


//==================================================
//   EVENT CONSTRUCTOR 
// 
// Initializes the event default information
//==================================================
Event::Event() : eventName("GENESIS EVENT"), eventDescription("Your group faces a challenge")
{

}

//==================================================
//   SET EVENT INFORMATION
// 
// updates the event name and description
//==================================================
void Event::SetEvent(const std::string& name, const std::string& description) 
{
	eventName = name;
	eventDescription = description;

}


//==================================================
//   DISPLAY EVENT
// 
// Displays the event name and description
//==================================================
void Event::DisplayEvent() const 
{
	std::cout << "\n===============================================\n";
	std::cout << "EVENT: " << eventName << "\n";
	std::cout << "=================================================\n";
	std::cout << eventDescription << "\n";

}

//==================================================
//   START EVENT
// 
// Displays choices, validates input, and applies
// the consequences of the players selection
//==================================================
void Event::StartEvent(Player& player, const Location& location) 
{
	int selection = 0;
	std::string input;

	//Display the current event and location
	DisplayEvent();

	std::cout << "\nLocation: " << location.GetName() << std::endl;

	//Display the available player choices 
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Rest and recover" << std::endl;
	std::cout << "2. Search for supplies" << std::endl;
	std::cout << "3. Continue traveling" << std::endl;

	//Validate the players input 
	while (true)
	{
		std::cout << "\nEnter your choice: ";
		std::getline(std::cin, input);

		try
		{
			//Deny blank input 
			if (input.empty())
			{
				std::cout << "Input cant be blank. Try again.\n";
				continue;
			}
		 
			//Convert input to an int
			selection = std::stoi(input);

			//Validate the selection
			if (selection < 1 || selection > 3)
			{
				std::cout << "Invalid selection. Select 1, 2, or 3.\n";
				continue;
			}

			//Valid selection then exit loop
			break;

		}
		catch (const std::invalid_argument&)
		{
			//Hanld input thats not a number 
			std::cout << "Invalid input. You must enter a number\n";
		}
		catch (const std::out_of_range&) 
		{
		  //Handle large numbers 
			std::cout << "Number is too large. Try again\n";
		}

	}

	//Apply the consequences of the selection
	//Easier to read using switch
	//Uses the Change instead of directly modifying member vars in player
	switch (selection)
	{
	case 1: 
		//Resting restores the groups health 
		player.ChangeHealth(10);
		std::cout << "\nYour group rested. Health increased by 10\n";
		break;

	case 2: 
		//If the group searches the supplies will increase 
		player.ChangeSupplies(10);

		std::cout << "\nYour group found supplies. Supplies increased by 10\n";
		break;

	case 3: 
		//Traveling consumes food and water 
		player.ChangeFood(-5);
		player.ChangeWater(-5);

		std::cout << "\nYour group continues traveling\n";
		std::cout << "Food and water each decreased by 5\n";
		break;

	default:
		std::cout << "Invalid seleciton. Try again.\n";
		break;
	}


//==================================================
//   DISPLAY THE PLAYERS UPDATED RESOURCES
//==================================================
std::cout << "\n===========================================\n";
std::cout << "             CURRENT RESOURCES\n";
std::cout << "\n===========================================\n";


std::cout << "Health:     " << player.GetHealth() << "\n";
std::cout << "Food:       " << player.GetFood() << "\n";
std::cout << "Water:      " << player.GetWater() << "\n";
std::cout << "Supplies:   " << player.GetSupplies() << "\n";

}