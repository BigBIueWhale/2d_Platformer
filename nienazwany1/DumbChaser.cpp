#include <DumbChaser.h>




DumbChaser::DumbChaser(sf::Vector2i &enemy_pos)
{
    chaser_text_.loadFromFile("textures\\game\\enemies.png");
    chaser_sprite_.setTexture(chaser_text_);
    //chaser_sprite_.setTextureRect(sf::IntRect(28,16,36,64));
    chaser_sprite_.setScale(3.0,3.0);
    chaser_sprite_.setPosition(enemy_pos.x, enemy_pos.y);

}

void DumbChaser::move()
{

//    if(1)
//    {
//        ;
//    }
//    else if(chase_player)
//    {
//        //run after player;
//    }


   if(elapsed > 0.03f)
   {
       chaser_sprite_.move(2,0);
   }

    animate();
}

void DumbChaser::drawWindow(sf::RenderWindow &window)
{
    window.draw(chaser_sprite_);
}

void DumbChaser::animate()
{
    elapsed = animationTimer.getElapsedTime().asSeconds();

    if(elapsed >= 0.1f && move_right==0 &&  move_left==0)
    {
        animationState=4;
    }

    if(elapsed >= 0.1f && move_right)//right
    {
        if(!turned_right)
        {
            chaser_sprite_.setScale(5.0f, 5.0f);
            chaser_sprite_.move(-chaser_sprite_.getLocalBounds().width, 0);

            turned_right = 1;
        }


        animationState++;
        if (animationState>4)
        {
            animationState=0;
        }

        animationTimer.restart();
    }
    else if(elapsed >= 0.1f && move_left)//left
    {
        if(turned_right)
        {
           chaser_sprite_.setScale(-5.0f, 5.0f);
            chaser_sprite_.move(chaser_sprite_.getLocalBounds().width, 0);

            turned_right = 0;
            animationState=0;
        }

        animationState++;
        if (animationState>4)
        {
            animationState=0;
        }

        animationTimer.restart();
    }


    //ANIMATIONS
    switch(animationState) //animation of walking
    {
    case 0:
        chaser_sprite_.setTextureRect(sf::IntRect(4,3,6,13));
        break;
    case 1:
        chaser_sprite_.setTextureRect(sf::IntRect(12,3,6,13));
        break;
    case 2:
        chaser_sprite_.setTextureRect(sf::IntRect(21,3,6,13));
        break;
    case 3:
        chaser_sprite_.setTextureRect(sf::IntRect(31,3,6,13));
        break;
    case 4:
        chaser_sprite_.setTextureRect(sf::IntRect(40,3,6,13));
        break;

    }

}


