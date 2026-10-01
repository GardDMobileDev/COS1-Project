#include "Traveler.h"
#include <iostream>

/*
 This will show what to do with the information from Traveler.h
  - holds the travelers that will be from the book of Genesis
*/

/*
Constructor
  Adam: first human created to tend to Gods Creation
  Noah: Chose to preserve human/animal life during the flood because of his faith
  Abraham: father of a great nation: Called by God because of his faith and God would
  allow his generations to inherit land and be blessed through him
*/
Traveler::Traveler() 
{
	travelers.push_back("Adam");
	travelers.push_back("Noah");
	travelers.push_back("Abraham");
}


//Vector to Add Travelers
void Traveler::AddTraveler(const std::string& travelerName) 
{
	travelers.push_back(travelerName);
}


//Displays All Travelers
void Traveler::DisplayTravelers() const 
{
	std::cout << "\n";
	std::cout << "=====================================================================";
	std::cout << "                     YOUR TRAVELERS\n";
	std::cout << "=====================================================================";

	//Check if there are any travelers
	if (travelers.empty())
	{
		std::cout << "There are no travelers\n";
	}
	else
	{
		//Loop through the vectors and display traveler 
		int num = 1; 

		for (const std::string& travler : travelers)
		{
			std::cout << num << ". " << travler << std::endl;

			num++;
		}
	}


	std::cout << "Travel Count: " << travelers.size() << std::endl;
	std::cout << "=====================================================================\n";


}

//Returns Traveler Size
int Traveler::GetTravelerSize() const
{
	return travelers.size();

}