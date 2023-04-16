#include "Game.h"
#include "map.h"
#include <iostream>
Game::Game()
{ //RESULT: Push back game objects to vector + dynamic cast


    //INIT LEVEL
    struct_Level level_data;
    level_data = xmlhandler.loadLevelDataFromFile();



    entities_vector.push_back(std::make_unique<Map>(level_data.map_size));
    entities_vector.push_back(std::make_unique<Player>(level_data.player_pos));

    player = dynamic_cast<Player*>(entities_vector[1].get());
    map = dynamic_cast<Map*>(entities_vector[0].get());

}


std::string Game::eventHandling(sf::RenderWindow &window)
{//RESULT: GAME

    //MOVE/ANIMATIONS FUNCTIONS
    player->move();


   //###########VALUE GETTERS//INIT  #####  <---- PUT IN ANOTHER FUNCTION LATER
    //MAP
   walls_vector = map->getWalls();
   spikes_vector = map->getSpikes();
    //PLAYER
   player_bounds = player->getBounds();
   player_velocities = player->getVelocity();




   //Collision detection:
    player_move_bounds = player_bounds;
    player_move_bounds.height -=5;

    player_jump_bounds = player_bounds;
    player_jump_bounds.top =player_jump_bounds.top + player_jump_bounds.height - 7.0;
    player_jump_bounds.height = 7.0;

    player_cancel_jump_bounds = player_bounds;
    player_cancel_jump_bounds.top -= 8.0;
    player_cancel_jump_bounds.height = 8.0;



//###########################################################################################################
//###### MOVE LEFT AND RIGHT PLAYER + COLLISIONS

player->setBoolRightMove(0);
player->setBoolLeftMove(0);
player->setCancelJump(0);

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
    player->setBoolRightMove(1);
   player_move_bounds.left +=2; // < - 2 == player velocity move left/right  !!!
    for(auto &el : walls_vector)
    {
        if(el.getGlobalBounds().intersects(player_move_bounds))
        {
            player->setBoolRightMove(0);
            break;
        }
    }
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
    player->setBoolLeftMove(1);
    player_move_bounds.left -=2;

    for(auto &el : walls_vector)
    {
        if(el.getGlobalBounds().intersects(player_move_bounds))
        {
            player->setBoolLeftMove(0);
            break;
        }
    }
}


//########################################
//##########JUMPS AND GRAVITY + COLLISIONS

//GRAVITY
player->setBoolGravitation(1);
for(auto &el : walls_vector)
{
    if(el.getGlobalBounds().intersects(player_jump_bounds))
    {
        player->setBoolGravitation(0);
        break;
    }
}

//JUMP IF SPACE
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
    for(auto &el : walls_vector)
    {
        if(el.getGlobalBounds().intersects(player_jump_bounds))
        {
            player->setBoolJump(1);
            break;
        }
    }
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
{
    player->setBoolAttack(1);
}

//JUMP CANCEL IF PLAYERS TOP HITS WALL
for(auto &el : walls_vector)
{
    if(el.getGlobalBounds().intersects(player_cancel_jump_bounds))
    {
        player->setCancelJump(1);
        break;
    }
}


return "";
}

//#########################################################################################################################################
//#########################################################################################################################################

void Game::drawWindow(sf::RenderWindow &window)
{
    //RESULT: Draw everything in the game
    for (const auto &entity : entities_vector)
    {
        entity->drawWindow(window);
    }
}
