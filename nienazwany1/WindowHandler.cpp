#include "WindowHandler.h"

WindowHandler::WindowHandler(){
    // MUSIC INITIALIZATION
    changeoption_sound.openFromFile("music\\plum.wav");
    chooseoption_sound.openFromFile("music\\choose.wav");
}

void WindowHandler::rememberClickedButton(std::string button_name)
{
    if (button_name != "" && button_name != what_button_clicked)
    {
        what_button_clicked = button_name;
    }
}
