

\*\*Milestone 3: Game Improvements and Refactoring\*\*



This week, I continued refactoring and improving my game by focusing on gameplay balancing, inventory management, travel mechanics, event choices, and error handling. My main goal was to make the journey more challenging and engaging while improving the organization and reliability of the code.



\*\*Features Added and Updated\*\*

1\. Inventory Resource Management

\* Updated the inventory system so that items such as bread, water containers, and aloe can restore resources when needed.

\* Improved item use conditions to prevent items from being consumed when they are not needed.

\* Added a condition to prevent aloe from being consumed when the player's health is already at 60.

\* Made inventory management more important by requiring players to think carefully about when to use their supplies.

\* Previously, players could complete the journey without using inventory items. These changes encourage strategic decisions and make inventory management an essential part of the gameplay.



1\. \*\*Gameplay Difficulty and Starting Stats\*\*

Reduced the player's starting resources to make the game more challenging.

The player now starts with the following stats:

\* Health: 60

\* Food: 60

\* Water: 60

\* Supplies: 50

\* Morale: 75

\* Players previously had enough resources to reach Egypt without using inventory items. Lowering the starting stats makes resource management more important throughout the journey.



1\. \*\*Travel and Resource Management\*\*

\* Reviewed food and water consumption during travel.

\* Reviewed starvation and dehydration penalties.

\* Investigated situations where travel related resource losses could be deducted twice.

\* Reviewed resource recovery when searching for supplies.

\* These changes help make travel decisions more meaningful and prevent resource management from becoming too easy or unfair.



1\. \*\*Event Choices and Game Endings\*\*

\* Reviewed event choices to ensure that player decisions have a greater impact on the journey.

\* Reviewed the conditions for winning and losing the game.

\* Continued improving the overall difficulty and balance of the journey.

\* Meaningful choices and clear win and loss conditions help make the game more engaging and give players greater responsibility for their decisions.



1\. \*\*Player Instructions\*\*

\* Started improving the starting instructions.

\* Worked on explaining the player's available supplies and how to use inventory items.

\* Clearer instructions help players understand the game mechanics before beginning their journey.



\*\*Updates to System Design\*\*

1\. \*\*Journey Reset System\*\*

Implemented the ResetJourney() method after testing revealed that the game did not reset properly between players.

\* Identified an issue with game state persisting between plays.

\* Added a method to reset the journey so that a new player can start a fresh game.

\* Used family testing to help identify the issue.

\* Resetting the journey prevents previous game progress and resource values from affecting a new play.



1\. \*\*Inventory and Resource Logic\*\*

Reviewed the conditions that control inventory usage and resource changes.

\* Improved the logic that determines when inventory items should be consumed.

\* Reviewed how resources are recovered when searching for supplies.

\* Investigated duplicate travel resource deductions.

\* Keeping resource calculations and inventory conditions consistent helps prevent unexpected gameplay behavior.



1\. \*\*Save and Load System Planning\*\*

Currently, I am planning a SaveSystem that will allow players to save and load their progress using file I/O. Saving and loading will allow players to continue their journey without having to restart from the beginning. This feature is planned for the next development stage. Hoping all goes well.



\*\*Refactoring Improvements\*\*

1\. \*\*Improved Inventory Usage Conditions\*\*

Refined the conditions that determine whether an inventory item should be used. For example, aloe should not be consumed when the player's health is already at 60.

This was an improvement because it prevents unnecessary item consumption and makes the inventory system behave more consistently.



2\. \*\*Updated Starting Resource Values\*\*

Changed the player's starting health, food, water, supplies, and morale values to create a more balanced starting point. This improvement makes the journey more challenging and reduces the likelihood that players can complete it without managing their inventory.



3\. \*\*Continued Reviewing Game Logic\*\*

Reviewed event choices, resource consumption, resource recovery, and game ending conditions. This helps identify inconsistencies between different game systems and makes the gameplay easier to test and maintain.



\*\*What I Changed and Why\*\*

The most important changes this week focused on making the game more challenging and fixing issues discovered during testing.

Previously, players could reach Egypt and win without using inventory items because their starting resources were too high. I lowered the starting stats to encourage players to manage their health, food, water, supplies, and morale more carefully.

I also improved the inventory usage conditions to prevent unnecessary item consumption. I reviewed resource recovery and travel penalties after discovering that searching for supplies made it too easy to recover resources and that travel losses could sometimes be deducted twice.



\*\*Challenges and Lessons Learned\*\*

One of my biggest challenges was balancing the game without making it either too easy or too difficult. I learned that starting resource values, inventory usage, travel penalties, and resource recovery all affect the overall difficulty. I also learned that finding a workaround is not always the best solution when debugging. I want to spend more time understanding why an issue occurs and correcting the underlying cause instead of simply making the code work in one situation.





\*\*Plans for Week 4\*\*

My goals for Week 4 are to:

\* Complete testing and ensure the game is playable from beginning to end.

\* Implement the SaveSystem to save and load progress using file I/O.

\* Complete the remaining Genesis locations and events.

\* Finalize the starting instructions so players understand the game mechanics and inventory system.

\* Improve error handling for invalid input and unexpected situations.

\* Continue debugging and fixing the underlying causes of gameplay issues.





\*\*Summary\*\*

Milestone 3 focused on gameplay balancing, inventory improvements, resource management, and fixing issues discovered through testing. The changes make inventory decisions more important, improve the consistency of resource usage, and address problems with resetting the game between players. My next priority is to complete the remaining features, test the full journey, and ensure that the game is reliable, balanced, and fully playable from beginning to end.



