#include<iostream>
#include<SFML/Graphics.hpp>
#include "MainMenu.h"

int main()
{

    //################################## TEXTURES ################################################
    sf::Texture play;
    if (!play.loadFromFile("textures\\play.png")) {
        std::cout << "Could not load texture play.png" << std::endl;
        return 1;
    }
    sf::Texture bestscores;
    if (!bestscores.loadFromFile("textures\\bestscores.png")) {
        std::cout << "Could not load texture bestscores.png" << std::endl;
        return 1;
    }
    sf::Texture settings;
    if (!settings.loadFromFile("textures\\settings.png")) {
        std::cout << "Could not load texture settings.png" << std::endl;
        return 1;
    }
    sf::Texture exit;
    if (!exit.loadFromFile("textures\\exit.png")) {
        std::cout << "Could not load texture exit.png" << std::endl;
        return 1;
    }

    //###############################################################################################

    //################################### OBJECTS INICJALIZATION #########################################
    sf::Event event;
    sf::RenderWindow _window;
    _window.create(sf::VideoMode(1280,720), "test", sf::Style::None);

    MainMenu mainmenu(play, bestscores, settings, exit, _window);

    //#########################################################################################################

    while(_window.isOpen()){
        _window.display();

        //############################# EVENTS ######################################
        while(_window.pollEvent(event)){
            if(event.key.code == sf::Keyboard::Space)
                _window.close();


            mainmenu.eventHandling(event,_window);
        }
        //############################################################################



        mainmenu.drawMenu(_window);
    }





    return 0;
}
