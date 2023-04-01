#include "Game.h"
#include "map.h"
#include <iostream>
Game::Game()
{
    entities_vector.push_back(std::make_unique<Map>());
    entities_vector.push_back(std::make_unique<Player>());

    player = dynamic_cast<Player*>(entities_vector[1].get());
    map = dynamic_cast<Map*>(entities_vector[0].get());

}


std::string Game::eventHandling(sf::RenderWindow &window)
{
    //MOVE/ANIMATIONS FUNCTIONS
    player->move();


   //###########VALUE GETTERS
    //MAP
   walls_vector = map->getWalls();
   spikes_vector = map->getSpikes();
    //PLAYER
   player_bounds = player->getBounds();
   player_velocities = player->getVelocity();

   //Collision detection:
    player_next_pos = player_bounds;

//###########################################################################################################
//###### MOVE LEFT AND RIGHT + COLLISIONS

player->setBoolRightMove(0);
player->setBoolLeftMove(0);
player->setCancelJump(0);

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (player_bounds.left+player_bounds.width + 2) < window.getSize().x)
{
    player->setBoolRightMove(1);
    player_next_pos.left +=2;

    for(auto &el : walls_vector)
    {
        if(el.getGlobalBounds().intersects(player_next_pos))
        {
            player->setBoolRightMove(0);
            break;
        }
    }
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (player_bounds.left - 2) > 0)
{
    player->setBoolLeftMove(1);
    player_next_pos.left -=4;

    for(auto &el : walls_vector)
    {
        if(el.getGlobalBounds().intersects(player_next_pos))
        {
            player->setBoolLeftMove(0);
            break;
        }
    }
}


//########################################
//##########JUMPS AND GRAVITY + COLLISIONS

//GRAVITY

player_next_pos.height += 7; // prevent sprite from sticking to the ground
player_next_pos.left += 2; // prevent sprite from sticking to the wall while falling
player_next_pos.width -= +4 ; // prevent sprite from sticking to the wall while falling

player->setBoolGravitation(1);
for(auto &el : walls_vector)
{
    if(el.getGlobalBounds().intersects(player_next_pos))
    {
        player->setBoolGravitation(0);
        player->setBoolJump(0);
        break;
    }
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
{
    for(auto &el : walls_vector)
    {
        if(el.getGlobalBounds().intersects(player_next_pos))
        {
            player->setBoolJump(1);
            space_clicked = 1;
            break;
        }
    }
}

player_bounds.top -= 10;
player_bounds.left += 2;
player_bounds.width -= 4;

for(auto &el : walls_vector)
{
    walls = el.getGlobalBounds();
    walls.top +=5;
    if(walls.intersects(player_bounds))
    {
        player->setCancelJump(1);
        break;
    }
}


//##########################################

return "";
}

void Game::drawWindow(sf::RenderWindow &window)
{
    for (const auto &entity : entities_vector)
    {
        entity->drawWindow(window);
    }
}
