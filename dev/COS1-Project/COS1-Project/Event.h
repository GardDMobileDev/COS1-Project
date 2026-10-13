#pragma once
#include<string>
#include "Player.h"
#include "Location.h"
//==================================================
//   EVENT.H 
// 
// This declares the event description, choices
// and event methods
//==================================================
class Event 
{
private:
	std::string eventName;
	std::string eventDescription;

public:

	//Event Constructor 
	Event();

	//Set Event Information 
	void SetEvent(const std::string&name, const std::string& description);

	//Display Event Information 
	void DisplayEvent() const;

	//Display choices and apply consequences 
	void StartEvent(Player& player, const Location& location);
};