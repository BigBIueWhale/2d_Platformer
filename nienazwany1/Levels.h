#ifndef LEVELS_H
#define LEVELS_H

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <cmath>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>


#include <vector>
#include <WindowHandler.h>

class Levels : public WindowHandler {

private:
    float number_of_levels = 0; // number of levels available counted by countLevels(function)
    int chosen_level; //lvl selected by the player by clicking on it

    sf::Sprite level_sprite_; // lvl square sprite
    sf::Texture level_texture_;// lvl square texture

    sf::Sprite back_sprite_; // back to main menu sprite
    sf::Texture back_texture_; // back to main menu texture

    sf::Sprite go_sprite_; // go to the game sprite
    sf::Texture go_texture_; //  go to the game texture

    sf::Text text_;
    sf::Font font_;



    void countLevels(); // counting lvls available
    std::vector<sf::Sprite> levels_vector; //2d vector used to draw table of evailable levels
    std::vector<sf::Text> numbers_vector;

    void setLevelsVector(sf::RenderWindow &window);

public:
    Levels(sf::RenderWindow &window);

    virtual void drawWindow(sf::RenderWindow &window); // draw levels
    virtual std::string eventHandling(sf::RenderWindow &window){;};


};




#endif // LEVELS_H
