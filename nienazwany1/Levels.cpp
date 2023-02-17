#include "Levels.h"

Levels::Levels()
{


    std::vector<int> level;
}

void Levels::drawLevels(sf::RenderWindow &window)
{

}


void Levels::countLevels()
{

    DIR *dp;
      struct dirent *ep;
      dp = opendir ("levels\\");

      if (dp != NULL)
      {
        while (ep = readdir(dp))
          number_of_levels++;

        (void) closedir(dp);
      }
      else
        perror ("Couldn't open the directory");


      number_of_levels = number_of_levels - 2;

}
