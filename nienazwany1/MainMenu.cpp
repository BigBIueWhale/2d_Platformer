#include "MainMenu.h"
#include<windows.h>

//#########################################################################################################################################
//#########################################################################################################################################

MainMenu::MainMenu(sf::Texture &play_texture,sf::Texture &bestscores_texture, sf::Texture &settings_texture, sf::Texture &exit_texture, sf::RenderWindow &window)
{
    // IN: Graphic content of: "Play", "Bestscore", "Settings" and "Exit" buttons + rendered window;
    // RESULT:  Displaying graphic content of these buttons, setting positions and scales;

    // PLAY BUTTON
    play_texture_ = play_texture;
    play_sprite_.setTexture(play_texture_);
    play_sprite_.setOrigin(play_sprite_.getGlobalBounds().left + play_sprite_.getGlobalBounds().width/2, play_sprite_.getGlobalBounds().top + play_sprite_.getGlobalBounds().height/2);
    play_sprite_.setPosition(window.getSize().x/2 , play_sprite_.getGlobalBounds().height + 100);
    play_sprite_.setScale(1.0,1.0);

    // BEST_SCORES BUTTON
    bestscores_texture_ = bestscores_texture;
    bestscores_sprite_.setTexture(bestscores_texture);
    bestscores_sprite_.setOrigin(bestscores_sprite_.getGlobalBounds().left + bestscores_sprite_.getGlobalBounds().width/2, bestscores_sprite_.getGlobalBounds().top + bestscores_sprite_.getGlobalBounds().height/2);
    bestscores_sprite_.setPosition(window.getSize().x/2, play_sprite_.getGlobalBounds().height + play_sprite_.getGlobalBounds().top + 77);
    //bestscores_sprite_.setScale(1.1, 1.1);

    // SETTINGS BUTTON
    settings_texture_ = settings_texture;
    settings_sprite_.setTexture(settings_texture);
    settings_sprite_.setOrigin(settings_sprite_.getGlobalBounds().left + settings_sprite_.getGlobalBounds().width/2, settings_sprite_.getGlobalBounds().top + settings_sprite_.getGlobalBounds().height/2);
    settings_sprite_.setPosition(window.getSize().x/2, bestscores_sprite_.getGlobalBounds().height + bestscores_sprite_.getGlobalBounds().top + 70);
    //settings_sprite_.setScale(1.1, 1.1);

    // EXIT BUTTON
    exit_texture_ = exit_texture;
    exit_sprite_.setTexture(exit_texture);
    exit_sprite_.setOrigin(exit_sprite_.getGlobalBounds().left + exit_sprite_.getGlobalBounds().width/2, exit_sprite_.getGlobalBounds().top + exit_sprite_.getGlobalBounds().height/2);
    exit_sprite_.setPosition(window.getSize().x/2, settings_sprite_.getGlobalBounds().height + settings_sprite_.getGlobalBounds().top + 70);
    //exit_sprite_.setScale(1.1, 1.1);

}
//#########################################################################################################################################
//#########################################################################################################################################

void MainMenu::drawMenu(sf::RenderWindow &window)
{
    // IN: Rendered window;
    // RESULT: Draw graphic content on the provided window;

    scaleButtonWhenContainsMouse(window);

     window.draw(play_sprite_);
     window.draw(bestscores_sprite_);
     window.draw(settings_sprite_);
     window.draw(exit_sprite_);

}

//#########################################################################################################################################
//#########################################################################################################################################

std::string MainMenu::detectButtonContainsMouse(sf::RenderWindow &window)
{

    //IN: Rendered window;
    //RETURN: string - "play", "bestscores", "settings", "exit", "" -- when mouse cursor contains according button;
       sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

       sf::FloatRect play_bounds = play_sprite_.getGlobalBounds();
       sf::FloatRect bestscores_bounds = bestscores_sprite_.getGlobalBounds();
       sf::FloatRect settings_bounds = settings_sprite_.getGlobalBounds();
       sf::FloatRect exit_bounds = exit_sprite_.getGlobalBounds();


       if(play_bounds.contains(mouse_pos))
       {
           return "play";
       }
       else if(bestscores_bounds.contains(mouse_pos))
       {
           return "bestscores";
       }
       else if(settings_bounds.contains(mouse_pos))
       {
           return "settings";
       }
       else if(exit_bounds.contains(mouse_pos))
       {
           return "exit";
       }
       else
       {
        return "";
       }
}

//#########################################################################################################################################
//#########################################################################################################################################

void MainMenu::scaleButtonWhenContainsMouse(sf::RenderWindow &window)
{
    //IN: Rendered window;
    //RESULT: Changed scale of menu button while mouse cursor is within their boundaries;

 std::string button = detectButtonContainsMouse(window);

 play_sprite_.setScale(1.5,1.5);
 bestscores_sprite_.setScale(1.1, 1.1);
 settings_sprite_.setScale(1.1, 1.1);
 exit_sprite_.setScale(1.1, 1.1);

 if(button == "play"){
     play_sprite_.setScale(1.56, 1.56);
 } else if(button == "bestscores"){
     bestscores_sprite_.setScale(1.11,1.11);
 } else if(button == "settings"){
     settings_sprite_.setScale(1.11,1.11);
 } else if(button == "exit"){
     exit_sprite_.setScale(1.11,1.115);
 }
}

//#########################################################################################################################################
//#########################################################################################################################################

void MainMenu::eventHandling(sf::Event &event, sf::RenderWindow &window)
{
    //IN: event, window;
    //RESULT: Event handling regarding menu (clicking buttons: play, score board, settings, exit);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
           std::string name_of_clicked_button = detectButtonContainsMouse(window);

           if(name_of_clicked_button == "exit"){
                Sleep(230);
                window.close();
           }
    }
}



