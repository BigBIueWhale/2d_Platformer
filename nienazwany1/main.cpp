#include<iostream>
#include<SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Levels.h"
int main()
{

    //################################### OBJECTS INICJALIZATION #########################################
    sf::Event event;

    sf::RenderWindow _window;
    _window.create(sf::VideoMode(1280,720), "test", sf::Style::None);
    _window.setVerticalSyncEnabled(true); // synchronization with frequency of the monitor

    MainMenu mainmenu(_window);

    Levels levels;

    //#########################################################################################################

    while(_window.isOpen()){
        _window.display();

        //############################# EVENTS ######################################
        while(_window.pollEvent(event)){
            if(event.key.code == sf::Keyboard::Space)
                _window.close();
            if(mainmenu.what_button_clicked == "")
            mainmenu.what_button_clicked = mainmenu.eventHandling(_window);
        }
        //###############################################################################


        //############################ DRAW WINDOW ######################################
        _window.clear();
        if(mainmenu.what_button_clicked == "")
        {
          mainmenu.drawMenu(_window);
        }
      else if(mainmenu.what_button_clicked == "play_clicked")
        {
            levels.drawLevels(_window);
        }




      //######################################################
        sf::sleep(sf::microseconds(16667)); // 60fps
    }





    return 0;
}
