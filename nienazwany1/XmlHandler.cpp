#include <XmlHandler.h>

struct_Level XmlHandler::loadLevelDataFromFile() {


    struct_Level level;
    readLevelChosen(level);
    QFile file(QString::fromStdString("levelsinfo//levels_info.xml"));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Error loading file!" << std::endl;
        return level;
    }

    QXmlStreamReader xml(&file);

    while (!xml.atEnd() && !xml.hasError()) {
        xml.readNext();

        if (xml.name() == QStringLiteral("level") && xml.attributes().value("id").toInt() == level_id) {
            level.map_size.y = xml.attributes().value("map_width").toInt();
            level.map_size.x = xml.attributes().value("map_height").toInt();

            while (xml.name() != QStringLiteral("start") || xml.tokenType() != QXmlStreamReader::StartElement) {
                xml.readNext();
            }

            int player_pos_x = xml.attributes().value("position_x").toString().toInt();
            int player_pos_y = xml.attributes().value("position_y").toString().toInt();
            level.player_pos = {player_pos_x, player_pos_y};


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

    QDomDocument doc;
    QDomElement root = doc.createElement("root");
    doc.appendChild(root);
    QDomElement chosenLevelElement = doc.createElement("chosen_level");
    root.appendChild(chosenLevelElement);

    QDomText chosenLevelText = doc.createTextNode(QString::number(level));
    chosenLevelElement.appendChild(chosenLevelText);

    QTextStream stream(&file);
    stream << doc.toString();

    file.close();
}


void XmlHandler::readLevelChosen(struct_Level &level)
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
                QString valueString = xmlReader.readElementText();
                int value = valueString.toInt();
                file.close();
                level_id = value;
            }
        }
    }

    file.close();
}


