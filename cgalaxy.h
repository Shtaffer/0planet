#ifndef CGALAXY_H
#define CGALAXY_H

#include "QObject"
#include "QDebug"
#include "QVector"
#include "generators/CNumber.h"
#include "generators/CName.h"

static int counter = -1;

class CSpaceObject
{
public:
    CSpaceObject() {}
    virtual ~CSpaceObject() {}
    virtual QString getName() {return name;}
    virtual QString getFullName() {return type + " " + name;}
    virtual int getID() { return id; }
    virtual int getOwner() {return owner;}
protected:
    QString name;
    QString type;
    double seed;
    int owner;
    int id = -1;
    CSpaceObject* parent;

    qreal x,y,size,speed;
    int color;

};

class CPlanet : public CSpaceObject
{
public:
    CPlanet(CNumber *number, int type);
    //QString getName() {return "Planet " + name;}
    QVariantMap getInfo();
private:
    double size;
    double population;
    uchar type;
};

class CSolarSystem : public CSpaceObject
{
public:
    CSolarSystem(CNumber *number);
    //QString getName() {return "Solar system " + name;}
    QVector<CPlanet*>* getPlanets() {return &planets;}
private:
    QVector<CPlanet*> planets;
};

class CSector : public CSpaceObject
{
public:
    CSector(CNumber *number);
    //QString getName() {return "Sector " + name;}
    QVector<CSolarSystem*>* getSolarSystems() {return &solarSystems;}
private:
    QVector<CSolarSystem*> solarSystems;
};

class CGalaxy : public CSpaceObject
{
public:
    CGalaxy(CNumber *number);
    //QString getName() {return "Galaxy " + name;}
    QVector<CSector*>* getSectors() {return &sectors;}

private:
    QVector<CSector*> sectors;
};

#endif // CGALAXY_H
