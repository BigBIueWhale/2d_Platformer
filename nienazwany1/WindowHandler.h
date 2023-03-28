#ifndef WINDOWHANDLER_H
#define WINDOWHANDLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


class WindowHandler : public sf::Sprite
{
private:
    std::string tmp1 = "";
    bool soundPlayed = false;



protected:
    int chosen_level=1;
    sf::Music changeoption_sound;
    sf::Music chooseoption_sound;
    virtual void dynamicMenu(sf::RenderWindow &window)=0;
    void playSoundOnChange(std::string &detection);
public:
    WindowHandler();

    std::string what_button_clicked = "";
    void rememberClickedButton(std::string button_name);

    virtual void drawWindow(sf::RenderWindow &window)=0;
    virtual std::string eventHandling(sf::RenderWindow &window)=0;

    virtual ~WindowHandler(){}
};


#endif // WINDOWHANDLER_H
