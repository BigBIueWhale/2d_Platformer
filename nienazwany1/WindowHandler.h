#ifndef WINDOWHANDLER_H
#define WINDOWHANDLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


class WindowHandler : public sf::Sprite
{
protected:
    sf::Music changeoption_sound;
    sf::Music chooseoption_sound;

public:
    std::string what_button_clicked = "";
    WindowHandler();

    void rememberClickedButton(std::string button_name);

    virtual void drawWindow(sf::RenderWindow &window)=0;
    virtual std::string eventHandling(sf::RenderWindow &window)=0;
    virtual ~WindowHandler(){}
};


#endif // WINDOWHANDLER_H
