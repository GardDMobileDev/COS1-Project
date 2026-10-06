#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Player.h"
#include "Traveler.h"
#include "Location.h"
#include "GameUI.h"

/*
FUNCTION DECLARATIONS 
  - Functions to start The Bible Trail 

        - GetMenuChoice : menu choice from player
        - DisplayMainMenu : displays menu
        - DisplayInstructions : displays game instructions
        - StartJourney : Starts/controls journey of Player 
*/

//GetMenuChoice 
int GetMenuChoice(int min, int max);

//Display Main Menu 
void DisplayMainMenu();

//Display Instructions 
void DisplayInstructions();

//Start Journey 
void StartJourney(Player& player, Traveler& travelers, const std::vector<Location> locations);


/*
  The main:
    - This will be the control flow. This creates Player/Traveler objects.
    - This will store location in Genesis into a vector (REQUIREMENT)
    - This will use input validation check for user entry
    - The app should Display a menu for the player to start, view instructions
    of the game or exit.

   Program Runs:
       - Asks for name
       - Provides Options to
           - View Status
           - View Travelers
           - View Locations
           - Continue on Journey
 */
int main()
{

    //Create a Player 
    Player player;

    //Create a Traveler : starts the group
    Traveler travelers;

    //Create Locations : vector will store multiple objects
    std::vector<Location> locations;

    /*
       Books of Genesis Locations (Important Locations)
       
       1. Garden of Eden: God placed Adam and Eve to tend before banishing them for sin 

       2. Noahs Ark: God commands Noah to build, spare his family/animals before the flood 

       3. Tower of Babel: A tower built by people to be boastful, not for God, 
       because they spoke the same lanaguage they could continue to build so he 
       made them all speak different languages to cause confusion

       4. Abrahams Journey: The man who was the example of true fath, God made a promise
       to give him the Promise Land, bless his decendents, and all of his family line
       for his obedience

       5. Egypt: A journey in Egpty ( to be continued ) 
    
    */
    locations.push_back(Location("Garden of Eden", "The Garden Adam was suppose to tend to with Eve."));
    locations.push_back(Location("Noah's Ark", "The world is full of sin. Noah has been tasked to build an ark."));
    locations.push_back(Location("Tower of Babel", "People are gathered to build a great city and tower."));
    locations.push_back(Location("Abraham's Journey", "Abraham leaves home, packs up his family and God leads him to the Promise Land."));
    locations.push_back(Location("Egypt", "The Journey reach Egypt. This is a significant location."));
 

    //Loop so long as user makes a selection
    bool start = true;

    //This will keep displaying the main menu until Exit is selected
    while (start)
    {
        //Display Menu
        DisplayMainMenu();

        //Get the menu selection
        int choice = GetMenuChoice(1, 5);

        switch (choice)
        {

        case 1: 
              //Start Journey 
            StartJourney(player, travelers, locations);
            break;

        case 2: 
              //Display Instructions
            DisplayInstructions();
            break;

        case 3: 
             //Exit 
            start = false;
            std::cout << "Thank your playing the Bible Trail! Goodbye!" << std::endl;
            break;

        default:
            std::cout << "Oops. Something went wrong. Try again." << std::endl;
            break;
        }

    }
    //End program 
    return 0;
    
}


//Display Main Menu 
void DisplayMainMenu()
{
    DisplayHeader("GENESIS JOURNEY");
    std::cout << "An Interactive Journey Through Genesis\n";
    std::cout << "========================================\n";
    std::cout << "\n";

    std::cout << "1. Start A New Journey\n";
    std::cout << "2. Instructions\n";
    std::cout << "3. Exit\n";
    std::cout << "\n";

}


//Display Instructions 
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

    //Clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Wait for player to press Enter 
    std::cin.get();

}

//Input Validation(REQUIREMENT)
int GetMenuChoice(int min, int max) 
{
    int choice;

    //Keep running until user selects a valid option
    while (true)
    {
        std::cout << "Make a Selection:";

        //Get input
        if (std::cin >> choice)
        {
            //Is number in range
            if (choice >= min && choice <= max)
            {
                return choice;
            }

        }

        //Error 
        std::cout << "Invalid. Please select an option from the menu." << std::endl;

        //Clear 
        std::cin.clear();

        //Remove invalid input 
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    }

}

//Start Journey 
void StartJourney(Player& player, Traveler& travelers, const std::vector<Location> locations) 
{
    //Clear
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string playerName;


    DisplayHeader("BEGIN YOUR JOURNEY");

    //Prompt user 
    std::cout << "Enter the name of your traveler: ";
    std::getline(std::cin, playerName);

    //Check 
    while (playerName.empty())
    {
        std::cout << "Please enter a name for your traveler.\n";
        std::cout << "Enter the name of your traveler: ";
        std::getline(std::cin, playerName);

    }

    //Stores name inside player
    player.SetName(playerName);

    //Journey menu 
    bool journey = true;

    //Continue to display journey menu until user chooses return
    while (journey)
    {
        DisplayHeader("YOUR JOURNEY");

         //Display name of player 
        std::cout << "Traveler: " << player.GetName() << std::endl;
        std::cout << "\n";
        
        //Display Options
        std::cout << "1. View Status\n";
        std::cout << "2. View Travelers\n";
        std::cout << "3. View Genesis Locations\n";
        std::cout << "4. Continue Journey\n";
        std::cout << "5. Return to Main Menu\n";

        //User selection
        int choice = GetMenuChoice(1,3);

        switch (choice)
        {

        case 1: 
             // Display Player Stats 
            player.DisplayStats();
            break;

        case 2:
            //Display Travelers 
            travelers.DisplayTravelers();
            break;

        case 3: 
            //Display Locations
            DisplayHeader("LOCATIONS");

            //Loop through vector 
            for (int i = 0; i < locations.size(); i++)
            {
                std::cout << i + 1 << ". " << locations[i].GetName() << std::endl;
            }

            std::cout << "\n";
            std::cout << "Enter a location to view it, \n";
            std::cout << "or 0 to return.\n";

            {
                int locationChoice;

                //Validate selection
                while (true)
                {
                    std::cout << "Selection: ";

                    if (std::cin >> locationChoice)
                    {
                        if (locationChoice == 0)
                        {
                            break;
                        }

                        //Check selection
                        if (locationChoice >= 1 && locationChoice <= static_cast<int>(locations.size()))
                        {
                            //Display selected 
                            locations[locationChoice - 1].DisplayLocation();
                            break;
                        }
                    }

                    //Error 
                    std::cout << "Invalid. Try Again.\n";

                    //Clear
                    std::cin.clear();

                    //Remove neg input
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                }
            }
            break;
           
        case 4: 
            std::cout << "Continue your journey.. (temp placement)";
            //Will continue next week
            break;

        case 5: 
            journey = false;
            break;

        default:
            std::cout << "Something went wrong. Try again.";

            break;
        }
    }

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
