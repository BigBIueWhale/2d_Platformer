# 2D Platformer: C++, SFML, XML, STL
## Versions: SFML 2.5.1, C++ 17, Mingw64

## Project Goals:
This project consists of a 2D platformer game with the following features:

- **Main Menu**: Provides options to play, access settings, view the scoreboard, or exit the game.
    - *Play*: Leads to the level selection screen, allowing the player to start the game or return to the main menu.
    - *Scoreboard*: Displays the best times achieved for each level.
    - *Settings*: Allows players to mute sounds and change controls during gameplay.
    - *Exit*: Closes the program.
    
    The main menu is dynamic, featuring buttons that enlarge upon cursor collision and emit sounds for collision and clicking.

## Gameplay:
The game is programmed in C++, with the objective of completing each level within a designated time. Failing to complete within the time limit, being attacked by monsters, falling off the map, or colliding with spikes will result in player death. Successfully completing a level unlocks the next level.

### Player:
The player can move left, right, jump, and attack. Movement and attack animations are incorporated into the gameplay. The player's starting position is determined by reading an XML file.

### Map:
The map is read from a .txt file, with letters indicating the type of texture to be placed at the corresponding position. Decorative elements and spikes that can kill the player upon contact are included on the map.

## Monsters:
The game includes two classes of monsters:

1. **DumbChaser**: Chases the player when within range and rushes toward them. If avoided, it continues running forward until falling, dying, or leaving the player's sight. Animated movements are included.
2. **Archer**: Shoots arrows when the player is within range. Moves left and right when the player is not visible. Animated movements and shooting are included.

## Additional Features:
- A small window appears upon player death, prompting the option to restart or return to the main menu.
- The game can be paused.
- The game camera follows the player.
- Information such as player's starting position, monster positions, and map size are determined by reading an XML file for the selected level.
