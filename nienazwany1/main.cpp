#include<iostream>
#include<SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Levels.h"


int main()
{

    //################################### OBJECTS INITIALIZATION #########################################
    sf::Event event;

    sf::RenderWindow _window;
    _window.create(sf::VideoMode(1280,720), "Bloody game", sf::Style::None);
    _window.setVerticalSyncEnabled(true); // synchronization with frequency of the monitor


    WindowHandler *windowhandler;
    windowhandler = new MainMenu(_window);


    //--------------------------------------------------------------------------------------------------------



    while(_window.isOpen()){
        _window.display();
        //###########################################################################
        //############################# EVENTS ######################################

        while(_window.pollEvent(event)){
            if(event.key.code == sf::Keyboard::Space)
            {
                _window.close();
            }
            windowhandler->rememberClickedButton(windowhandler->eventHandling(_window));

        }

        //################################################################################
        //############################ DRAW WINDOW ######################################
        _window.clear();
        windowhandler->drawWindow(_window);
        sf::sleep(sf::microseconds(16667)); // 60fps


        //###############################################################################
        //############## CHANGE POINTER VALUE WHEN OTHER BUTTONS CLICKED ################

       if(windowhandler->what_button_clicked == "play_clicked")
       {
            Sleep(172);
            delete windowhandler;
            windowhandler = new Levels(_window);
       }
       else if(windowhandler->what_button_clicked == "back_clicked")
       {
           Sleep(172);
           delete windowhandler;
           windowhandler = new MainMenu(_window);
       }






    }



    delete windowhandler;
    return 0;
}
