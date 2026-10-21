#pragma once
#include "Player.h"
#include "Traveler.h"

//==================================================
// SAVE SYSTEM CLASS
//
// Saves and loads the players journey
//==================================================
class SaveSystem
{
public:


	bool SaveGame(const std::string& fileName, const
		Player& player, const Traveler& traveler);

	bool LoadGame(const std::string& fileName,
		Player& player, Traveler& traveler);

};