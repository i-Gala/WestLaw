#include "../lib/stdafx.h"
#include "../include/bullet.h"
#include "../include/global.h"

Bullet::Bullet():
    m_position(-1) { }


Bullet::~Bullet() {}

void Bullet::init(int position, bool orientation) 
{
    m_position = position;
    m_orientation = orientation;
    m_inGame = true;
}

void Bullet::reset() 
{
    m_position = -1;
    m_inGame = false;
}

/***************************************/
/*              SITUACIÓN              */
/***************************************/

void Bullet::setOrientation(bool orientation)  {    m_orientation = orientation;    }
bool Bullet::getOrientation()                  {    return m_orientation; }

void Bullet::setPosition(int position)         {    m_position = position;   }
int Bullet::getPosition()                      {    return m_position;       }

void Bullet::move() 
{
    if (m_orientation)  m_position++;
    else                m_position--;

    if (m_position < 0 || m_position > TAM_WORLD)    reset();
}


/***************************************/
/*               IN GAME               */
/***************************************/

void Bullet::setInGame(bool inGame) {    m_inGame = inGame;  }
bool Bullet::getInGame()            {    return m_inGame;    }