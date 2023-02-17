#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>

class MainMenu : public sf::Sprite {
private:
    //#### INITIALIZATION OF TEXTURES AND MUSIC #####
    sf::Sprite play_sprite_;
    sf::Texture play_texture_;

    sf::Sprite bestscore_sprite_;
    sf::Texture bestscore_texture_;

    sf::Sprite settings_sprite_;
    sf::Texture settings_texture_;

    sf::Sprite exit_sprite_;
    sf::Texture exit_texture_;

    sf::Music changeoption_sound;
    sf::Music chooseoption_sound;


    std::string tmp1 = "";
        bool soundPlayed = false;


    //#### FUNCTIONS ####
    void dynamicMenu(sf::RenderWindow &window);
    void playSoundOnChange(std::string &detection);

public:
    //#### VARIABLES ####
    std::string what_button_clicked;

    //#### FUNCTIONS ####
    MainMenu();
    MainMenu(sf::RenderWindow &window);
    void drawMenu(sf::RenderWindow &window);
    std::string detectButtonContainsMouse(sf::RenderWindow &window);
    std::string eventHandling(sf::RenderWindow &window);

};



#endif // MAINMENU_H
