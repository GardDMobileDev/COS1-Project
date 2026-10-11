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
Game::Game() : player(), currentLocation(), 
traveler(player, currentLocation), isRunning(true)
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


    //Readd user entry 
    std::string playerName;

    std::cout << "\nWelcome, your journey through the book of Genesis begins.\n";
    std::cout << "\nPlease enter your name Traveler: \n";

    //Updates using getline
    std::getline(std::cin, playerName);

    //Prompt user not to leave blank
    while (playerName.empty())
    {
        std::cout << "Oops! Can't leave blank. Please enter your name: ";
        std::getline(std::cin, playerName);
    }

    //Save name in player object
    player.SetName(playerName);

    //Displays Message
    std::cout << "\nWelcome, " << player.GetName() << "!\n\n";

    //Traveler Handler 
    traveler.StartJourney();

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

	DisplayHeader("BIBLE TRAIL: BOOK OF GENESIS");
	std::cout << "               An Interactive Journey Through Genesis\n";
    std::cout << "=====================================================================\n";
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
void Game::DisplayInstructions()
{
    DisplayHeader("INSTRUCTIONS");

    //The Purpose of the Game: explain to user 
    std::cout << "Welcome to Bible Trail: Book of Genesis\n\n";
    std::cout << "An interactive console adventure inspired by the people,\n";
    std::cout << "places, and events recorded in the Book of Genesis\n";
    std::cout << "Travel through the world of Genesis, explore biblical locations, experience\n";
    std::cout << "important events, and guide your group safely through the journey. Your\n";
    std::cout << "decisions will shape your adventure as you face challenges, manage resources,\n";
    std::cout << "and encounter events inspired by Scripture\n";


    DisplayDivider();

    //What user can do 
    std::cout << "What you can do:\n\n";
    std::cout << "Travel to places connected to the events and people of Genesis\n";
    std::cout << "Keep track of your group's food, water, and supplies to help everyone survive the journey\n";
    std::cout << "Choose how to respond to challenges and situations along the way.\n";
    std::cout << "Experience events and challenges inspired by the Book of Genesis\n";
    std::cout << "Manage your travelers and make choices that affect the progress of your journey\n";
    //std::cout << "Save your progress and return to your adventure later\n"; Add Week 4




    DisplayDivider();

    // Game Features
    std::cout << "Every journey brings new decisions, challenges, and discoveries. Plan your\n";
    std::cout << "travels carefully, manage your resources wisely, and guide your group through\n";
    std::cout << "the world of Genesis.\n\n";
    std::cout << "Are you ready to begin your Bible Trail? Your journey through Genesis awaits!\n\n";


  
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

