#include "../lib/stdafx.h"
#include "../include/enemy.h"
#include "../include/global.h"
#include "../include/random.h"

/***************************************/
/*            CONSTRUCTORES            */
/***************************************/

Enemy::Enemy():
    m_position(0),
    m_orientation(false),
    m_lifes(1),
    m_dead(false)  { }

Enemy::Enemy(int o, int l)
{
    reset(o, l);
}

Enemy::~Enemy() { }

void Enemy::reset() 
{
    if (Random::getRandomClass()->getRandom(2)) 
    {
        m_position = 0;
        m_orientation = true;
    }
    else 
    {
        m_position = TAM_WORLD;
        m_orientation = false;
    }

    m_lifes = Random::getRandomClass()->getRandom(LIFES_ENEMY) + 1;
    m_dead = false;
}

void Enemy::reset(const bool orientation)
{
    m_orientation = orientation;
    m_lifes = Random::getRandomClass()->getRandom(LIFES_ENEMY) + 1;

    if (m_orientation)  m_position = 0;
    else                m_position = TAM_WORLD;
}

void Enemy::reset(const int orientation, const int lifes) 
{
    if (orientation) 
    {
        m_position = 0;
        m_orientation = orientation;
    }
    else 
    {
        m_position = TAM_WORLD;
        m_orientation = orientation;
    }

    m_lifes = lifes;
    m_dead = false;
}

/***************************************/
/*              SITUACIÓN              */
/***************************************/

void Enemy::setPosition(int position)          {    m_position = position;          }
int Enemy::getPosition()                       {    return m_position;              }

void Enemy::setOrientation(bool orientation)   {    m_orientation = orientation;    }
bool Enemy::getOrientation()                   {    return m_orientation;           }

void Enemy::followPlayer(int player_position) 
{
    if (m_position  < player_position) m_position++;
    else                               m_position--;
}

void Enemy::wounded() 
{
    if (m_orientation)                 m_position -= ENEMY_RECOIL;
    else                               m_position += ENEMY_RECOIL;
                                       
    if (m_position < 0)                m_position = 0;
    else if (m_position > TAM_WORLD)   m_position = TAM_WORLD;

    decLifes();
}

/***************************************/
/*                VIDAS                */
/***************************************/

void Enemy::setLifes(int lifes)    {    m_lifes = lifes;             }
int Enemy::getLifes()              {    return m_lifes;              }
bool Enemy::getDead()              {    return m_dead;               }

void Enemy::decLifes() 
{
    m_lifes--;
    if (m_lifes <= 0) m_dead = true;
}

