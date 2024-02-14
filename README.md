# Description
The project involves implementing a game similar to `Plants vs Zombies` but adapted to have a much simpler geometry.

# Game Overview
The game takes place on a grid with 3 rows and 3 columns. Enemies appear randomly from the right side of the screen and move along a line towards the left side. If an enemy crosses the entire line, the player loses a life. Losing all three lives results in losing the game.

To combat the enemies, the player can place a diamond-shaped projectile launcher in one of the three cells on each row. Once projectiles hit an enemy three times, it disappears temporarily, saving the situation.

However, the player faces two challenges. Firstly, they can only place a limited number of launchers due to the cost of stars, which appear randomly on the scene and must be collected. Secondly, each launcher can only damage a specific type of enemy based on color.

# General Rules
- Place diamonds on the game scene.
- The game mechanics are color-based, with four types of diamond-projectile-enemy triplets, each of the same base colors.
- Collect stars to gain resources for placing diamonds.
- Combat enemies with projectiles launched by diamonds.
- Manage resources wisely to defeat enemies effectively.

# Instructions
- Download the repository
- Start `build/GFXFramework.sln` in Visual Studio Code
- Start the `main.cpp` file
- Use the mouse to interact with the game interface.
- Drag and drop diamonds onto the grid to place them.
- Collect stars to gain resources for placing diamonds.
- Strategically place diamonds to combat enemies and protect the grid.
