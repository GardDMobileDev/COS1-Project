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

//==================================================
//  LOCATION NAME/DESCRIPTION
//
// Store current name/location
//==================================================
	std::string name; //name of location
	std::string description; //name of description

public:
//==================================================
//  DEFAULT CONSTRUCTOR 
//
// Initalizes a location with default values 
//==================================================
	Location();

//==================================================
//  LOCATION CONSTRUCTOR 
//
// Initializes a lcoation with a specified name
// and description
//==================================================
	Location(const std::string& locationName, const std::string& locationDescription);

//==================================================
//  GETTERS
// 	NAME, DESCRIPTION 
//
// Returns name/description
//==================================================
	std::string GetName() const;
	std::string GetDescription() const;

//==================================================
//  DISPLAYS LOCATION
//
// Displays the location name/description
//==================================================
	void DisplayLocation() const;

};
