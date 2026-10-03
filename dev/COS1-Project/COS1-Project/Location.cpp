#include "Location.h"
#include<iostream>
#include "GameUI.h"


/*
 Default constructor
   - this gets created without providing a name or description
*/
Location::Location()
{
	name = "Unknown";
	description = "You have not reached a known location.";

}

/*
 Location constructor
   - creates a location and immediately gives it a name/description
*/
Location::Location(const std::string& locationName, const std::string& locationDescription) 
{
	name = locationName;
	description = locationDescription;
}

// Returns location name
std::string Location::GetName() const 
{
	return name;
}

//Returns Description 
std::string Location::GetDescription() const
{
	return description;
}


//Display Location 
void Location::DisplayLocation() const 
{
	std::cout << "\n";
	std::cout << "=====================================================================";
	std::cout << "          " << name << std::endl;
	std::cout << "=====================================================================";

	std::cout << description << std::endl;

	std::cout << "=====================================================================";

}
