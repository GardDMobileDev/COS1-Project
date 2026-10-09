#include "Game.h"
#include <iostream>
#include <string>
#include "GameUI.h"



//==============================
//  Week 2 UPDATES:
// - Added Game Class
// - Added getline
// - Added try/catch
// - Connecting Game to Traveler 
//==============================



//==============================
//   STARTS IN RUNNING STATE 
//==============================
Game::Game() : traveler(player, currentLocation)
{
	isRunning = true;
}

//==============================
//   STARTS GAME LOOP  
//==============================
void Game::StartGame() 
{
  //Continue until false 
	while (isRunning)
	{
		DisplayMainMenu();
	}

}

//================================
//  DISPLAYS MAIN JOURNEY MENU
// inludes try/catch, getline uptd
//================================
void Game::DisplayMainMenu() 
{
	//Store user input 
	std::string input;

	//Store the converted menu selection
	int selection;

	DisplayHeader("GENESIS JOURNEY");
	std::cout << "An Interactive Journey Through Genesis\n";
	std::cout << "========================================\n";
	std::cout << "\n";

	std::cout << "1. Start A New Journey\n";
	std::cout << "2. Instructions\n";
	std::cout << "3. Exit\n";
	std::cout << "\n";

	/*
	 Required update per instruction : getline/try catch
	*/
	std::getline(std::cin, input);

    //Check for blank input 
    if (input.empty())
    {
        std::cout << "Invalid selection\n";
        std::cout << "Please select 1, 2, or 3 from the menu.\n";

    }

    try
    {
        //Convert user input from string to int 
        selection = std::stoi(input);

        //Validation: number in range?
        if (selection < 1 || selection > 3)
        {
            std::cout << "Invalid selection\n";
            std::cout << "Please select 1, 2, or 3 from the menu.\n";
        }

        //Players Selection
        if (selection == 1)
        {
            StartJourney();
        }
        else if (selection == 2)
        {
            DisplayInstructions();
        }
        else if (selection == 3)
        {
            ExitGame();
        }
      
    }
    catch (const std::invalid_argument&)
    {
        //This will handle text 
        std::cout << "\n";
        std::cout << "Invalid input.\n";
        std::cout << "Please enter a number\n";

       
    }
    catch (const std::out_of_range&)
    {
        //This will handle text 
        std::cout << "\n";
        std::cout << "The number is too large.\n";
        std::cout << "Please  try again.\n";
    }

  
}


//================================
//  DISPLAYS INSTRUCTIONS
// inludes try/catch, getline uptd
//================================
void DisplayInstructions()
{
    DisplayHeader("INSTRUCTIONS");

    //The Purpose of the Game: explain to user 
    std::cout << "Genesis Journey is an interactive console app based on locations\n";
    std::cout << "and events from the Book of Genesis\n";

    DisplayDivider();

    //Players goal  
    std::cout << "Your goal is to travel through Genesis while managing\n";
    std::cout << "traveler group.\n";

    DisplayDivider();

    // Game Features
    std::cout << "You will be able to travel through Genesis locations\n";
    std::cout << "- Manage Resources like: food, water and supplies\n";
    std::cout << "- Make decisions\n";
    std::cout << "- Encounter events\n";
    std::cout << "- Save and load your journey\n";

    DisplayDivider();

    //Getline Update 
    std::string input;

    std::cout << "Press enter to return to the Main Menu.";
    std::getline(std::cin, input);

}

//Input Validation(REQUIREMENT)
//================================
//    GET MENU SELECTION 
// rewrite method to apply update
// inludes try/catch, getline uptd
//================================
int GetMenuChoice(int min, int max)
{
    std::string input;

    //Keeps looping until player make a valid selection
    while (true)
    {
        std::cout << "Make A Selection: ";

        //Getline update 
        std::getline(std::cin, input);

        //Check for blank input 
        if (input.empty())
        {
            std::cout << "Invalid input. Please enter a number";

            continue;
        }
        try
        {
            //Convert the input to int 
            int selection = std::stoi(input);

            //Check within range
            if (selection < min || selection > max)
            {
                std::cout << "Invalid selection. Please try again.\n";
                continue;
            }

            //Return selection 
            return selection;
        }
        catch (const std::invalid_argument&)
        {
            //Handles text 
            std::cout << "Invalid input. Please enter a number\n";
        }
        catch (const std::out_of_range&)
        {
            //Handles text 
            std::cout << "Number is too large. Please tyr again.\n";
        }

    }

}



//================================
//  START JOURNEY 
// 
// Updates for Week 2:
// Traveler will control the 
// actual travel portion of the game
// 
//Traveler will handle:
// Day Counter 
// Travel 
// Resources 
// Genesis Location 
// Location Selections
//================================
void Game::StartJourney() 
{
    DisplayHeader("BEGIN YOUR JOURNEY");

    std::cout << "Welcome, your journey through the book of Genesis begins.\n";

    std::cout << "\n";

    //Traveler Handler 
    

}

//==============================
//         EXIT GAME 
//==============================
void Game::ExitGame() 
{
    DisplayHeader("EXIT");

    std::cout << "Thank you for playing Genesis Trail!\n";
    std::cout << "Have a blessed day!\n";

    //Updates isRunning to FALSE : stops main game loop
    isRunning = false;
}

