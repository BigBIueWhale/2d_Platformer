#ifndef GAME_H
#define GAME_H

#include "WindowHandler.h"
#include "Player.h"
#include "map.h"
class Game : public WindowHandler
{

private:
   // sf::View game_view;


    virtual void dynamicMenu(sf::RenderWindow &window) override{;};


    Player* player;
    sf::FloatRect player_bounds;
    sf:: Vector2f player_velocities;

    Map* map;
    std::vector<sf::Sprite> walls_vector;
    std::vector<sf::Sprite> spikes_vector;

    //collisions
    sf::FloatRect player_move_bounds;
    sf::FloatRect player_jump_bounds;
    sf::FloatRect player_cancel_jump_bounds;
    sf::FloatRect walls;


    std::vector<std::unique_ptr<Entity>> entities_vector;


public:
    Game();
    virtual void drawWindow(sf::RenderWindow &window) override;
    virtual std::string eventHandling(sf::RenderWindow &window) override;
};




#endif // GAME_H
