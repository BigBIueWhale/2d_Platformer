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

    animationTimer.restart();
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

const sf::FloatRect Player::getBounds()
{
    return player_sprite_.getGlobalBounds();
}

const sf::Vector2f Player::getVelocity()
{
    return sf::Vector2f(velocity_x,velocity_y);
}

void Player::setCancelJump(const bool &value)
{
    cancel_jump = value;
}

void Player::setBoolJump(const bool &allow)
{
    jump = allow;
}

void Player::setBoolGravitation(const bool &value)
{
    gravitation = value;
}



void Player::setBoolRightMove(const bool &value)
{
    move_right = value;
}

void Player::setBoolLeftMove(const bool &value)
{
    move_left = value;
}


//#########################################################################################################################################
//#########################################################################################################################################



void Player::move()
{

    if(move_right)
    {
        velocity_x = 2;
    }
    if(move_left)
    {
        velocity_x = -2;
    }
    if(!move_left && !move_right)
        velocity_x = 0;


    //- - - - - - - -

    if(gravitation && jumped == 1)
    {
        velocity_y = gravity;
    }
    else if(jumped == 1)
    {
        velocity_y = 0;
    }
    // - - - - - - - -
    elapsed = jumpTimer.getElapsedTime().asSeconds();
    if (jump)
    {
        if(jumped)
        {
            velocity_y = -jump_power;
            gravitation = 0;
            jumped = 0;
        }

        if(elapsed > 0.01f)
        {
            velocity_y = velocity_y + 0.16 ;
            jumpTimer.restart();
        }
        if(velocity_y >= gravity || cancel_jump)
        {
            gravitation = 1;
            jump = 0;
            jumped = 1;
        }
    }
    else{
        jumped = 1;
    }



    elapsed = moveTimer.getElapsedTime().asSeconds();
    if(elapsed > 0.1f)
    {
        player_sprite_.move(velocity_x,velocity_y);
    }


   this->animate();
   this->move_right=0;
   this->move_left=0;
}


void Player::animate()
{
    elapsed = animationTimer.getElapsedTime().asSeconds();


    //#####WALK ANIMATION
    if(elapsed >= 0.1f && move_right==0 &&  move_left==0)
    {
       animationState=5;
    }

    if(elapsed >= 0.1f && move_right)//right
    {
        if(!turned_right)
        {
            player_sprite_.setScale(0.7f, 0.7f);
            player_sprite_.move(-player_sprite_.getLocalBounds().width + 11, 0);

            turned_right = 1;
        }


        animationState++;
        if (animationState>5)
            {
                animationState=0;
            }

        animationTimer.restart();
    }
    else if(elapsed >= 0.1f && move_left)//left
    {
        if(turned_right)
        {
            player_sprite_.setScale(-0.7f, 0.7f);
            player_sprite_.move(player_sprite_.getLocalBounds().width-11, 0);

            turned_right = 0;
            animationState=0;
        }

        animationState++;
        if (animationState>5)
            {
                animationState=0;
            }

        animationTimer.restart();
    }

    //#####JUMP ANIMATION


    std::cout<<player_sprite_.getGlobalBounds().left <<" ," <<" ,"<<player_sprite_.getGlobalBounds().top<<" ,"<<player_sprite_.getGlobalBounds().width<<" ,"<<player_sprite_.getGlobalBounds().height<<std::endl;

    //ANIMATIONS
    switch(animationState) //animation of walking
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


// TO DO: ATTACK, ATTACK WHILE WALKING, ATTACK ON THE LADDER, GRAVITY IMPLEMENTATION, JUMP, LADDER CLIMBING, SMOOTHERING OF WALKING (now character does not do it fluently (ma)
    
}


//#########################################################################################################################################
//#########################################################################################################################################
