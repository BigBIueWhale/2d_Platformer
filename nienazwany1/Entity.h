#ifndef ENTITY_H
#define ENTITY_H
#pragma once
#endif // ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



class Entity : public sf::Sprite
{
protected:
    int x_pos;
    int y_pos;


    void readInfoFromFile(std::string &what_level);
public:
    virtual sf::Sprite setSprite(sf::Sprite &player_sprite, sf::Texture &player_texture){;};
    virtual void drawWindow(sf::RenderWindow &window) const=0;
    virtual void animate(){;};

};
