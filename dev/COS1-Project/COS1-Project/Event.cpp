#include <limits>
#include<iostream>
#include<string>
#include "Event.h"
#include "GameUI.h"

//==================================================
//   EVENT.CPP 
// 
// implements event prompts, input validation and
// consequences
// 
// Event: handles the encounter
// Player: handles player stats
//==================================================

Event::Event() : eventName("GENESIS EVENT"), eventDescription("Your group faces a challenge")
{

}

//Updates the event name and description
void Event::SetEvent(const std::string& name, const std::string& description) 
{
	eventName = name;
	eventDescription = description;

}

// Displays the event name and description
void Event::DisplayEvent() const 
{
	DisplayDivider();
	std::cout << "EVENT: " << eventName << "\n";
	DisplayDivider();
	std::cout << eventDescription << "\n";

}

// Displays choices, validates input, and applies the consequences of the players selection
void Event::StartEvent(Player& player, const Location& location) 
{
	int selection = 0;
	std::string input;

	DisplayEvent();

	std::cout << "\nLocation: " << location.GetName() << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Rest and recover(restore 10 health)" << std::endl;
	std::cout << "2. Search for supplies(costs 5 supplies)" << std::endl;
	std::cout << "3. Continue traveling(lose 5 health, gain 5 morale)" << std::endl;

	while (true)
	{
		std::cout << "\nEnter your choice: ";

		if (!std::getline(std::cin, input))
		{
			std::cout << "Input ended. Event cancelled." << std::endl;
			return;

		}
		

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
          //Restores health but consumes food/water
		player.ChangeHealth(10);
		player.ChangeFood(-10);
		player.ChangeWater(-10);

		std::cout << "\nYour group rested and recovered 10 health\n";
		std::cout << "Food and water each decreased by 10\n";
		break;

	case 2: 
		 //Search gains supplies but costs food/health 
		player.ChangeSupplies(10);
		player.ChangeFood(-5);
		player.ChangeHealth(-5);

		std::cout << "Your group found 10 supplies!\n";
		std::cout << "Searching cost 5 food and 5 health.\n";
		break;

	case 3: 
		
		//Continuing travel with addtional resources losses
		player.ChangeHealth(-15);
		player.ChangeFood(-5);
		player.ChangeWater(-5);

		std::cout << "\nYour group has continued through harsh conditions.\n";
		std::cout << "\nFood and water both decreased by 5.\n";
		break;

	default:
		std::cout << "Invalid seleciton. Try again.\n";
		break;
	}


//=================================================
//   DISPLAY THE PLAYERS UPDATED RESOURCES
//=================================================
DisplayDivider();
std::cout << "             CURRENT RESOURCES\n";
DisplayDivider();


std::cout << "Health:     " << player.GetHealth() << "\n";
std::cout << "Food:       " << player.GetFood() << "\n";
std::cout << "Water:      " << player.GetWater() << "\n";
std::cout << "Supplies:   " << player.GetSupplies() << "\n";
std::cout << "Morale:   " << player.GetMorale() << "\n";


}