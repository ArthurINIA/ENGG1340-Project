# ENGG1340-Project
+ Team Members (alphabetically order):

Chan Yiu Sing (IORIshizuku)
Cheng Ching Yan Grace (flyuzu)
Chiu Yi Shun (Eylssca)
Hui Chi Ming (JimmyHCM)
Kwong King Lam (azidoazideazide)

*name in bracket is the nickname in GitHub


+ Game Description:

Our game, Galatic Empires: Odyssey, is a simulation game which is inspired by the existing civilization-building game "Civilization VI". The goal of the game is to expand your territory through means such as building infrastructures and houses, attack other countries. The game is turn-based, each turn means one day. You can choose when to end each turn, but all the changes made will only be settled after you declare the end of each turn.

The game is won by occupying all the 16 regions on the world map or you can survive for more than 20 days. The game can also be lost by losing all your territories through being conquered by other countries or consumption of your own military power and manpower after each attack.


+ Game Rules:

There are 4 countries in total and there are four resources for each country, namely population, food, fuel, metal. In each turn, territories, city index and the amount of resources will be altered after you have made different choices.

1.	Type “new” if you are new to the game. If you want to load back your previous game status, please type “previous”.
2.	You will be assigned to one of the 4 countries and you will receives the corresponding resources. You will need to make good use of your own resources in the following time.
3.	After the beginning of each turn, you can choose to increase the number of soldiers or add more resources or attack other countries. You can do more than one action in each turn.
4.	After all your modifications, you have to declare the end of that turn. Then, all the changes regarding to resources, territories and city index will be made and one day will be passed.
5.	You will repeat step 2 and 3 until the end of the game.

*You can save the game progress at any time, so that you can get back to it next time if you have not reached the state of victory or loss.


+ Game World:

The game world is a 4x4 map consisting of 16 territories. The 4 territories at the 4 corners are being occupied by each country respectively at the beginning of the game. The remaining 12 lands remain unoccupied at first and players will have to send troops to the desired land and fight with their enemies before they can get the land. Failure may occur depending on various factors, such as the military factor.


+ A List of Features Implemented

1.  Your enemies are controlled by random factors. They may have different actions in each turn.
2.  We will remind you if you give an invalid command.
3.  You can check your amount of resources at anytime during the game.
4.  Every time when you quit the game, your game progress is saved. Thus, you can get back to the previous status when you enter our game again later on.


+ Coding Elements:

1.	Generation of random game sets or events: 
Players will see a random story every time when they enter our game. In each turn, the other countries may send troops to random lands on the world map with random number of soldiers. They will also have random number of additional actions, for example, they may build more mines, factories, houses or other buildings. Energy crisis, financial crisis, decrease in birth rate, royalty of the chief of staff are all the random events that may happen to the player in each turn in the game. After each turn, the city index is altered randomly as well. There are up to 20 random events that may happen in the game.

2.	Data structures for storing game status:
In <all_interface.h>, there are 4 class functions. Under the class “Resources”, there are many resources like, fuel, metal and food. They are all set to a certain standard at the beginning of the game. Under the class “Building”, “name”, “requirement”, “description” and “effect” are stored in the form of string while “build_limit” and “qty_owned” are stored in the form of integer. Under the class “military_resources”, we have “country” and “alliance”. The class “map” stores the world map in our game.
In <UI.h>, there are 2 class functions, namely “ui_region” and “UI”. They store the dimension and other details of the user interface of the game.

3.	Dynamic memory management: 
We have used the “new” function to create a dynamic array to store the line by line screen drawing for the UI design. We use the “delete” operator to deallocate the memory after drawing the lines for the UI. We do not use the “malloc” function, so memory does not need to be “free” afterwards.

4.	File input/output (e.g., for loading/saving game status): 
We have implemented file input/output functionality to allow the player to save and load their game progress so that he/ she can get back to his/ her previous status when he/ she re-opens the game.

5.	Program codes in multiple files: 
Our code is organized into multiple source files to improve readability and maintainability.


+ Non-Standard C/C++ Libraries:

We have not used any non-standard C/C++ libraries in our game.


+ Compilation and Execution Instructions:

To run the game, follow these instructions:
1.	Run the game using the command “make main” in the terminal.
2.	Do “./main” to start the game.
3.	Follow the on-screen instructions to play the game.

