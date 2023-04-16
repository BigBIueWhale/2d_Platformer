#include <XmlHandler.h>

struct_Level XmlHandler::loadLevelDataFromFile() {

        readLevelChosen();

        struct_Level level;

        QFile file(QString::fromStdString("levelsinfo//levels_info.xml"));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            std::cerr << "Error loading file!" << std::endl;
                return level;
        }

        QXmlStreamReader xml(&file);

        while (!xml.atEnd() && !xml.hasError()) {
            xml.readNext();

            if (xml.name() == QStringLiteral("level") && xml.attributes().value("id").toInt() == level_id) {
                //level.id = level_id;
                level.map_size.x = xml.attributes().value("map_width").toInt();
                level.map_size.y = xml.attributes().value("map_height").toInt();
                level.time_to_complete_seconds = xml.readElementText().toInt();

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
                break;
            }
        }

        file.close();
        return level;
}

void XmlHandler::setLevelChosen(const int &level)
{

    QFile file("levelsinfo//chosen_level.xml");
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("CAN NOT OPEN chosen_level.xml!!!");
        return;
    }
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("chosen_level");
    xmlWriter.writeCharacters(QString::number(level));
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file.close();

}


void XmlHandler::readLevelChosen()
{
    QFile file("levelsinfo//chosen_level.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("CAN NOT OPEN chosen_level.xml!!!");
    }

    QXmlStreamReader xmlReader(&file);

    while (!xmlReader.atEnd() && !xmlReader.hasError()) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();

        if (token == QXmlStreamReader::StartElement) {
                if (xmlReader.name() ==  QStringLiteral("chosen_level")) {
                // Odczyt wartości zmiennej
                QString valueString = xmlReader.readElementText();
                int value = valueString.toInt();
                file.close();
                level_id = value;
            }
        }
    }

    file.close();
}


