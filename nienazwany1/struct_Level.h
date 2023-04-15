
#ifndef STRUCT_LEVEL_H
#define STRUCT_LEVEL_H

#include "SFML/System/Vector2.hpp"
#endif // STRUCT_LEVEL_H
#include <iostream>
#include <vector>

struct struct_Level {
    sf::Vector2i player_pos;
    sf::Vector2i map_size;
    std::vector<struct Enemy> enemies;
    int time_to_complete_seconds;
};


struct Enemy {
    std::string enemy_class;
    sf::Vector2i enemy_pos;
};
