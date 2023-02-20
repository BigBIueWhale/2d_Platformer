#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>

#include<WindowHandler.h>

class MainMenu : public WindowHandler {
private:
    //#### INITIALIZATION OF TEXTURES #####
    sf::Sprite play_sprite_;
    sf::Texture play_texture_;

    sf::Sprite bestscore_sprite_;
    sf::Texture bestscore_texture_;

    sf::Sprite settings_sprite_;
    sf::Texture settings_texture_;

    sf::Sprite exit_sprite_;
    sf::Texture exit_texture_;



    //#### FUNCTIONS ####
    virtual void dynamicMenu(sf::RenderWindow &window) override;
public:
    //#### FUNCTIONS ####
    MainMenu(sf::RenderWindow &window);
    std::string detectButtonContainsMouse(sf::RenderWindow &window);

    virtual void drawWindow(sf::RenderWindow &window) override;
    virtual std::string eventHandling(sf::RenderWindow &window) override;

};



#endif // MAINMENU_H
