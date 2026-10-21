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
	std::string name;
	int health;
	int food; 
	int water;
	int supplies;
	int morale;

public:
	Player();

	std::string GetName() const;		
	int GetHealth()const;
	int GetFood() const;
	int GetWater() const;
	int GetSupplies() const;
	int GetMorale() const;

	void SetName(const std::string& playerName);
	void LoadStats(int saveHealth, int saveFood, 
		int saveWater, int saveSupplies, int saveMorale);

	void ChangeHealth(int consumption);
	void ChangeFood(int consumption);
	void ChangeWater(int consumption);
	void ChangeSupplies(int consumption);
	void ChangeMorale(int consumption);

	void DisplayStats() const;
    void ResetStats();

};