#include "Player.h"



//#########################################################################################################################################
//#########################################################################################################################################

Player::Player()
{
    player_texture_.loadFromFile("textures\\game\\player.png");
    player_sprite_.setTexture(player_texture_);
    player_sprite_.setTextureRect(sf::IntRect(28,16,36,64));
    player_sprite_.setScale(0.7,0.7);
    player_sprite_.setPosition(100,100);
}

//#########################################################################################################################################
//#########################################################################################################################################

sf::Sprite Player::setSprite(sf::Sprite &player_sprite, sf::Texture &player_texture)
{
    player_texture.loadFromFile("textures\\game\\player.png");
    player_sprite.setTexture(player_texture);
    player_sprite.setPosition(100,100);
    return player_sprite;
}


//#########################################################################################################################################
//#########################################################################################################################################
void Player::drawWindow(sf::RenderWindow &window) const
{
    window.draw(player_sprite_);
}


//#########################################################################################################################################
//#########################################################################################################################################

void Player::animate()
{


    //if button not pressed stand on two legs
    player_sprite_.setTextureRect(sf::IntRect(24,16,36,64));
    static bool turned_right = 1;

    //LEFT AND RIGHT MOVEMENT
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        int xTexture = 0;

        xTexture = (int)player_sprite_.getPosition().x/21 %6;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            //RIGHT
            if(!turned_right)
            {
            player_sprite_.setScale(0.7f, 0.7f);
            player_sprite_.move(-player_sprite_.getLocalBounds().width, 0);
            turned_right = 1;
            }
            move_speed = 1000000;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            //LEFT
            if(turned_right)
            {
            player_sprite_.setScale(-0.7f, 0.7f);
            player_sprite_.move(player_sprite_.getLocalBounds().width, 0);
            turned_right = 0;
            }
            move_speed = -1000000;
            xTexture = 5 - xTexture;
        }
        sf::Clock clock_animate;
        switch(xTexture) //animation of walking
        {
        case 0:
            player_sprite_.setTextureRect(sf::IntRect(80,16,36,64));
            break;
        case 1:
            player_sprite_.setTextureRect(sf::IntRect(128,16,36,64));
            break;
        case 2:
            player_sprite_.setTextureRect(sf::IntRect(176,16,36,64));
            break;
        case 3:
            player_sprite_.setTextureRect(sf::IntRect(224,16,36,64));
            break;
        case 4:
            player_sprite_.setTextureRect(sf::IntRect(272,16,36,64));
            break;
        case 5:
            player_sprite_.setTextureRect(sf::IntRect(24,16,36,64));
            break;
        }

        sf::Time elapsed = clock_animate.getElapsedTime();

        player_sprite_.move(10*move_speed * elapsed.asSeconds(), 0);

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        //EVENT WHEN SPACE CLICKED
    }
    
// TO DO: ATTACK, ATTACK WHILE WALKING, ATTACK ON THE LADDER, GRAVITY IMPLEMENTATION, JUMP, LADDER CLIMBING, SMOOTHERING OF WALKING (now charakter does it not fluently (ma) 
    
    


}


//#########################################################################################################################################
//#########################################################################################################################################
