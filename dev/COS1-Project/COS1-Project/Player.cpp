#include "Player.h"
#include <iostream>
#include "GameUI.h"


/*
Player Constructor : stats for new game
 - This class defines whats actually happening in Player.h
 - Player:: - belongs to Player.h class 
 - data in constructor give the beginning state of the object
 - Getters get the data from object


*/
Player::Player()
{
	name = "Traveler";
	health = 100;
	food = 100;
	water = 100;
	supplies = 50;
	morale = 75;
}

/*
Set Players name
  - const : read playerName but dont change
  - & : referencing name but not creating a copy

  Progress with research: the idea is the class holds data that can be 
  used to create multiple objects. As an example name is the private variable
  I am using that I dont want to be accessed throughout the program. So when I 
  use my setter method, users can create a name, that can be read and update name var.
  Each player will have its own copy of name. The name will be a reference of playerName.
*/
void Player::SetName(const std::string& playerName) 
{
	name = playerName;

}

std::string Player::GetName() const { return name; }

int Player::GetHealth()const { return health; }

int Player::GetFood() const { return food;}

int Player::GetWater() const { return water; }

int Player::GetSupplies() const { return supplies; }

int Player::GetMorale() const { return morale; }

//Display players stats
void Player::DisplayStats() const 
{
	DisplayHeader("PLAYER STATS");
	
	std::cout << "Traveler: " << name <<std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Food: " << food << std::endl;
	std::cout << "Water: " << water << std::endl;
	std::cout << "Supplies: " << supplies << std::endl;
	std::cout << "Morale: " << morale << std::endl;

	std::cout << "=====================================================================";

}

//Week 2 Updates: Declarations new methods
void Player::ChangeHealth(int consumption)
{

	health += consumption;

	//Cant go below 0 
	if (health < 0)
	{
		health = 0;
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

}


void Player::ChangeWater(int consumption)
{
	water += consumption;

	//Cant go below 0 
	if (water < 0)
	{
		water = 0;
	}

}

void Player::ChangeSupplies(int consumption)
{

	supplies += consumption;

	//Cant go below 0 
	if (supplies < 0)
	{
		supplies = 0;
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

