#ifndef LEVELS_H
#define LEVELS_H

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>

#include <vector>

class Levels : public sf::Sprite {

private:
    int number_of_levels = 0; // number of levels available counted by countLevels(function)
    int chosen_level; //lvl selected by the player by clicking on it

    sf::Sprite level_sprite_; // lvl square sprite and texture
    sf::Texture level_texture_;//

    void countLevels(); // counting lvls available

public:
    Levels();

    void drawLevels(sf::RenderWindow &window); // draw levels


};

inline void Levels::drawLevels(sf::RenderWindow &window)
{

}



#endif // LEVELS_H
