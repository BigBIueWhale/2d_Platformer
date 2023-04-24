#ifndef PLAYER_H
#define PLAYER_H
#endif // PLAYER_H
#include "Entity.h"



class Player : public Entity
{
private:
    sf::View game_view;


    sf::Sprite player_sprite_;
    sf::Texture player_texture_;
    sf::FloatRect playerBounds;
//- - - - - - - - - - -
    sf::Clock moveTimer;
    sf::Clock jumpTimer;
    sf::Clock animationTimer;
    float elapsed;

    int animationState = 0;

    void anim_move_right_left(float &elapsed);
 //- - - - - - - - - - -
    const int move_velocity = 2;
    bool turned_right = 1;
    bool move_right;
    bool move_left;
//- - - - - - - - - - -
    bool jump;
    bool jumped = 1;
    bool cancel_jump = 0;
//- - - - - - - - - - -
    bool gravitation;
    const float gravity = 4.0;
    const int jump_power = 6;

//- - - - - - - - - - -
    bool attack;

//- - - - - - - - - - -
    float velocity_x;
    float velocity_y;

    void animate() override;
    void substractHP();
public:
    Player(const sf::Vector2i &player_pos);
    void setPostion(const sf::Vector2i &player_pos);
    void move();
    virtual void drawWindow(sf::RenderWindow &window) override;

//- - - - - - - - - - -
    const sf::FloatRect getBounds();
    const sf::Vector2f getVelocity();
    const int getMaxMoveVelocity();
//- - - - - - - - - - -
    void setCancelJump(const bool &value);
    void setBoolJump(const bool &value);
    void setBoolGravitation(const bool &value);
    void setBoolRightMove(const bool &value);
    void setBoolLeftMove(const bool &value);
    void setBoolAttack(const bool &value);


};
