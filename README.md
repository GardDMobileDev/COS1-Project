# 🚀 Welcome to Project & Portfolio!

This repository will be used to keep track of research and development conducted in this class. Follow the instructions below to get started.
cos
### Getting Started

**1.** Review the [About](./docs/01_about/README.md) README and all of the links it provides.

**2.** Review the documentation and [Getting Started](./docs/02_getting_started/README.md) steps in this repository's docs folder.

**3.** Attend the first Live Lecture to see a live setup demo. If you are unable to attend, make sure to watch the archive.

### Next Steps...

After completing the above steps, feel free to begin updating this readme where indicated below. Remember to update this document each week to receive proper credit for the weekly Milestone assignment.

<br>

> ❗️ &nbsp; Now that you have read to this point, go ahead and delete this sentence and everything above it.

<br>

# Project & Portfolio 1

### Desire' & White

Hello my name is Desire' White. I am a student from New Jersey(raised). The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

This week, I worked on building the foundation for my Bible Trail Console Application. I created the C++ project structure and started developing the Player, Traveler and location classes. I also worked on organizing the project into .h/.cpp files and creating main and journey menus. My goal is to create the main structure of the app that makes building onto a simple process. 

I didn't face any major challenges. If I had to define a challenge I encountered, I would say organizing classes and making decisions on what responsibilities/control they would contain. At this time each class will have a specific purpose making declarations in my .h and defining them in my .cpp files. A small error I did face was in my loops. Spelling/typos I am known for and this caused my .exe to crash.  

Now that I have a better understanding of how to use references, which I have been avoiding, this helped me organize my classes more efficiently. 

My goal in the coming week is to build on the foundation by creating a playable game. I plan to add a Game class, travel system, counter for days, food, water, health, supplies and morale. As I go along I may change some things but this is my plan to date. 

### Week 2

This week, I worked on building the core gameplay for my Bible Trail. I worked on creating the Game.h and Game.cpp files, connecting my existing classes, and using getline() and try/catch to handle user input and validate menu choices

One challenge was making sure my classes connected correctly and that the input validation worked without causing errors. Being sick and not getting enough sleep also made it harder to manage my time, so I plan to break my assignments into smaller tasks and give myself more time to complete them.

I improved my understanding of how classes work together and how to organize code into separate header and implementation files. I also learned more about using getline(), stoi(), and try/catch to handle invalid user input.

For Week 3 Upcoming Goals, I plan to further develop my existing menus and test. I currently have an Issue called Prototype. This is just for myself. I want to refer back to this issue to be sure I stay focused on things I want to improve upon. Two important things I will focus on will be creating an Inventory system for quantity of supplies and Event system, that will introduce encounters along the journey which will impact the inventory. 


### Week 3
STAND UP RESPONSE(original post) 

This week, I continued working on refactoring to update consistent comments, removed unnecessary comments, or repeats. I also spent a lot of time improving my game. I focused on balancing the gameplay, improving the inventory system, and updating events so that player choices have a greater impact on the journey. I also reviewed the travel mechanics, starting player stats, and game ending conditions to make the game more challenging and engaging. 

I updated the inventory system so that items such as bread, water containers, and aloe can be used to restore resources when needed. I also made changes to ensure items are only consumed when appropriate. For example, aloe should not be consumed when the player's health is already at 60 These changes help prevent players from wasting inventory items and encourage them to think carefully about when to use their supplies. Another important change was lowering the player's starting stats to make winning the game more challenging. The player now starts with the following stats:
* Health: 60
* Food: 60
* Water: 60
* Supplies: 50
* Morale: 75

Prior stats for health, food and water were at 100.

Previously, players could reach Egypt without using any inventory items because they started with enough resources to complete the journey. By lowering health, food, and water to 60, players must make more thoughtful decisions about when to use supplies, search for resources, rest, or push forward. My goal is to make inventory management an essential part of the gameplay rather than an optional feature. I also reviewed the event choices and resource management mechanics, including food and water consumption during travel, starvation and dehydration penalties, and the conditions for winning or losing. Additionally, I am working on making the starting instructions clearer so players understand what supplies they have and how to use their inventory.

One of my biggest challenges has been balancing the game. During testing, I realized that players could reach Egypt and win without using any inventory items because their resources remained high enough throughout the journey. I also found that searching for supplies made it too easy to recover resources and that travel loss could be deducted twice in certain situations. I addressed this by updating player stats. 

Having my family test the game has helped me identify issues that I might not have noticed while working on the code myself. Their testing previously helped me discover that the game did not reset properly between players, which led me to implement my ResetJourney() method. 

Finally, I want to improve my debugging skills by spending more time understanding why an issue occurs instead of simply finding another way to make the code work. My plans for week 4 will be to complete, test, and be sure my game is fully playable from beginning to end. I plan to add a SaveSystem that allows players to save and load their progress using file I/O. I will also complete the remaining Genesis locations and events, finalize the player instructions, and improve error handling to ensure the game responds appropriately to invalid input and unexpected situations



Stay tuned, this stand up is coming soon...

### Week 4

My final stand up...
