#include "Location.h"
#include<iostream>
#include "GameUI.h"

//==================================================
//   DEFAULT LOCATION CONSTRUCTOR
//
//   Initializes a location with a default name
//   and description.
//==================================================
Location::Location()
{
	name = "Unknown";
	description = "You have not reached a known location.";

}

//  Initializes a location with a specified name and description
Location::Location(const std::string& locationName, const std::string& locationDescription) : name(locationName),
	description (locationDescription){}

std::string Location::GetName() const 
{
	return name;
}

std::string Location::GetDescription() const
{
	return description;
}

// Displays the locations name and description with visual dividers 
void Location::DisplayLocation() const 
{
	std::cout << "\n";
	DisplayDivider();
	std::cout << "\n" << name << "\n";
	DisplayDivider();

	std::cout << description << "\n";

}
