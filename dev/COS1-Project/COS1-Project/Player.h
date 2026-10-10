#pragma once
#include<string>

/*
Stores information about the person controlling the journey
  - each player will have member variables below
  - example: Player player1;
  - member vars will represent stats of player  
  - Setters/Getters will be used to access mem vars outside class
  - Constructor runs when player created
*/
class Player 
{
	//private member variables
	std::string name;

	int health;
	int food; 
	int water;
	int supplies;
	int morale;

	//Constructor : will set the players starting value
	public:
		Player();

   /*
     Getters: allows access to player information 
	  - const read but dont change object 
   */
		std::string GetName() const;

		int GetHealth()const;
		int GetFood() const;
		int GetWater() const;
		int GetSupplies() const;
		int GetMorale() const;

	 /*
	   Setters: update players name
	   &: wont modify string, allow access and not copy
	 */
	void SetName(const std::string& playerName);

	//WEEK 2 UPDATES: will be + or -
	void ChangeHealth(int consumption);
	void ChangeFood(int consumption);
	void ChangeWater(int consumption);
	void ChangeSupplies(int consumption);
	void ChangeMorale(int consumption);



	//Display players stats
	void DisplayStats() const;
};