#include "Player.h"
#include <iostream>
#include "GameUI.h"
//==================================================
//   PLAYER CONSTRUCTOR
//
//  Initializes the players default name, health,
// food, water, supplies and morale
//==================================================
Player::Player()
{
	name = "Traveler"; //DEFAULT
	health = 100;
	food = 100;
	water = 100;
	supplies = 50;
	morale = 75;
}

//==================================================
//   SET PLAYER NAME
//
// Updates the players name
//==================================================
void Player::SetName(const std::string& playerName) 
{
	name = playerName;

}

//==================================================
//   GET PLAYERS
//   
//
// Updates current 
// NAME, HEALTH, FOOD,WATER, SUPPLIES AND MORALE
//==================================================
std::string Player::GetName() const { return name; }

int Player::GetHealth()const { return health; }

int Player::GetFood() const { return food;}

int Player::GetWater() const { return water; }

int Player::GetSupplies() const { return supplies; }

int Player::GetMorale() const { return morale; }


//==================================================
//   DISPLAYS PLAYER STATS
//
// Displays the players name and current stats
//==================================================
void Player::DisplayStats() const 
{	
	std::cout << "Traveler: " << name <<std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Food: " << food << std::endl;
	std::cout << "Water: " << water << std::endl;
	std::cout << "Supplies: " << supplies << std::endl;
	std::cout << "Morale: " << morale << std::endl;
}

//==================================================
//   CHANGE PLAYER HEALTH, FOOD AND WATER, MORALE 
//
// Adjusts health while keeping it between 0 && 100
//==================================================
void Player::ChangeHealth(int consumption)
{

	health += consumption;

	//Cant go below 0 
	if (health < 0)
	{
		health = 0;
	}
	else if (health > 100)
	{
		health = 100;
	}
}

void Player::ChangeFood(int consumption)
{
	food += consumption;

	//Cant go below 0 
	if (food < 0)
	{
		food = 0;
	}
	else if (food > 100)
	{
		food = 100;
	}

}


void Player::ChangeWater(int consumption)
{
	water += consumption;

	//Cant go below 0 
	if (water < 0)
	{
		water = 0;
	}
	else if (water > 100)
	{
		water = 100;
	}

}

void Player::ChangeMorale(int consumption)
{
	morale += consumption;

	//Morale will be between 0 and 100
	if (morale < 0)
	{
		morale = 0;
	}
	else if (morale > 100)
	{
		morale = 100;
	}

}

//==================================================
//   CHANGE PLAYER SUPPLIES
//
// Adjusts supplies while preventing negative values
//==================================================
void Player::ChangeSupplies(int consumption)
{

	supplies += consumption;

	//Cant go below 0 
	if (supplies < 0)
	{
		supplies = 0;
	}
	else if (supplies > 100)
	{
		supplies = 100;
	}
}



//==================================================
//  RESET PLAYER STATS
// 
// Restores the players default name and starting 
// stats for a new journey
//==================================================
void Player::ResetStats() 
{
	name = "Traveler";
	health = 100;
	food = 100;
	water = 100;
	supplies = 50;
	morale = 75;

}