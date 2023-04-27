
#ifndef DUMBCHASER_H
#define DUMBCHASER_H

#include "Entity.h"
#endif // DUMBCHASER_H


class DumbChaser : public Entity
{

private:
    sf::Texture chaser_text_;
    sf::Sprite chaser_sprite_;


    bool move_right=1;;
    bool move_left=0;
    bool turned_right=1;
    bool chase_player=0;
    sf::Clock animationTimer;
    float elapsed;
    int animationState=0;


public:
    DumbChaser(sf::Vector2i &enemy_pos);
    void move();



    virtual void drawWindow(sf::RenderWindow &window) override;
    virtual void animate() override;
};
