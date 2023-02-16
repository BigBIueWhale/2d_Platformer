#include<iostream>
#include<SFML/Graphics.hpp>
#include "MainMenu.h"

int main()
{

    //################################### OBJECTS INICJALIZATION #########################################
    sf::Event event;

    sf::RenderWindow _window;
    _window.create(sf::VideoMode(1280,720), "test", sf::Style::None);
    _window.setVerticalSyncEnabled(true); // synchronization with frequency of the monitor

    MainMenu mainmenu(_window);

    //#########################################################################################################

    while(_window.isOpen()){
        _window.display();

        //############################# EVENTS ######################################
        while(_window.pollEvent(event)){
            if(event.key.code == sf::Keyboard::Space)
                _window.close();

            mainmenu.eventHandling(_window);
        }
        //###############################################################################


        //############################ DRAW WINDOW ######################################
        _window.clear();

        mainmenu.drawMenu(_window);


      //######################################################
        sf::sleep(sf::microseconds(16667)); // 60fps
    }





    return 0;
}
