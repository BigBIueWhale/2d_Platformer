#ifndef MAP_H
#define MAP_H

#include "Entity.h"
class Map : public Entity
{
private:
    sf::View game_view;


    sf::Texture map_texture_;
    sf::Texture map_background;
    sf::RectangleShape map_background_rect;

    //###################WALLS
    //BASIC FLOOR
    sf::Sprite floor_ul_basic_sprite_;  // u - up, l - left, r - right, b - bottom, ur = up-right etc...
    sf::Sprite floor_um_basic_sprite_;
    sf::Sprite floor_ur_basic_sprite_;
    sf::Sprite floor_ml_basic_sprite_;
    sf::Sprite floor_mm_basic_sprite_;
    sf::Sprite floor_mr_basic_sprite_;
    sf::Sprite floor_bl_basic_sprite_;
    sf::Sprite floor_bm_basic_sprite_;
    sf::Sprite floor_br_basic_sprite_;

    sf::Sprite floor_single_basic_sprite_;

    sf::Sprite floor_l_basic_sprite_;
    sf::Sprite floor_m_basic_sprite_;
    sf::Sprite floor_r_basic_sprite_;

    //FANCY FLOOR
    sf::Sprite floor_ul_fancy_sprite_;
    sf::Sprite floor_um_fancy_sprite_;
    sf::Sprite floor_ur_fancy_sprite_;
    sf::Sprite floor_ml_fancy_sprite_;
    sf::Sprite floor_mm_fancy_sprite_;
    sf::Sprite floor_mr_fancy_sprite_;
    sf::Sprite floor_bl_fancy_sprite_;
    sf::Sprite floor_bm_fancy_sprite_;
    sf::Sprite floor_br_fancy_sprite_;

    sf::Sprite floor_single_fancy_sprite_;

    sf::Sprite floor_l_fancy_sprite_;
    sf::Sprite floor_m_fancy_sprite_;
    sf::Sprite floor_r_fancy_sprite_;


    //BRIDGE
    sf::Sprite bridge_l_sprite_;
    sf::Sprite bridge_m_sprite_;
    sf::Sprite bridge_r_sprite_;


    //##################BACKGROUND
    sf::Sprite background_sprite_;

    //#####################DECORATIONS

    sf::Sprite sign1_sprite_;
    sf::Sprite sign2_sprite_;
    sf::Sprite sign3_sprite_;
    sf::Sprite sign4_sprite_;

    sf::Sprite pile1_sprite_;
    sf::Sprite pile2_sprite_;
    sf::Sprite pile3_sprite_;

    //#####################SPIKES

    sf::Sprite spike_l_sprite_;
    sf::Sprite spike_r_sprite_;
    sf::Sprite spike_u_sprite_;
    sf::Sprite spike_b_sprite_;



    //VARIABLES

    //map sizes
    const int rows = 20;
    const int cols = 60;

    //vector of objects on map
    std::vector<sf::Sprite> walls_vector;
    std::vector<sf::Sprite> decorations_vector;
    std::vector<sf::Sprite> spikes_vector;

    //FUNCTIONS
    void loadMapFromFile();

public:
    virtual void drawWindow(sf::RenderWindow &window)override;
    Map();

    std::vector<sf::Sprite> getWalls() const;
    std::vector<sf::Sprite> getSpikes() const;
};

#endif // MAP_H
