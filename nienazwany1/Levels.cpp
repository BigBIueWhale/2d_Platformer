#include "Levels.h"
#include <synchapi.h>


//#########################################################################################################################################
//#########################################################################################################################################

Levels::Levels(sf::RenderWindow &window)
{
    // IN: Rendered window;
    // RESULT:  Initialization of graphic content of buttons "Go", "Back"; Red and Green square textures along with font initialization
    //          to represent levels; Initialization of CountLevels() and setTextAndSprites(window).


    //LEVEL SQUARE
        //RED
    level_texture_.loadFromFile("textures\\level.png");
    level_sprite_.setTexture(level_texture_);
    level_sprite_.setScale(0.96,0.96); //shoulde be after setOrigin();
    level_sprite_.setOrigin(level_sprite_.getGlobalBounds().left + level_sprite_.getGlobalBounds().width/2, level_sprite_.getGlobalBounds().top + level_sprite_.getGlobalBounds().height/2);
        //GREEN
    level_green_texture_.loadFromFile("textures\\level_green.png");
    level_green_sprite_.setTexture(level_green_texture_);
    level_green_sprite_.setScale(0.96,0.96); //shoulde be after setOrigin();
    level_green_sprite_.setOrigin(level_green_sprite_.getGlobalBounds().left + level_green_sprite_.getGlobalBounds().width/2, level_green_sprite_.getGlobalBounds().top + level_green_sprite_.getGlobalBounds().height/2);


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

//#########################################################################################################################################
//#########################################################################################################################################


Levels::~Levels()
{
    //RESULT: saves variable indicating chosen level by the player to the .txt file
    std::ofstream file("levelsinfo\\level_name.txt");

    file.clear();
    file.seekp(0);
    file << (chosen_level+1);

    file.close();
}


//#########################################################################################################################################
//#########################################################################################################################################




void Levels::setTextAndSprites(sf::RenderWindow &window)
{
    //IN: Rendered window;
    //RESULT: Initialization of 2 vectors with sprite and text: levels_vector and numbers_vector - containing sf::Sprite's and sf::Text's
    //        used to draw the table of levels drawn at the level choice window. Adding new levels is easier becouse levels in level choice
    //        screen are drawn automaticly after adding new file to "levels/" directory.
    //        To draw more levels in one row change LEVELS_IN_ROW variable,
    //        To change margins between squares modify variable MARGIN_BETWEEN_LEVELS.

    const float levels_in_row = 8.0;
    const int margin_between_levels = 110;
    float division = number_of_levels/levels_in_row;


    if (division <= 1.0)
    {
        //TO FINISH IN THE FUTURE THIS IF STATEMT DOESNT WORK PROPERLY FOR NUMBER_OF_LEVELS < LEVELS_IN_ROW;

        for(int i=1; i<=number_of_levels; i++)
        {
            level_sprite_.setPosition(180*i,100);
            levels_vector.emplace_back(level_sprite_);
        }
    }
    else if(division >1.0)
    {
       const int number_of_rows = static_cast<int>(floor(division)) + 1;

       //x_position - variable used to center LEVELS_IN_ROW squares
       const int x_position = (window.getSize().x - (levels_in_row*(level_sprite_.getGlobalBounds().width) + (levels_in_row-1)*(margin_between_levels-level_sprite_.getGlobalBounds().width)))/2;

        for (int i = 1; i <number_of_rows+1; i++)
        {
            for (int j = 1; j < levels_in_row+1; j++)
            {
                //#### SPRITE
                if(j-1==(number_of_levels - levels_in_row*(number_of_rows - 1)) && i == number_of_rows)
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


               const sf::FloatRect textBounds = text_.getLocalBounds();
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


//#########################################################################################################################################
//#########################################################################################################################################




void Levels::drawWindow(sf::RenderWindow &window)
{
    // IN: Rendered window;
    // RESULT: Draw graphic content in the provided window and initialization of dynaminMenu() function;
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


//#########################################################################################################################################
//#########################################################################################################################################


void Levels::countLevels()
{
    //RESULT: Number of files in "levels/" directory set to NUMBER_OF_LEVELS variable;

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


//#########################################################################################################################################
//#########################################################################################################################################


std::string Levels::detectButtonContainsMouse(sf::RenderWindow &window)
{
    //IN: Rendered window;
    //RESULT: Returns the information within whitch texture mouse is at the moment.
    //RETURN: "go", "back" or number of level (i);
   const sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

   const sf::FloatRect go_bounds = go_sprite_.getGlobalBounds();
   const sf::FloatRect back_bounds = back_sprite_.getGlobalBounds();



    if(go_bounds.contains(mouse_pos))
    {
        return "go";
    }
    else if(back_bounds.contains(mouse_pos))
    {
        return "back";
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


//#########################################################################################################################################
//#########################################################################################################################################


std::string Levels::eventHandling(sf::RenderWindow &window)
{
    //IN:  window;
    //RESULT: Event handling regarding levels choice (clicking buttons: back, go, level choosing);
    //        when level chosen it changes texture color to green.
    //RETURN: "back", "go", "";
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
           std::string name_of_clicked_button = detectButtonContainsMouse(window);

           if(name_of_clicked_button == "go"){
                //EVENT FOR GO
                chooseoption_sound.play();
                return "go_clicked";
           }
           else if(name_of_clicked_button == "back"){
               //EVENT FOR BESTSCORES
               chooseoption_sound.play();
               return "back_clicked";
           }
           else if(std::isdigit(name_of_clicked_button[0]))
           {
               //EVENT FOR LEVEL SELECT
               chooseoption_sound.play();

               chosen_level = std::stoi(name_of_clicked_button);
               const sf::Sprite tmp_sprite = levels_vector[chosen_level];

               if(what_level_chosen == -1)
               {
                //delete red texture, replace with green texture;
                level_green_sprite_.setPosition(tmp_sprite.getGlobalBounds().left + tmp_sprite.getGlobalBounds().width/2, tmp_sprite.getGlobalBounds().top + tmp_sprite.getGlobalBounds().height/2);
                levels_vector.erase(levels_vector.begin()+ chosen_level);
                levels_vector.insert(levels_vector.begin() + chosen_level,level_green_sprite_);

                what_level_chosen = chosen_level;
               }
               else if(chosen_level != what_level_chosen)
               {
                   //delete green texture, replace with red texture;
                   level_sprite_.setPosition(levels_vector[what_level_chosen].getGlobalBounds().left + levels_vector[what_level_chosen].getGlobalBounds().width/2 -2, levels_vector[what_level_chosen].getGlobalBounds().top + levels_vector[what_level_chosen].getGlobalBounds().height/2 -3);
                   levels_vector.erase(levels_vector.begin()+ what_level_chosen);
                   levels_vector.insert(levels_vector.begin() + what_level_chosen,level_sprite_);

                   //delete red texture, replace with green texture;
                   level_green_sprite_.setPosition(tmp_sprite.getGlobalBounds().left + tmp_sprite.getGlobalBounds().width/2 -2, tmp_sprite.getGlobalBounds().top + tmp_sprite.getGlobalBounds().height/2 -1);
                   levels_vector.erase(levels_vector.begin()+ chosen_level);
                   levels_vector.insert(levels_vector.begin() + chosen_level,level_green_sprite_);

                   what_level_chosen = chosen_level;
               }
           }
    }
    return "";
}


//#########################################################################################################################################
//#########################################################################################################################################


void Levels::dynamicMenu(sf::RenderWindow &window)
{
    //IN: Rendered window;
    //RESULT: Changed scale of levels, "go" and "back" buttons while mouse cursor is within their boundaries;
    //        Initialization of playSoundOnChange(std::string).

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


//#########################################################################################################################################
//#########################################################################################################################################
