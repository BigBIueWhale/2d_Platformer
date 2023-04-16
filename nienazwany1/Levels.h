#ifndef LEVELS_H
#define LEVELS_H

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>



#include <vector>
#include <WindowHandler.h>
#include <XmlHandler.h>

class Levels : public WindowHandler {

private:
    XmlHandler xml_handler;
    float number_of_levels = 0; // number of levels available counted by countLevels(function) //lvl selected by the player by clicking on it
    int what_level_chosen = -1;

    sf::Sprite level_sprite_; // lvl square sprite
    sf::Texture level_texture_;// lvl square texture

    sf::Sprite level_green_sprite_; // lvl square sprite
    sf::Texture level_green_texture_;// lvl square texture

    sf::Sprite levels_sprite_; // "Levels"
    sf::Texture levels_texture_;// "Levels"



    sf::Sprite back_sprite_; // "Back"
    sf::Texture back_texture_; // "Back"

    sf::Sprite go_sprite_; // "Go"
    sf::Texture go_texture_; // "Go"

    sf::Text text_;
    sf::Font font_;



    void countLevels(); // counting lvls available
    std::vector<sf::Sprite> levels_vector; //2d vector used to draw table of evailable levels
    std::vector<sf::Text> numbers_vector;

    void setTextAndSprites(sf::RenderWindow &window);
    virtual void dynamicMenu(sf::RenderWindow &window) override;

public:

    Levels(sf::RenderWindow &window);
    ~Levels();

    std::string detectButtonContainsMouse(sf::RenderWindow &window);

    virtual void drawWindow(sf::RenderWindow &window) override; // draw levels
    virtual std::string eventHandling(sf::RenderWindow &window) override;
};




#endif // LEVELS_H
