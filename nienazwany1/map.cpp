#include "map.h"

Map::Map()
{
    //RESULT: INITIALIZATION OF loadMapFromFile, TEXTURE AND SPRITES


    map_texture_.loadFromFile("textures\\game\\tiles.png");

    //#############WALLS
    //TOP BASIC
    floor_ul_basic_sprite_.setTexture(map_texture_);
    floor_ul_basic_sprite_.setTextureRect(sf::IntRect(384,384,64,64));
    floor_ul_basic_sprite_.setScale(0.6,0.6);

    floor_um_basic_sprite_.setTexture(map_texture_);
    floor_um_basic_sprite_.setTextureRect(sf::IntRect(448,384,64,64));
    floor_um_basic_sprite_.setScale(0.6,0.6);

    floor_ur_basic_sprite_.setTexture(map_texture_);
    floor_ur_basic_sprite_.setTextureRect(sf::IntRect(512,384,64,64));
    floor_ur_basic_sprite_.setScale(0.6,0.6);

    //MIDDLE BASIC
    floor_ml_basic_sprite_.setTexture(map_texture_);
    floor_ml_basic_sprite_.setTextureRect(sf::IntRect(384,448,64,64));
    floor_ml_basic_sprite_.setScale(0.6,0.6);

    floor_mm_basic_sprite_.setTexture(map_texture_);
    floor_mm_basic_sprite_.setTextureRect(sf::IntRect(448,448,64,64));
    floor_mm_basic_sprite_.setScale(0.6,0.6);


    floor_mr_basic_sprite_.setTexture(map_texture_);
    floor_mr_basic_sprite_.setTextureRect(sf::IntRect(512,448,64,64));
    floor_mr_basic_sprite_.setScale(0.6,0.6);

    //BOTTOM BASIC
    floor_bl_basic_sprite_.setTexture(map_texture_);
    floor_bl_basic_sprite_.setTextureRect(sf::IntRect(384,512,64,64));
    floor_bl_basic_sprite_.setScale(0.6,0.6);

    floor_bm_basic_sprite_.setTexture(map_texture_);
    floor_bm_basic_sprite_.setTextureRect(sf::IntRect(448,512,64,64));
    floor_bm_basic_sprite_.setScale(0.6,0.6);

    floor_br_basic_sprite_.setTexture(map_texture_);
    floor_br_basic_sprite_.setTextureRect(sf::IntRect(512,512,64,64));
    floor_br_basic_sprite_.setScale(0.6,0.6);

    //SINGLE BASIC

    floor_single_basic_sprite_.setTexture(map_texture_);
    floor_single_basic_sprite_.setTextureRect(sf::IntRect(896,320,64,64));
    floor_single_basic_sprite_.setScale(0.6,0.6);

    //TRIPLE BASIC
    floor_l_basic_sprite_.setTexture(map_texture_);
    floor_l_basic_sprite_.setTextureRect(sf::IntRect(640,320,64,64));
    floor_l_basic_sprite_.setScale(0.6,0.6);

    floor_m_basic_sprite_.setTexture(map_texture_);
    floor_m_basic_sprite_.setTextureRect(sf::IntRect(704,320,64,64));
    floor_m_basic_sprite_.setScale(0.6,0.6);

    floor_m_basic_sprite_.setTexture(map_texture_);
    floor_m_basic_sprite_.setTextureRect(sf::IntRect(768,320,64,64));
    floor_m_basic_sprite_.setScale(0.6,0.6);

    //TOP FANCY
    floor_ul_fancy_sprite_.setTexture(map_texture_);
    floor_ul_fancy_sprite_.setTextureRect(sf::IntRect(384,192,64,64));
    floor_ul_fancy_sprite_.setScale(0.6,0.6);

    floor_um_fancy_sprite_.setTexture(map_texture_);
    floor_um_fancy_sprite_.setTextureRect(sf::IntRect(448,192,64,64));
    floor_um_fancy_sprite_.setScale(0.6,0.6);

    floor_ur_fancy_sprite_.setTexture(map_texture_);
    floor_ur_fancy_sprite_.setTextureRect(sf::IntRect(512,192,64,64));
    floor_ur_fancy_sprite_.setScale(0.6,0.6);

    //MIDLE FANCY
    floor_ml_fancy_sprite_.setTexture(map_texture_);
    floor_ml_fancy_sprite_.setTextureRect(sf::IntRect(384,256,64,64));
    floor_ml_fancy_sprite_.setScale(0.6,0.6);

    floor_mm_fancy_sprite_.setTexture(map_texture_);
    floor_mm_fancy_sprite_.setTextureRect(sf::IntRect(448,256,64,64));
    floor_mm_fancy_sprite_.setScale(0.6,0.6);


    floor_mr_fancy_sprite_.setTexture(map_texture_);
    floor_mr_fancy_sprite_.setTextureRect(sf::IntRect(512,256,64,64));
    floor_mr_fancy_sprite_.setScale(0.6,0.6);


    //BOTTOM FANCY
    floor_bl_fancy_sprite_.setTexture(map_texture_);
    floor_bl_fancy_sprite_.setTextureRect(sf::IntRect(384,320,64,64));
    floor_bl_fancy_sprite_.setScale(0.6,0.6);

    floor_bm_fancy_sprite_.setTexture(map_texture_);
    floor_bm_fancy_sprite_.setTextureRect(sf::IntRect(448,320,64,64));
    floor_bm_fancy_sprite_.setScale(0.6,0.6);

    floor_br_fancy_sprite_.setTexture(map_texture_);
    floor_br_fancy_sprite_.setTextureRect(sf::IntRect(512,320,64,64));
    floor_br_fancy_sprite_.setScale(0.6,0.6);


    //SINGLE FANCY
    floor_single_fancy_sprite_.setTexture(map_texture_);
    floor_single_fancy_sprite_.setTextureRect(sf::IntRect(896,192,64,64));
    floor_single_fancy_sprite_.setScale(0.6,0.6);

    //TRIPLE FANCY
    floor_l_fancy_sprite_.setTexture(map_texture_);
    floor_l_fancy_sprite_.setTextureRect(sf::IntRect(640,192,64,64));
    floor_l_fancy_sprite_.setScale(0.6,0.6);

    floor_m_fancy_sprite_.setTexture(map_texture_);
    floor_m_fancy_sprite_.setTextureRect(sf::IntRect(704,192,64,64));
    floor_m_fancy_sprite_.setScale(0.6,0.6);

    floor_r_fancy_sprite_.setTexture(map_texture_);
    floor_r_fancy_sprite_.setTextureRect(sf::IntRect(768,192,64,64));
    floor_r_fancy_sprite_.setScale(0.6,0.6);



    //BRIDGE
    bridge_l_sprite_.setTexture(map_texture_);
    bridge_l_sprite_.setTextureRect(sf::IntRect(640,448,64,64));
    bridge_l_sprite_.setScale(0.6,0.6);

    bridge_m_sprite_.setTexture(map_texture_);
    bridge_m_sprite_.setTextureRect(sf::IntRect(704,448,64,64));
    bridge_m_sprite_.setScale(0.6,0.6);

    bridge_r_sprite_.setTexture(map_texture_);
    bridge_r_sprite_.setTextureRect(sf::IntRect(768,448,64,64));
    bridge_r_sprite_.setScale(0.6,0.6);


    //BACKGROUND
    background_sprite_.setTexture(map_texture_);
    background_sprite_.setTextureRect(sf::IntRect(64,320,256,256));
    background_sprite_.setScale(0.6,0.6);


    //###########DECORATIONS
    //signs
    sign1_sprite_.setTexture(map_texture_);
    sign1_sprite_.setTextureRect(sf::IntRect(204,64,50,64));
    sign1_sprite_.setScale(0.6,0.6);

    sign2_sprite_.setTexture(map_texture_);
    sign2_sprite_.setTextureRect(sf::IntRect(254,64,50,64));
    sign2_sprite_.setScale(0.6,0.6);

    sign3_sprite_.setTexture(map_texture_);
    sign3_sprite_.setTextureRect(sf::IntRect(520,64,50,64));
    sign3_sprite_.setScale(0.6,0.6);

    sign4_sprite_.setTexture(map_texture_);
    sign4_sprite_.setTextureRect(sf::IntRect(584,64,50,64));
    sign4_sprite_.setScale(0.6,0.6);

    //piles
    pile1_sprite_.setTexture(map_texture_);
    pile1_sprite_.setTextureRect(sf::IntRect(704,64,64,64));
    pile1_sprite_.setScale(0.6,0.6);

    pile2_sprite_.setTexture(map_texture_);
    pile2_sprite_.setTextureRect(sf::IntRect(768,0,64,128));
    pile2_sprite_.setScale(0.6,0.6);

    pile3_sprite_.setTexture(map_texture_);
    pile3_sprite_.setTextureRect(sf::IntRect(832,0,64,128));
    pile3_sprite_.setScale(0.6,0.6);

    //#############SPIKES
    spike_u_sprite_.setTexture(map_texture_);
    spike_u_sprite_.setTextureRect(sf::IntRect(896,384,64,64));
    spike_u_sprite_.setScale(0.6,0.6);

    spike_r_sprite_.setTexture(map_texture_);
    spike_r_sprite_.setTextureRect(sf::IntRect(960,448,64,64));
    spike_r_sprite_.setScale(0.6,0.6);

    spike_b_sprite_.setTexture(map_texture_);
    spike_b_sprite_.setTextureRect(sf::IntRect(896,512,64,64));
    spike_b_sprite_.setScale(0.6,0.6);

    spike_l_sprite_.setTexture(map_texture_);
    spike_l_sprite_.setTextureRect(sf::IntRect(832,448,64,64));
    spike_l_sprite_.setScale(0.6,0.6);


    //FUNCTIONS
    loadMapFromFile();

}

std::vector<sf::Sprite> Map::getWalls() const
{
    return walls_vector;
}

std::vector<sf::Sprite> Map::getSpikes() const
{
    return spikes_vector;
}

void Map::loadMapFromFile()
{
    //RESULT: Open the file and get stored variable (chosen level), then iterate through another file storing layout of the chosen map
    //        and place correnspoding texture in the correct place.
    char letter;
    int chosen_level;

    std::ifstream plik("levelsinfo\\level_name.txt");
    plik >> chosen_level;

     plik.close();

    const std::string file_path ="levels\\" + std::to_string(chosen_level) + ".txt";
    std::ifstream file(file_path);

    std::cout<<file_path<<std::endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                file.get(letter);
                if(letter=='-')
                {
                    //DO NOTHING
                }
                else if(letter == 'Q')
                {
                    floor_ul_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_ul_fancy_sprite_);
                }
                else if(letter == 'W')
                {
                    floor_um_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_um_fancy_sprite_);
                }
                else if(letter == 'E')
                {
                    floor_ur_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_ur_fancy_sprite_);
                }
                else if(letter == 'A')
                {
                    floor_ml_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_ml_fancy_sprite_);
                }
                else if(letter == 'S')
                {
                    floor_mm_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_mm_fancy_sprite_);
                }
                else if(letter == 'D')
                {
                    floor_mr_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_mr_fancy_sprite_);
                }
                else if(letter == 'Z')
                {
                    floor_bl_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_bl_fancy_sprite_);
                }
                else if(letter == 'X')
                {
                    floor_bm_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_bm_fancy_sprite_);
                }
                else if(letter == 'C')
                {
                    floor_br_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_br_fancy_sprite_);
                }
                else if(letter == 'q')
                {
                    floor_ul_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_ul_basic_sprite_);
                }
                else if(letter == 'w')
                {
                    floor_um_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_um_basic_sprite_);
                }
                else if(letter == 'e')
                {
                    floor_ur_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_ur_basic_sprite_);
                }
                else if(letter == 'a')
                {
                    floor_ml_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_ml_basic_sprite_);
                }
                else if(letter == 's')
                {
                    floor_mm_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_mm_basic_sprite_);
                }
                else if(letter == 'd')
                {
                    floor_mr_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_mr_basic_sprite_);
                }
                else if(letter == 'z')
                {
                    floor_bl_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_bl_basic_sprite_);
                }
                else if(letter == 'x')
                {
                    floor_bm_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_bm_basic_sprite_);
                }
                else if(letter == 'c')
                {
                    floor_br_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_br_basic_sprite_);
                }
                else if(letter == 'r')
                {
                    bridge_l_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(bridge_l_sprite_);
                }
                else if(letter == 't')
                {
                    bridge_m_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(bridge_m_sprite_);
                }
                else if(letter == 'y')
                {
                    bridge_r_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(bridge_r_sprite_);
                }
                else if(letter == 'f')
                {
                    floor_l_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_l_basic_sprite_);
                }
                else if(letter == 'g')
                {
                    floor_m_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_m_basic_sprite_);
                }
                else if(letter == 'h')
                {
                    floor_r_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_r_basic_sprite_);
                }
                else if(letter == 'F')
                {
                    floor_l_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_l_fancy_sprite_);
                }
                else if(letter == 'G')
                {
                    floor_m_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_m_fancy_sprite_);
                }
                else if(letter == 'H')
                {
                    floor_r_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_r_fancy_sprite_);
                }
                else if(letter == 'v')
                {
                    floor_single_basic_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_single_basic_sprite_);
                }
                else if(letter == 'V')
                {
                    floor_single_fancy_sprite_.setPosition(j*38.4,i*38.4);
                    walls_vector.emplace_back(floor_single_fancy_sprite_);
                }
                else if(letter == 'b')
                {
                    sign1_sprite_.setPosition(j*38.4,i*38.4);
                    decorations_vector.emplace_back(sign1_sprite_);
                }
                else if(letter == 'B')
                {
                    sign2_sprite_.setPosition(j*38.4,i*38.4);
                    decorations_vector.emplace_back(sign2_sprite_);
                }
                else if(letter == 'n')
                {
                    sign3_sprite_.setPosition(j*38.4,i*38.4);
                    decorations_vector.emplace_back(sign3_sprite_);
                }
                else if(letter == 'N')
                {
                    sign4_sprite_.setPosition(j*38.4,i*38.4);
                    decorations_vector.emplace_back(sign4_sprite_);
                }
                else if(letter == 'u')
                {
                    pile1_sprite_.setPosition(j*38.4,i*38.4);
                    decorations_vector.emplace_back(pile1_sprite_);
                }
                else if(letter == 'U')
                {
                    pile2_sprite_.setPosition(j*38.4,i*38.4-36);
                    decorations_vector.emplace_back(pile2_sprite_);
                }
                else if(letter == 'i')
                {
                    pile3_sprite_.setPosition(j*38.4,i*38.4-36);
                    decorations_vector.emplace_back(pile3_sprite_);
                }
                else if(letter == 'O')
                {
                    spike_u_sprite_.setPosition(j*38.4,i*38.4);
                    spikes_vector.emplace_back(spike_u_sprite_);
                }
                else if(letter == 'o')
                {
                    spike_r_sprite_.setPosition(j*38.4,i*38.4);
                    spikes_vector.emplace_back(spike_r_sprite_);
                }
                else if(letter == 'P')
                {
                    spike_b_sprite_.setPosition(j*38.4,i*38.4);
                    decorations_vector.emplace_back(spike_b_sprite_);
                }
                else if(letter == 'p')
                {
                    spike_l_sprite_.setPosition(j*38.4,i*38.4);
                    spikes_vector.emplace_back(spike_l_sprite_);
                }
            }
        }


        file.close();
}

void Map::drawWindow(sf::RenderWindow &window) const
{
    // IN: Rendered window;
    // RESULT: Draws map in the provided window;

    for(const sf::Sprite &el : decorations_vector)
    {
        window.draw(el);
    }
    for(const sf::Sprite &el : spikes_vector)
    {
        window.draw(el);
    }
    for(const sf::Sprite &el : walls_vector)
    {
        window.draw(el);
    }



}
