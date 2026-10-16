#include "Game.h"
#include "GameUI.h"
#include <iostream>
#include <string>

//==================================================
//   DISPLAY INSTRUCTIONS 
// 
//  Explains the purpose, features and available 
// actions in Bible Trail 
//==================================================
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


    DisplayHeader("GAME DETAILS: START JOURNEY MENU");

    //The Purpose of the Game: explain to user 
    std::cout << "Travel Next: Advances player to the next location. Consumes food and water.\n\n";
    std::cout << "View Player Stats: Displays the players: name, health, food, water, supplies, and morale.\n\n";
    std::cout << "View Current Location: Shows the current location and its description.\n\n";
    std::cout << "Make a Selection: Player can choose and action at the current location.\n\n";
    std::cout << "View Inventory: Displays the available inventory items and their quantities.\n\n";
    std::cout << "Use an Inventory Item: Use food, water or healing items to restore resources\n\n";
    std::cout << "End Journey: Allows the player to stop the current journey.\n\n";

    std::cout << "To play, make a selection from the menu and press ENTER\n\n";



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


//==================================================
//   GET MENU SELECTION 
// 
//  Validates user input and returns a selection 
// within the range of min and max
//==================================================

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

//==================================================
//  GAME CONSTRUCTOR 
// 
// Initializes the player, current location,
// traveler and game running state 
//==================================================
Game::Game() : player(), currentLocation(), 
traveler(player, currentLocation), isRunning(true)
{
	isRunning = true;
}

//==================================================
//   GET MENU SELECTION 
// 
//  Displays the main menu until game ends
//==================================================
void Game::StartGame() 
{
  //Continue until false 
	while (isRunning)
	{
		DisplayMainMenu();
	}

}

//==================================================
//   START JOURNEY 
// 
// Resets the journey, collects players name, and
// starts the travelers journey
//==================================================
void Game::StartJourney()
{
    //Reset the game for a new journey
    traveler.ResetJourney();

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
        std::getline(std::cin, playerName);

        if (playerName.empty())
        {
            std::cout << "Name cant be blank. Please try again: ";
        }
    }

    //Save name in player object
    player.SetName(playerName);

    //Displays Message
    std::cout << "\nWelcome, " << player.GetName() << "!\n";

    //Traveler Handler 
    traveler.StartJourney();

}


//==================================================
//   DISPLAYS MAIN MENU
// 
// Displays the main menu and processes the 
// players selection
//==================================================
void Game::DisplayMainMenu() 
{
	//Store user input 
	std::string input;

	//Store the converted menu selection
	int selection;

	DisplayHeader("BIBLE TRAIL: BOOK OF GENESIS");
	std::cout << "               An Interactive Journey Through Genesis\n";
    DisplayDivider();
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


//==================================================
//  EXIT GAME 
// 
// Displays the exit message and stops the main 
// game loop
//==================================================
void Game::ExitGame() 
{
    DisplayHeader("EXIT");

    std::cout << "Thank you for playing Genesis Trail!\n";
    std::cout << "Have a blessed day!\n";

    //Updates isRunning to FALSE : stops main game loop
    isRunning = false;
}

