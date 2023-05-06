# ENGG1340-Project

## Game Description
<img src="/images/gameplay-map.png">
<img src="/images/gameplay-map2.png">
Our game, Galatic Empires: Odyssey, is a simulation game which is inspired by the existing civilization-building game "Civilization VI". The goal of the game is to expand your territory through means such as building infrastructures and houses, attack other countries. The game is turn-based, each turn means one day. You can choose when to end each turn, but all the changes made will only be settled after you declare the end of each turn.

The game is won by occupying all the 16 regions on the world map or you can survive for 20 days. The game can also be lost by losing all your territories through being conquered by other countries or consumption of your own military power and manpower after each attack.


## Installation
[Instructions on how to install and run the game, including any prerequisites or dependencies.]
The game can be executed in Linux terminal. 
If you are Windows users type`wsl` to access it.

1. cd to the exact directory
2. type `make start`

## How to Play
This game requires only one player to type commands.

### In the starting screen, 
You can type `new` to start a new game; type `load` or `previous` to load saved game, a new game is started if there is no saved game.

### In the gaming screen,
There are 4 interfaces.
#### Commands to switch between interfaces: 
`to i1`, `to i2`, `to i3`, `to i4`.
#### The interface1 is admin panel.
#### The interface2 is internal action board.
1.  `show built` listed the buildings you now have.
2.  `show buildable` listed the buildings and their max amount you can build now
3.  `show info BUILDING_NAME` show the details of a building you type in the BUILDING_NAME
4.  `build NUM BUILDING_NAME` buy NUM amount of building with the name BUILDING_NAME typed.

#### The interface3 is the external action board.
1. `move NUM [solider/tank] from x,y to x,y` is the command to move your soliders and tanks from your lands. 

Type `end` to end the current game day.
Type `help` to see the command guides.
Type `quit` to save and leave the game.

## Contributors
#### Team Members (alphabetically order)

1. Chan Yiu Sing (IORIshizuku)
2. Cheng Ching Yan Grace (flyuzu)
3. Chiu Yi Shun (Eylssca)
4. Hui Chi Ming (JimmyHCM)
5. Kwong King Lam (azidoazideazide)

*name in bracket is the nickname in GitHub

## Acknowledgements
We have not used any non-standard C/C++ libraries in our game.

Game Rules
---

There are 4 countries in total and there are four resources for each country, namely population, food, fuel, metal. In each turn, territories, city index and the amount of resources will be altered after you have made different choices.

Type “new” if you are new to the game. If you want to load back your previous game status, please type “previous”.
You will be assigned to one of the 4 countries and you will receives the corresponding resources. You will need to make good use of your own resources in the following time.
After the beginning of each turn, you can choose to increase the number of soldiers or add more resources or attack other countries. You can do more than one action in each turn.
After all your modifications, you have to declare the end of that turn. Then, all the changes regarding to resources, territories and city index will be made and one day will be passed.
You will repeat step 2 and 3 until the end of the game.

*You can save the game progress at any time, so that you can get back to it next time if you have not reached the state of victory or loss.*


Game World
---

The game world is a 4x4 map consisting of 16 territories. The 4 territories at the 4 corners are being occupied by each country respectively at the beginning of the game. The remaining 12 lands remain unoccupied at first and players will have to send troops to the desired land and fight with their enemies before they can get the land. Failure may occur depending on various factors, such as starvation.


## A List of Features Implemented

1. Your enemies are controlled by random factors. They may have different actions in each turn.
2. We will remind you if you give an invalid command.
3. You can check your amount of resources at anytime during the game.
4. Every time when you quit the game, your game progress is saved. Thus, you can get back to the previous status when you enter our game again later on.


## Coding Elements

### Element 1 - Generation of random game sets or events:
#### Random event 1 - Daily News
In the beginning of every game day, players will see a random story. Some may have bad or good effect to the player resources.
#### Random event 2 - Random number of moves for NPC countries each day. 
In each day, countries controlled by computer has 0 to 4 moves. In these moves, they can choose to build buildings and move soldiers like the player does, for example, they may build more mines, factories, houses or other buildings. 
#### Random event 3 - Random selected land to assign solders by npc countries
The npc countries may send troops to random lands on the world map with random number of soldiers.


### Element 2 - Data structures for storing game status:
#### Classes used
* `class Military_Resouces`: a class representing a set of military resources, including the number of soldiers and tanks.
* `class Resources`: a class representing a set of resources, including food, fuel, metal, citizen, and other attributes such as maximum population, livelihood, military strength, diplomacy, and military factor.
* `class Building`: a class representing a building, including its name, requirements, description, effect, cost, production, limit per land, and initial quantity.
* `class i3Map`: a class representing a world map, including the military resources of each country and its owner.
* `class Country`: a class representing a country, including its resources and attributes, such as whether it is dead, the building limits and quantities it owns.

#### Extensive uses of C++ STL containers
`std::map` and `std::vector` are used a lot in the code.

### Element 3 - Self-made game UI
The user interface can be read inside UI.cpp and UI.h
The class UI is constructed as a game screen. It is a 2D grids of characters in 120 x 47. It allows the divide of game screen into different ui_regions showing different informations. 
For each ui_region, drawing of content to the screen is automatically aligned at center vertically. The developers can decide the horizontal alignment of the content to be to the left, at center or to the right. The word and background colors of each ui_region can be modified by developers.

### Element 4 - Dynamic memory management applied in constructing the UI:
We have used the “new” function to create a dynamic array to as a buffer to store the line by line screen drawing for the UI design. We use the “delete” operator to deallocate the memory after drawing the lines for the UI. We do not use the “malloc” function, so memory does not need to be “free” afterwards.

### Element 5 - File input/output (e.g., for loading/saving game status):
We have implemented file input/output functionality to allow the player to save and load their game progress so that he/ she can get back to his/ her previous status when he/ she re-opens the game.

### Element 6 - Program codes in multiple files:
Our code is organized into multiple source files to improve readability and maintainability.
