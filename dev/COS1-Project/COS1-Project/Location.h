#pragma once
#include<string>

/*
 The Location class will be a representation of a place from the Book of
 Genesis

  - This class is very simple, it will store the name and description
  - Displays information about the location
*/
class Location 
{
private:
	std::string name; //name of location
	std::string description; //name of description

public:
	//Default Constructor
	Location();

	//Location constructor gives specific name/description
	Location(const std::string& locationName, const std::string& locationDescription);

	//Getters
	std::string GetName() const;
	std::string GetDescription() const;

	//Displays location information
	void DisplayLocation() const;

};
