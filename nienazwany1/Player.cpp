#include "Player.h"


//#########################################################################################################################################
//#########################################################################################################################################

Player::Player()
{   //RESULT: Init and set player sprite
    player_texture_.loadFromFile("textures\\game\\player.png");
    player_sprite_.setTexture(player_texture_);
    player_sprite_.setTextureRect(sf::IntRect(28,16,36,64));
    player_sprite_.setScale(0.7,0.7);
    player_sprite_.setPosition(100,100); // <- has to be read from file
}

//#########################################################################################################################################
//#########################################################################################################################################

sf::Sprite Player::setSprite(sf::Sprite &player_sprite, sf::Texture &player_texture)
{   //FUNCTION UNUSED YET
    player_texture.loadFromFile("textures\\game\\player.png");
    player_sprite.setTexture(player_texture);
    player_sprite.setPosition(100,100);
    return player_sprite;
}

//#########################################################################################################################################
//#########################################################################################################################################

void Player::drawWindow(sf::RenderWindow &window)
{ //RESULT: draw player

    game_view.setSize(window.getSize().x, window.getSize().y);
    game_view.setCenter(player_sprite_.getGlobalBounds().left + (0.5*player_sprite_.getGlobalBounds().width), player_sprite_.getGlobalBounds().top+ (0.5 *player_sprite_.getGlobalBounds().height));
    window.setView(game_view);
    window.draw(player_sprite_);
}

//#########################################################################################################################################
//#########################################################################################################################################

const sf::FloatRect Player::getBounds()
{   //RETURN: player boundaries
    return player_sprite_.getGlobalBounds();
}

//#########################################################################################################################################
//#########################################################################################################################################

const sf::Vector2f Player::getVelocity()
{ //RETURN: PLAYER XY VELOCITIES
    return sf::Vector2f(velocity_x,velocity_y);
}

//#########################################################################################################################################
//#########################################################################################################################################

void Player::setCancelJump(const bool &value)
{
    //RESULT: sets bool cancel_jump
    cancel_jump = value;
}

//#########################################################################################################################################
//#########################################################################################################################################

void Player::setBoolJump(const bool &allow)
{  //RESULT: sets bool jump
    jump = allow;
}

//#########################################################################################################################################
//#########################################################################################################################################

void Player::setBoolGravitation(const bool &value)
{ //RESULT: sets bool gravitation
    gravitation = value;
}

//#########################################################################################################################################
//#########################################################################################################################################

void Player::setBoolRightMove(const bool &value)
{ //RESULT: sets bool move_right
    move_right = value;
}

//#########################################################################################################################################
//#########################################################################################################################################

void Player::setBoolLeftMove(const bool &value)
{ //RESULT: sets bool move_left
    move_left = value;
}


//#########################################################################################################################################
//#########################################################################################################################################

void Player::setBoolAttack(const bool &value)
{
    attack = value;
}

//#########################################################################################################################################
//#########################################################################################################################################

void Player::move()
{
    //RESULT: Moves player in XY positions depending on the GRAVITATION, JUMPED, MOVE RIGHT, MOVE LEFT, JUMP, CANCEL_JUMP values

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
            velocity_y = velocity_y + 0.155 ;
            jumpTimer.restart();
        }
        if(velocity_y >= gravity || cancel_jump)
        {
            gravitation = 1;
            jump = 0;
            jumped = 1;
        }
        if(velocity_y>0 && !jumped && !gravitation)
        {
            velocity_y = 0;
            jump = 0;
            jumped = 1;
        }
    }
    else{
        jumped = 1;
    }


// - - - - - - -
    elapsed = moveTimer.getElapsedTime().asSeconds();
    if(elapsed > 0.1f)
    {
        player_sprite_.move(velocity_x,velocity_y);
    }


   this->animate();
   this->move_right=0;
   this->move_left=0;
}

//#########################################################################################################################################
//#########################################################################################################################################

void Player::anim_move_right_left(float &elapsed)
{
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
}

void Player::animate()
{ //RESULT: Animate player (only during walk - for now)
    elapsed = animationTimer.getElapsedTime().asSeconds();

    anim_move_right_left(elapsed); //Animate standing still, walking left right

//    if(attack)
//    {
//        if(move_right)
//        {

//        }
//        else if(move_left)
//        {

//        }
//        else
//        {

//        }


//        switch(animationState) //animation of walking
//        {
//        case 0:
//            player_sprite_.setTextureRect(sf::IntRect(80,16,36,64));
//            break;
//        case 1:
//            player_sprite_.setTextureRect(sf::IntRect(128,16,36,64));
//            break;
//        case 2:
//            player_sprite_.setTextureRect(sf::IntRect(176,16,36,64));
//            break;
//        case 3:
//            player_sprite_.setTextureRect(sf::IntRect(224,16,36,64));
//            break;
//        case 4:
//            player_sprite_.setTextureRect(sf::IntRect(272,16,36,64));
//            break;
//        case 5:
//            player_sprite_.setTextureRect(sf::IntRect(24,16,36,64));
//            break;
//        }

//    }


// TO DO: ATTACK, ATTACK WHILE WALKING, ATTACK ON THE LADDER, GRAVITY IMPLEMENTATION, JUMP, LADDER CLIMBING, SMOOTHERING OF WALKING (now character does not do it fluently (ma)
    
}


//#########################################################################################################################################
//#########################################################################################################################################
