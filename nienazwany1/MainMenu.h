#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class MainMenu : public sf::Sprite {
private:
    sf::Sprite play_sprite_;
    sf::Texture play_texture_;

    sf::Sprite bestscores_sprite_;
    sf::Texture bestscores_texture_;

    sf::Sprite settings_sprite_;
    sf::Texture settings_texture_;

    sf::Sprite exit_sprite_;
    sf::Texture exit_texture_;

    void scaleButtonWhenContainsMouse(sf::RenderWindow &window);

public:
    MainMenu(sf::Texture &play_texture, sf::Texture &bestscores_texture, sf::Texture &settings_texture, sf::Texture &exit_texture, sf::RenderWindow &window);
    void drawMenu(sf::RenderWindow &window);
    std::string detectButtonContainsMouse(sf::RenderWindow &window);
    void eventHandling(sf::Event &event, sf::RenderWindow &window);

};



#endif // MAINMENU_H
