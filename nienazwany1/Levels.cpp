#include "Levels.h"

Levels::Levels(sf::RenderWindow &window)
{
    level_texture_.loadFromFile("textures\\level.png");
    level_sprite_.setTexture(level_texture_);
    level_sprite_.setOrigin(level_sprite_.getGlobalBounds().left + level_sprite_.getGlobalBounds().width/2, level_sprite_.getGlobalBounds().top + level_sprite_.getGlobalBounds().height/2);


    font_.loadFromFile("fonts\\Final_Fantasy_Tactics_Regular.ttf");


    countLevels();
    setLevelsVector(window);
}

void Levels::setLevelsVector(sf::RenderWindow &window)
{
    float levels_in_row=6.0;
    float division = number_of_levels/levels_in_row;
    int margin_between_levels=130;

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
                if(j-1==(number_of_levels-levels_in_row*(number_of_rows-1)) && i == number_of_rows)
                    break;


                level_sprite_.setPosition( x_position + (j-1)* margin_between_levels + level_sprite_.getGlobalBounds().width/2 , margin_between_levels*i);
                levels_vector.emplace_back(level_sprite_);



                text_.setFont(font_);
                if(levels_vector.size() < 10)
                {
                  text_.setCharacterSize(180);
                }
                else
                {
                    text_.setCharacterSize(140);
                }


                sf::FloatRect textBounds = text_.getLocalBounds();

                sf::Vector2f textCenter(textBounds.width / 2.0f, textBounds.height / 2.0f);
                text_.setString(std::to_string(levels_vector.size()));

                text_.setOrigin(text_.getLocalBounds().width / 2, text_.getLocalBounds().height / 2);
                std::cout<<text_.getGlobalBounds().left <<", "<< text_.getGlobalBounds().width <<", "<< text_.getGlobalBounds().top <<", "<< text_.getGlobalBounds().height <<std::endl;
                text_.setPosition(x_position + (j-1)* margin_between_levels + level_sprite_.getGlobalBounds().width/2 - textCenter.x , margin_between_levels*i - textCenter.y);

                numbers_vector.emplace_back(text_);




            }
        }
    }


}




void Levels::drawWindow(sf::RenderWindow &window)
{
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
