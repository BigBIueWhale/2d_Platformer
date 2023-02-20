#include "Levels.h"
#include <synchapi.h>

Levels::Levels(sf::RenderWindow &window)
{
    //LEVEL SQUARE
    level_texture_.loadFromFile("textures\\level.png");
    level_sprite_.setTexture(level_texture_);
    level_sprite_.setScale(0.96,0.96); //shoulde be after setOrigin();
    level_sprite_.setOrigin(level_sprite_.getGlobalBounds().left + level_sprite_.getGlobalBounds().width/2, level_sprite_.getGlobalBounds().top + level_sprite_.getGlobalBounds().height/2);

    //"LEVELS"
    levels_texture_.loadFromFile("textures\\levels.png");
    levels_sprite_.setTexture(levels_texture_);
    levels_sprite_.setOrigin((levels_sprite_.getGlobalBounds().left + levels_sprite_.getGlobalBounds().width)/2, levels_sprite_.getGlobalBounds().top + levels_sprite_.getGlobalBounds().height/2);
    levels_sprite_.setScale(0.7,0.7);
    levels_sprite_.setPosition(window.getSize().x/2, levels_sprite_.getGlobalBounds().height/2);

    //"BACK"
    back_texture_.loadFromFile("textures\\back.png");
    back_sprite_.setTexture(back_texture_);
    back_sprite_.setOrigin((back_sprite_.getGlobalBounds().left + back_sprite_.getGlobalBounds().width)/2, back_sprite_.getGlobalBounds().top + back_sprite_.getGlobalBounds().height/2);
    back_sprite_.setScale(0.4,0.4);
    back_sprite_.setPosition(back_sprite_.getGlobalBounds().width/2 + 35, window.getSize().y - back_sprite_.getGlobalBounds().height/2 -20);

    //"GO"
    go_texture_.loadFromFile("textures\\go.png");
    go_sprite_.setTexture(go_texture_);
    go_sprite_.setOrigin((go_sprite_.getGlobalBounds().left + go_sprite_.getGlobalBounds().width)/2, go_sprite_.getGlobalBounds().top + go_sprite_.getGlobalBounds().height/2);
    go_sprite_.setScale(0.6,0.6);
    go_sprite_.setPosition(window.getSize().x - go_sprite_.getGlobalBounds().width/2 - 35, window.getSize().y-  go_sprite_.getGlobalBounds().height/2 - 10);


    //FONT
    font_.loadFromFile("fonts\\Final_Fantasy_Tactics_Regular.ttf");



    //FUNCTIONS
    countLevels();
    setTextAndSprites(window);
}

void Levels::setTextAndSprites(sf::RenderWindow &window)
{
    float levels_in_row=8.0;
    float division = number_of_levels/levels_in_row;
    int margin_between_levels=110;

    if (division <= 1.0)
    {
        for(int i=1; i<=number_of_levels; i++)
        {
            level_sprite_.setPosition(180*i,100);
            levels_vector.emplace_back(level_sprite_);
        }
    }
    else if(division >1.0)
    {
        int number_of_rows = static_cast<int>(floor(division)) + 1;
        int x_position = (window.getSize().x - (levels_in_row*(level_sprite_.getGlobalBounds().width) + (levels_in_row-1)*(margin_between_levels-level_sprite_.getGlobalBounds().width)))/2;

        for (int i = 1; i <number_of_rows+1; i++)
        {
            for (int j = 1; j < levels_in_row+1; j++)
            {
                //#### SPRITE
                if(j-1==(number_of_levels-levels_in_row*(number_of_rows-1)) && i == number_of_rows)
                    break;


                level_sprite_.setPosition( x_position + (j-1)* margin_between_levels + level_sprite_.getGlobalBounds().width/2 , margin_between_levels*i + 100);
                levels_vector.emplace_back(level_sprite_);


                //#### TEXT
                text_.setFont(font_);
                if(levels_vector.size() < 10)
                {
                  text_.setCharacterSize(130);
                }
                else
                {
                    text_.setCharacterSize(120);
                }


                sf::FloatRect textBounds = text_.getLocalBounds();

                sf::Vector2f textCenter(textBounds.width / 2.0f, textBounds.height / 2.0f);
                text_.setString(std::to_string(levels_vector.size()));

                text_.setOrigin(text_.getLocalBounds().width / 2, text_.getLocalBounds().height / 2);

                if(levels_vector.size() < 10)
                {
                   text_.setPosition(x_position + (j-1)* margin_between_levels + level_sprite_.getGlobalBounds().width/2 + 4 , margin_between_levels*(i-1)+23 + 100);
                }
                else
                {
                     text_.setPosition(x_position + (j-1)* margin_between_levels + level_sprite_.getGlobalBounds().width/2 + 3 , margin_between_levels*(i-1)+31 + 100);
                }
                numbers_vector.emplace_back(text_);
            }
        }
    }


}




void Levels::drawWindow(sf::RenderWindow &window)
{
    dynamicMenu(window);
    window.draw(levels_sprite_);
    window.draw(go_sprite_);
    window.draw(back_sprite_);

    for(sf::Sprite &el : levels_vector)
    {
        window.draw(el);
    }
    for(sf::Text &el : numbers_vector)
    {
        window.draw(el);
    }
}


void Levels::countLevels()
{

    DIR *dp;
      struct dirent *ep;
      dp = opendir ("levels\\");

      if (dp != NULL)
      {
        while (ep = readdir(dp))
          number_of_levels++;

        (void) closedir(dp);
      }
      else
        perror ("Couldn't open the directory");


      number_of_levels = number_of_levels - 2;

}
std::string Levels::detectButtonContainsMouse(sf::RenderWindow &window)
{
    sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    sf::FloatRect go_bounds = go_sprite_.getGlobalBounds();
    sf::FloatRect back_bounds = back_sprite_.getGlobalBounds();



    if(go_bounds.contains(mouse_pos))
    {
        return "go_clicked";
    }
    else if(back_bounds.contains(mouse_pos))
    {
        return "back_clicked";
    }
    else
    {
        int i = 0;
        for(sf::Sprite &el : levels_vector)
        {
            if(el.getGlobalBounds().contains(mouse_pos))
            {
                return std::to_string(i);
            }
            i++;
        }
    }
    return "";
}

std::string Levels::eventHandling(sf::RenderWindow &window)
{
    //IN:  window;
    //RESULT: Event handling regarding menu (clicking buttons: back, go, level choosing);
    //RETURN: "back_clicked", "go_clicked", "level_clicked"
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
           std::string name_of_clicked_button = detectButtonContainsMouse(window);

           if(name_of_clicked_button == "go_clicked"){
                //EVENT FOR GO
                chooseoption_sound.play();
                return "go_clicked";
           }
           else if(name_of_clicked_button == "back_clicked"){
               //EVENT FOR BESTSCORES
               chooseoption_sound.play();
               return "back_clicked";
           }

    }
    return "";
}
void Levels::dynamicMenu(sf::RenderWindow &window)
{
    //IN: Rendered window;
    //RESULT: Changed scale of menu button while mouse cursor is within their boundaries;

 std::string button = detectButtonContainsMouse(window);


 go_sprite_.setScale(0.6,0.6);
 back_sprite_.setScale(0.4, 0.4);
 for(sf::Sprite &el : levels_vector)
 {
         el.setScale(0.75,0.75);
 }


playSoundOnChange(button);

 if(button == "go_clicked"){
     go_sprite_.setScale(0.7, 0.7);
 } else if(button == "back_clicked"){
     back_sprite_.setScale(0.48,0.48);
 } else
 {
     int i=0;
     for(sf::Sprite &el : levels_vector)
     {
         if(button == std::to_string(i))
         {
             el.setScale(1,1);
         }
             i++;
     }
 }

}

