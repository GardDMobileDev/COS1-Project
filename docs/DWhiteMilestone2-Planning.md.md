> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name: Bible Trail **
→   
  
**What does your program currently do? (1–3 sentences)**   
→ My Genesis Journey app currently allows players to travel between locations from the Book of Genesis, manage food and water, view player statistics, and make simple decisions.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   1. Menu that allows player to select different actions:
          - start journey, read instructions and exit 
          - Displays Day Counter 
     2. Second Menu Journey:
          - allows user to travel between locations 
          - View Player Stats
          - View current Location
          - Make a selection Menu:
              - Player can continue journey in location
              - Explore location: results in supply consumption
              - Encourage the group: increases morale by 5 points
          - End Journey:
               - ends the game but runs a check to make sure the player wants to end 
           - Input validation using getline(), stoi(), and exception handling
  
**What is NOT working or incomplete?**   
→   Not showing current location, need to find a way to update so this 
    makes sense for the user "Where am I starting from? Where am I?"
  
**What feels confusing or messy in your code?**   
→ I want the output to be a little more clean, be sure the player understands 
next steps, may some prompts in the beginning on main menu

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   Resource management 
→   Currently resources cant fall below 0 but I want to define penalties when resources run out
  
**What does this feature do?**   
→   Prevents food/water from becoming negative
  
**Why is this feature important?**   
→   The consumption will determine the win/lose
  
---
### Feature 2  
**Name:**   
→   Inventory System 
  
**What does this feature do?**   
→   Display detailted items/quantities
  
**Why is this feature important?**   
→   Right now the stats are being displayed but I want this to be a little more clear than just a score
  
---
  
### Feature 3 (optional)  
**Name:**   
→   Event System(Main goal for week 3)
  
**What does this feature do?**   
→   Introduce more encounters, if they make a selection, maybe something occurs and intervenes 
  
**Why is this feature important?**   
→   In the Bible on the Journey so many things tested the travelers and this
came with consequences, this can make the game entertaining and not just feel like step1 step 2
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   Inventory 
  
**Will you modify any existing classes? How?**   
→   Event 
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   I would say Vectors 
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   Main Menu Displays: Start the journey, read instructions or exit
2. User chooses →   
    Start Journey - user is prompted to enter their Traveler name (personal)
3. Program responds →   
     - Displays Journey Menu:
      - travel to next location in Book of Genesis : increases day +description
      - View Player Stats: food, supplies, water, morale etc (just displays)
      - View Current Location: displays where they are currently
      - End Journey : exits Game
4. Loop/next step →   Choosing 4: Displays a new menu for selections: 
            - user can continue on the same journey(displays current) may update to add a message like "You are still in .... or lets continue..."
            - Explore the current location : reduces supplies but may add the Why, currently just says explored so used supplies 
            - Encourage: gains morale but may be add a message about what the user said or did to gain the morale
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   On user selection, more detailed responses from selections
  
- Better error handling:   
→   Update current location at the start of the program other than UNKNOWN
  
- Improved menu/navigation:   
→   updating prompts will help the user know exactly what they are doing 
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   I plan to create Events, I think adding this will update some of my menus and including consequences may create a lot of code in a short time depending on how I handle the structure 
  
**What is your plan if you get stuck?**   
→   If I get stuck I will combine my Week 3 and Week 4. I will break everything down into sections use my Project Board to plan everything out in the beginning of the week with clear direction on next steps
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→  This week, I want to focus on improving my time management skills. Being sick and not getting enough sleep made it difficult to stay on track, and my assignment ended up getting away from me. I want to do a better job of planning ahead, setting priorities, and managing my time so I can complete assignments on time, even when things don’t go as planned
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   I will improve my time management by creating a schedule, setting small goals, and breaking assignments into manageable steps. I will also try to get enough sleep and start assignments earlier so that if I get sick or fall behind, I have time to catch up and finish my work on time
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]  Allow testers to test the game and identify things I can improve 
- [ ]   Inventory class: give details on quantities of resources
- [ ]   Event class: create a vector that stores event/details 
- [ ]   add clearer responses on menu selection 4 
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [ ] Do I know what I’m building this week?   
- [ ] Do I know where to start?   
- [ ] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.

The Inventory and Event classes are planned additions, not existing features. I will introduce them when they provide a clear benefit to the program's organization. he application will continue to use a numbered command-line menu. This interface is straightforward and allows players to interact with the journey without needing a graphical interface.


Planned updated journey menu: 

1. Travel to next location
2. View Player Stats
3. View current location
4. Make location selection
5. View Inventory
6. Exit/Quit Journey

  Program Flow:
  > initialize Game, player and starting location
  >     - display/define current location 
  > - display the journey menu 
  > - validate user selection
  > - perform selection
  > - Update player: location, resources, stats (depends on selection)
  > - Trigger an event: need to determine when I want this to happen
  > - Check if journey should continue or end 
  > - Returns to main menu if journey continues
  > - If user exits: valid and display message 
  
     

