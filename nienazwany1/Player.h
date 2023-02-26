#ifndef PLAYER_H
#define PLAYER_H
#endif // PLAYER_H
#include "Entity.h"



class Player : public Entity
{
private:
    sf::Sprite player_sprite_;
    sf::Texture player_texture_;

    int HP = 3;


    float gravity = 5.5;
    int move_speed = 0;


    void substractHP();
public:
    Player();
    //Player(int &which_level);
    void animate();
    sf::Sprite setSprite(sf::Sprite &player_sprite, sf::Texture &player_texture) override;
    virtual void drawWindow(sf::RenderWindow &window) const override;

};
