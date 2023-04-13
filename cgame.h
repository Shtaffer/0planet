#ifndef CGAME_H
#define CGAME_H

#include <QListWidgetItem>
#include <QDebug>

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "generators/CNumber.h"
#include "generators/CName.h"
#include "cgalaxy.h"

class CGame
{
public:
    CGame();
    CGalaxy* getGalaxy();
    CGalaxy* generateGalaxy(CNumber &number);
    QString findByID(int id);
    QString findByName(QString name);
    QGraphicsScene *draw();

private:
    CNumber gen;
    CGalaxy *galaxy = nullptr;
    CNumber number;

    QGraphicsScene *scene = nullptr;

};

#endif // CGAME_H
