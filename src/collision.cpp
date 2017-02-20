#include "../lib/stdafx.h"
#include "../include/collision.h"


Collision::Collision() { }
Collision::~Collision() { }

const bool Collision::getCollision1D(int positionA, int positionB)
{
    bool collision = false;

    if (positionA == positionB)        collision = true;

    return static_cast<const bool>(collision);
}

