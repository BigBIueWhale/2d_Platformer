#include "Entity.h"

void Entity::readInfoFromFile(std::string &what_level)
{
    std::string file_path = "levelsinfo//" + what_level;
    std::ifstream file(file_path);
        if (!file.is_open())
        {
            std::cerr << "Error file " + what_level << std::endl;
        }
        std::string line;
           std::getline(file, line);
           file.close();

           std::stringstream sstream(line);
           char delimiter;

           sstream >> x_pos >> delimiter >> y_pos;

}


