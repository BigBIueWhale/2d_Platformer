#ifndef PLAYER_H
#define PLAYER_H
#endif // PLAYER_H
#include "Entity.h"



class Player : public Entity
{
private:
    sf::Sprite player_sprite_;
    sf::Texture player_texture_;
    sf::FloatRect playerBounds;
//- - - - - - - - - - -
    sf::Clock moveTimer;
    sf::Clock jumpTimer;
    sf::Clock animationTimer;
    float elapsed;

    int animationState = 0;
 //- - - - - - - - - - -
    bool turned_right = 1;
    bool move_right;
    bool move_left;
//- - - - - - - - - - -
    bool jump;
    bool jumped = 1;
    bool cancel_jump = 0;
//- - - - - - - - - - -
    bool gravitation;
    const float gravity = 3.0;
    const int jump_power = 6;

//- - - - - - - - - - -
    float velocity_x;
    float velocity_y;

    void animate() override;
    void substractHP();
public:
    Player();

    void move();
    sf::Sprite setSprite(sf::Sprite &player_sprite, sf::Texture &player_texture) override;
    virtual void drawWindow(sf::RenderWindow &window) const override;

//- - - - - - - - - - -
    const sf::FloatRect getBounds();
    const sf::Vector2f getVelocity();
//- - - - - - - - - - -
    void setCancelJump(const bool &value);
    void setBoolJump(const bool &value);
    void setBoolGravitation(const bool &value);
    void setBoolRightMove(const bool &value);
    void setBoolLeftMove(const bool &value);


};
