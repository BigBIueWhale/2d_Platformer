#include <XmlHandler.h>

struct_Level XmlHandler::readLevelDataFromFile(int level_id) {
        struct_Level level;

        // Otwarcie pliku
        QFile file(QString::fromStdString("levelsinfo//levels_info.xml"));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            std::cerr << "Błąd otwarcia pliku!" << std::endl;
                return level;
        }

        // Przygotowanie obiektu do odczytu XML
        QXmlStreamReader xml(&file);

        // Przeszukanie pliku XML
        while (!xml.atEnd() && !xml.hasError()) {
            xml.readNext();

            // Sprawdzenie, czy napotkano element "level" o odpowiednim ID
            if (xml.name() == QStringLiteral("level") && xml.attributes().value("id").toInt() == level_id) {
                //level.id = level_id;
                level.map_size.x = xml.attributes().value("map_width").toInt();
                level.map_size.y = xml.attributes().value("map_height").toInt();
                level.time_to_complete_seconds = xml.readElementText().toInt();

                // Przeszukanie elementu "enemies" i odczytanie danych o przeciwnikach
                while (xml.name() != QStringLiteral("enemies") || xml.tokenType() != QXmlStreamReader::StartElement) {
                    xml.readNext();
                }

                while (xml.readNextStartElement()) {
                    if (xml.name() == QStringLiteral("enemy")) {
                        Enemy enemy;
                        enemy.enemy_class = xml.attributes().value("class").toString().toStdString();
                        enemy.enemy_pos.x = xml.attributes().value("position_x").toString().toInt();
                        enemy.enemy_pos.y = xml.attributes().value("position_y").toString().toInt();
                        level.enemies.push_back(enemy);
                    }
                }

                // Przeszukanie elementu "start" i odczytanie pozycji startowej gracza
                while (xml.name() != QStringLiteral("start") || xml.tokenType() != QXmlStreamReader::StartElement) {
                    xml.readNext();
                }

                int player_pos_x = xml.attributes().value("position_x").toString().toInt();
                int player_pos_y = xml.attributes().value("position_y").toString().toInt();
                level.player_pos = {player_pos_x, player_pos_y};

                // Zakończenie przeszukiwania poziomu
                break;
            }
        }

        // Zamknięcie pliku i zwrócenie wyniku
        file.close();
        return level;
    }


