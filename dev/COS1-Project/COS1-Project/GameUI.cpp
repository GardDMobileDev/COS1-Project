#include "GameUI.h"
#include <iostream>

void DisplayHeader(const std::string& title) 
{
	std::cout << "\n";
	std::cout << "=====================================================================\n";
	std::cout << "                         " << title << "\n";
	std::cout << "=====================================================================\n";

}

void DisplayDivider() 
{
	std::cout << "=====================================================================\n";
}
