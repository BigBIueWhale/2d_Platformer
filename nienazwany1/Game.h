#ifndef GAME_H
#define GAME_H

#include "WindowHandler.h"
#include "Player.h"
class Game : public WindowHandler
{

private:
    virtual void dynamicMenu(sf::RenderWindow &window) override{;};

    std::vector<std::unique_ptr<Entity>> entities_vector;

public:
    Game();
    virtual void drawWindow(sf::RenderWindow &window) override;
    virtual std::string eventHandling(sf::RenderWindow &window) override;
};




#endif // GAME_H
