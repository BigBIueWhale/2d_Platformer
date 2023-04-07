#2D PLATFORMER: C++, SFML, XML

MY GOALS FOR THIS PROJECT:

The project includes a main menu with the options to play, access settings, view the scoreboard, or exit the game.
Choosing "play" leads to the level selection screen, from which the player may proceed straight to the game or return to the main menu.
The scoreboard displays the best times achieved for each level.
The settings menu allows players to mute sounds and change the controls during gameplay.
Exiting the game closes the program.
The main menu is dynamic, with buttons that grow larger upon collision with the cursor and emit two sounds - one for collision and one for a click.

GAMEPLAY:
The platform game is programmed in C++. The player's objective is to complete each level within a designated time. If the time limit is exceeded, the level is considered failed.
Players can also die by being attacked by monsters, falling off the map, or colliding with spikes. Once a level is successfully completed, the next level is unlocked.

PLAYER:
The player can move left, right, jump, and attack. When moving left or right, the player's position is updated with constant values. Gravity and jumping involve dynamic changes in the player's velocity.
Movement and attack animations are incorporated into the gameplay. The player's starting position is determined by reading an XML file.

MAP:
The map is read from a .txt file. Letters within the .txt file indicate the type of texture to be placed at the corresponding position on the map.
The map includes decorative elements that serve a purely visual role, as well as spikes that can kill the player upon contact.

Game includes two classes of monsters:
DumbChaser - chases the player when within its range of sight and rushes toward the player. If the player avoids the chaser, it continues running forward until it falls or dies, or until it leaves the player's sight. The chaser's movements are animated.
Archer - shoots arrows when the player is within its range of sight. The archer moves left and right when the player is not visible. The archer's movements and shooting are animated.

When the player dies, a small window appears asking whether to restart or return to the main menu.
The game can be paused. Game camera follows the player.

Other information such as the player's starting position, the position of monsters, and the size of the map are determined by reading from an XML file that corresponds to the selected level.
