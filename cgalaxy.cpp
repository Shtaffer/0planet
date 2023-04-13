#include "cgalaxy.h"

#define MAX_PLAYER 4

CPlanet::CPlanet(CNumber *number, int type)
{
    this->id = ++counter;
    this->seed = number->Next();

    CName   name(number->Next());

    this->type = type;
    this->name = name.NextName();
    this->population = number->Next();
    this->size = number->NextSize(type);
    this->owner = number->NextInt(MAX_PLAYER);
}

QVariantMap CPlanet::getInfo()
{
    QVariantMap info;

    info["id"] = this->id;
    info["seed"] = this->seed;
    info["owner"] = this->owner;
    info["size"] = this->size;
    info["population"] = this->population;

    return info;
}

CSolarSystem::CSolarSystem(CNumber *number)
{
    this->id = ++counter;
    this->seed = number->Next();

    CName   name(number->Next());

    this->owner = number->NextInt(MAX_PLAYER);
    this->name = name.NextName();

    int numberOfPlanets = 3 + number->NextInt(7);

    this->planets.resize(numberOfPlanets);

    for(auto &planet : planets)
    {
        planet = new CPlanet(number, 1);
    }
}

CSector::CSector(CNumber *number)
{
    this->id = ++counter;
    this->seed = number->Next();

    CName   name(number->Next());

    this->owner = number->NextInt(MAX_PLAYER);
    this->name = name.NextName();

    int numberOfSolarSystems = 3 + number->NextInt(7);

    this->solarSystems.resize(numberOfSolarSystems);

    for(auto &solarSystem : solarSystems)
    {
        solarSystem = new CSolarSystem(number);
    }

}

CGalaxy::CGalaxy(CNumber *number)
{
    counter = 0;
    this->id = 0;
    this->seed = number->Next();

    CName   name(number->Next());

    this->owner = number->NextInt(MAX_PLAYER);
    this->name = name.NextName();

    int numberOfSectors = 3 + number->NextInt(7);

    this->sectors.resize(numberOfSectors);

    for(auto &sector : sectors)
    {
        sector = new CSector(number);
    }

}
