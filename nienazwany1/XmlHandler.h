
#ifndef XMLHANDLER_H
#define XMLHANDLER_H

#endif // XMLHANDLER_H


#include <QCoreApplication>
#include <QFile>
#include <QtXml>


#include <struct_Level.h>


class XmlHandler
{
private:
    int level_id;

    void readLevelChosen();
public:
    struct_Level loadLevelDataFromFile();
    // readScoreboard();
    // readSettings();

    void setLevelChosen(const int &level);


};



