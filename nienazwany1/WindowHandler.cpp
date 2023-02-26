#include "WindowHandler.h"

WindowHandler::WindowHandler(){
    // MUSIC INITIALIZATION
    changeoption_sound.openFromFile("music\\plum.wav");
    chooseoption_sound.openFromFile("music\\choose2.wav");
}

void WindowHandler::rememberClickedButton(std::string button_name)
{
    //RESULT: Set clicked button to what_button_clicked. Function used in main.cpp.
    if (button_name != "" && button_name != what_button_clicked)
    {
        what_button_clicked = button_name;
    }
}
void WindowHandler::playSoundOnChange(std::string &detection)
{

    //IN: detected name of object that contains mouse.
    //RESULT: play sound once when cursor contains button.
    if (detection != tmp1)
    {
        tmp1 = "";
        soundPlayed = false;
        changeoption_sound.stop();
    }
    if (detection != "" && tmp1 != detection)
    {
        if (!soundPlayed)
        {
            changeoption_sound.play();
            soundPlayed = true;
        }
        tmp1 = detection;
    }
}



