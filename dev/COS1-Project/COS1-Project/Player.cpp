#include "Player.h"
#include <iostream>


//Player Constructor : stats for new game
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

std::string Player::GetName() const 
{


}


int Player::GetHealth()const 
{


}


int Player::GetFood() const 
{

}


int Player::GetWater() const
{



}


int Player::GetSupplies() const 
{



}



int Player::GetMorale() const 
{




}


