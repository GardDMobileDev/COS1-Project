#pragma once
#include<string>

//==================================================
//  LOCATION CLASS
//
//  Represents a location from the Book of Genesis
// and stores its name and description
//==================================================
class Location 
{
private:
	std::string name; //name of location
	std::string description; //name of description

public:
	Location();

	Location(const std::string& locationName, const std::string& locationDescription);

	std::string GetName() const;
	std::string GetDescription() const;

	void DisplayLocation() const;

};
