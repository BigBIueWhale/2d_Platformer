#include "MainMenu.h"



//#########################################################################################################################################
//#########################################################################################################################################

MainMenu::MainMenu(sf::RenderWindow &window)
{
    // IN: Rendered window;
    // RESULT:  Displaying graphic content of buttons "Play", "Bestscore", "Settings" and "Exit", setting positions; Music initialization

    // PLAY BUTTON
    play_texture_.loadFromFile("textures\\play.png");
    play_sprite_.setTexture(play_texture_);
    play_sprite_.setOrigin(play_sprite_.getGlobalBounds().left + play_sprite_.getGlobalBounds().width/2, play_sprite_.getGlobalBounds().top + play_sprite_.getGlobalBounds().height/2);
    play_sprite_.setPosition(window.getSize().x/2 , play_sprite_.getGlobalBounds().height + 100);
    play_sprite_.setScale(1.0,1.0);

    // BEST_SCORES BUTTON
    bestscore_texture_.loadFromFile("textures\\bestscore.png");
    bestscore_sprite_.setTexture(bestscore_texture_);
    bestscore_sprite_.setOrigin(bestscore_sprite_.getGlobalBounds().left + bestscore_sprite_.getGlobalBounds().width/2, bestscore_sprite_.getGlobalBounds().top + bestscore_sprite_.getGlobalBounds().height/2);
    bestscore_sprite_.setPosition(window.getSize().x/2, play_sprite_.getGlobalBounds().height + play_sprite_.getGlobalBounds().top + 80);
    //bestscores_sprite_.setScale(1.1, 1.1);

    // SETTINGS BUTTON
    settings_texture_.loadFromFile("textures\\settings.png");
    settings_sprite_.setTexture(settings_texture_);
    settings_sprite_.setOrigin(settings_sprite_.getGlobalBounds().left + settings_sprite_.getGlobalBounds().width/2, settings_sprite_.getGlobalBounds().top + settings_sprite_.getGlobalBounds().height/2);
    settings_sprite_.setPosition(window.getSize().x/2, bestscore_sprite_.getGlobalBounds().height + bestscore_sprite_.getGlobalBounds().top + 70);
    //settings_sprite_.setScale(1.1, 1.1);

    // EXIT BUTTON
    exit_texture_.loadFromFile("textures\\exit.png");
    exit_sprite_.setTexture(exit_texture_);
    exit_sprite_.setOrigin(exit_sprite_.getGlobalBounds().left + exit_sprite_.getGlobalBounds().width/2, exit_sprite_.getGlobalBounds().top + exit_sprite_.getGlobalBounds().height/2);
    exit_sprite_.setPosition(window.getSize().x/2, settings_sprite_.getGlobalBounds().height + settings_sprite_.getGlobalBounds().top + 70);
    //exit_sprite_.setScale(1.1, 1.1);



}
//#########################################################################################################################################
//#########################################################################################################################################

void MainMenu::drawWindow(sf::RenderWindow &window)
{
    // IN: Rendered window;
    // RESULT: Draw graphic content on the provided window and execution of dynaminMenu() function;

        dynamicMenu(window);

        window.draw(play_sprite_);
        window.draw(bestscore_sprite_);
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
       sf::FloatRect bestscores_bounds = bestscore_sprite_.getGlobalBounds();
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

void MainMenu::playSoundOnChange(std::string &detection)
{

    //IN: detected name of object that contains mouse
    //RESULT: play sound once when cursor contains button
    if (detection != tmp1)
    {
        tmp1 = "";
        soundPlayed = false;
        changeoption_sound.stop();
    }
    if (detection != "" && tmp1 != detection)
    {
        if (!soundPlayed)
        {
            changeoption_sound.play();
            soundPlayed = true;
        }
        tmp1 = detection;
    }
}


//#########################################################################################################################################
//#########################################################################################################################################

void MainMenu::dynamicMenu(sf::RenderWindow &window)
{
    //IN: Rendered window;
    //RESULT: Changed scale of menu button while mouse cursor is within their boundaries;

 std::string button = detectButtonContainsMouse(window);


 play_sprite_.setScale(1.5,1.5);
 bestscore_sprite_.setScale(1.1, 1.1);
 settings_sprite_.setScale(1.1, 1.1);
 exit_sprite_.setScale(1.1, 1.1);

playSoundOnChange(button);

 if(button == "play"){
     play_sprite_.setScale(1.56, 1.56);
 } else if(button == "bestscores"){
     bestscore_sprite_.setScale(1.11,1.11);
 } else if(button == "settings"){
     settings_sprite_.setScale(1.11,1.11);
 } else if(button == "exit"){
     exit_sprite_.setScale(1.11,1.115);
 }
}

//#########################################################################################################################################
//#########################################################################################################################################

std::string MainMenu::eventHandling(sf::RenderWindow &window)
{
    //IN:  window;
    //RESULT: Event handling regarding menu (clicking buttons: play, score board, settings, exit);
    //RETURN: "play_clicked", "bestscore_clicked", "settings_clicked"
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
           std::string name_of_clicked_button = detectButtonContainsMouse(window);

           if(name_of_clicked_button == "play"){
                //EVENT FOR PLAY
                chooseoption_sound.play();
                return "play_clicked";
           }
           else if(name_of_clicked_button == "bestscores"){
               //EVENT FOR BESTSCORES
               chooseoption_sound.play();
               Sleep(240);
               return "bestscore_clicked";
           }
           else if(name_of_clicked_button == "settings"){
               //EVENT FOR SETTINGS
               chooseoption_sound.play();
               Sleep(240);
               return "settings_clicked";

           }
           else if(name_of_clicked_button == "exit"){
               //EVENT FOR EXIT
               chooseoption_sound.play();
               Sleep(900);
               window.close();
          }

    }
    return "";
}



