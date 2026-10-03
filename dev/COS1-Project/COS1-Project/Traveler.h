#pragma once
#include <string>
#include <vector>

/*
 This class will keeps track of all the travelers with the player.
   - The vector will store travelers : can be increased or reduced
   - Methods : addTraveler, Display and getTravelerSize 
*/

class Traveler
{
private:
	//Vector : store travelers 
	std::vector<std::string> travelers;

public: 
	//Constructor creates staring traveling group
	Traveler();

	//Method to add a traveler 
	void AddTraveler(const std::string& travelerName);

	//Method to Diplay current travelers
	void DisplayTravelers() const;

	// Returns the number of travelers in the group
	int GetTravelerSize() const;

};