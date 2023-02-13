#ifndef GAMEHANDLING_H
#define GAMEHANDLING_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameHandling : sf::Sprite {

public:
    sf::Texture textureInitialization();
    void eventHandling(sf::Event &event);

};

#endif // GAMEHANDLING_H
