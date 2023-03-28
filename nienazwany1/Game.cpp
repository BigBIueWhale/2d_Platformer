#include "Game.h"
#include "map.h"

Game::Game()
{
    entities_vector.push_back(std::make_unique<Map>());
    entities_vector.push_back(std::make_unique<Player>());


//    for (const auto &entity : entities_vector)
//    {
//        //entity->setSprite(player_sprite_,player_texture_);
//    }


}
std::string Game::eventHandling(sf::RenderWindow &window)
{

        entities_vector[1]->animate(); //movement of the player



return "";
}

void Game::drawWindow(sf::RenderWindow &window)
{
    for (const auto &entity : entities_vector)
    {
        entity->drawWindow(window);
    }
}
