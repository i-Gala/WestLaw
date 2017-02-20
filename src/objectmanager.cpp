#include "../lib/stdafx.h"
#include "../include/objectmanager.h"
#include "../include/global.h"
#include "../include/random.h"

ObjectManager::ObjectManager():
    Position(0),
    Type(EO_LIFE),
    Able(false) { }


ObjectManager::~ObjectManager() { }

void ObjectManager::generateObject(const bool multiplayer)
{
    const int random = Random::getRandomClass()->getRandom(100);

    if (multiplayer && random < 10)    Type = EO_REVIVE;
    else if (random < 40)              Type = EO_LIFE;
    else                               Type = EO_BULLET;

    Position = Random::getRandomClass()->getRandom(TAM_WORLD);
    Able = true;
}

void ObjectManager::disable()                     {   Able = false;       }

int ObjectManager::getPosition()                  {   return Position;    }
ObjectManager::EObject ObjectManager::getType()   {   return Type;        }
bool ObjectManager::getAble()                     {   return Able;        }
