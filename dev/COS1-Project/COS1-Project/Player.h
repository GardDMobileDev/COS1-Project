#pragma once
#include<string>
//==================================================
//   PLAYER CLASS
//
//   Stores the player's name, health, resources, and
//   morale throughout the Bible Trail journey.
//==================================================
class Player 
{
private:
	//==================================================
	//   PLAYER INFORMATION
	//
	//  Stores the players name and current stats
	//==================================================
	std::string name;

	int health;
	int food; 
	int water;
	int supplies;
	int morale;

	//==================================================
	//   PLAYER CONSTRUCTOR 
	//
	//  initializes the players starting information and 
	// stats
	//==================================================
	public:
		Player();

	//==================================================
	//   GETS PLAYER NAME
	//
	//   Returns the players name without modifying it 
	//==================================================
	std::string GetName() const;

	//==================================================
	//   GETS PLAYER 
	//   HEALTH, FOOD, WATER, SUPPLIES, MORALE

	//   Returns the players current health, food
	//   water, supplies and moral
	//==================================================
		
	int GetHealth()const;
	int GetFood() const;
	int GetWater() const;
	int GetSupplies() const;
	int GetMorale() const;

	//==================================================
	//   SETS PLAYER NAME 
	//
	//  Updates players name
	//==================================================
	void SetName(const std::string& playerName);

	//==================================================
	//   CHANGES PLAYERS
	//   HEALTH, FOOD, WATER, SUPPLIES AND MORALE
	//
	//   Adjusts by given amount  
	//==================================================
	void ChangeHealth(int consumption);
	void ChangeFood(int consumption);
	void ChangeWater(int consumption);
	void ChangeSupplies(int consumption);
	void ChangeMorale(int consumption);

	//==================================================
	//  DISPLAYS STATS
	//
	//   Displays the players current stats
	//==================================================
	void DisplayStats() const;
    
	//==================================================
	//  RESETS PLAYER STATS
	//
	//   Restores the players stats to their 
	//   starting values
	//==================================================	
   void ResetStats();

};