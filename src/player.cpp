#include "../lib/stdafx.h"
#include "../include/player.h"
#include "../include/bullet.h"
#include "../include/global.h"

/***************************************/
/*            CONSTRUCTORES            */
/***************************************/

Player::Player():
    m_gameOver(false),
    m_position(TAM_WORLD/2),
    m_orientation(true),
    m_lifes(LIFES_PLAYER),
    m_score(0),
    m_bulletAble(MAX_BULLET),
    m_bulletShot(0) { }


Player::~Player()
{
    deleteBullet(NULL, true);
}

void Player::reset() 
{
    m_gameOver = false;
    m_position = 40;
    m_orientation = true;
    m_lifes = LIFES_PLAYER;
    m_score = 0;
    m_bulletAble = MAX_BULLET;
    
    deleteBullet(NULL, true);
}

void Player::revive()
{
    m_gameOver = false;
    m_lifes = LIFES_PLAYER;
}

/***************************************/
/*              SITUACIÓN              */
/***************************************/

void Player::setOrientation(bool orientation)  {    m_orientation = orientation;  }
bool Player::getOrientation()                  {   return m_orientation;          }

void Player::setPosition(int position)         {   m_position = position;         }
int Player::getPosition()                      {   return m_position;             }

void Player::moveLeft() 
{
    m_orientation = false;
    if (m_position > 0)        m_position--;
}

void Player::moveRight() 
{
    m_orientation = true;
    if (m_position < TAM_WORLD) m_position++;
}


/***************************************/
/*                VIDAS                */
/***************************************/

bool Player::getGameOver()         {   return m_gameOver; }

void Player::setLifes(int lifes)   {   m_lifes = lifes;   }
int Player::getLifes()             {   return m_lifes;    }

void Player::incLifes() 
{ 
    if (m_lifes >= LIFES_PLAYER) return;
    m_lifes++;
}

void Player::decLifes() 
{
    m_lifes--;
    if (m_lifes <= 0) m_gameOver = true;
}


/***************************************/
/*             PUNTUACION              */
/***************************************/

void Player::setScore(int score)   {   m_score = score;  }
int Player::getScore()             {   return m_score;   }
void Player::incScore()            {   m_score++;        }

/***************************************/
/*                 BALAS               */
/***************************************/

void Player::reloadBullet()        {   m_bulletAble = MAX_BULLET;    }

void Player::incBullet() 
{
    if (m_bulletAble >= MAX_BULLET) return;
    m_bulletAble++;
}

bool Player::shoot()
{
    if (m_bulletAble <= 0) return false;

    Bullet* bullet = new Bullet();
    bullet->init(m_position, m_orientation);

    m_bullets.push_back(bullet);

    m_bulletAble--;
    m_bulletShot++;

    return true;
}

void Player::disableBullet(const int index, const bool incScore)
{
    if (incScore)    m_score++;
    deleteBullet(index, false);
}

void Player::moveBullet()
{
    if (m_bulletShot <= 0)   return;

    std::vector<Bullet*>::iterator it;
    for (it = m_bullets.begin(); it != m_bullets.end(); ++it)
        if ((*it)->getInGame())  (*it)->move();

}

void Player::deleteBullet(const int index, const bool deleteAll)
{
    if (m_bulletShot <= 0)   return;
    if (deleteAll)
    {
        std::vector<Bullet*>::iterator it = m_bullets.begin();
        for (int i = 0; i < m_bulletShot; i++)
        {
            delete * it;
            it = m_bullets.erase(it);
        }

        m_bulletShot = 0;
    }
    else
    {
        std::vector<Bullet*>::iterator it = m_bullets.begin() + index;
        delete * it;
        it = m_bullets.erase(it);

        m_bulletShot--;
    }
}

int Player::getBulletPosition(const int index) 
{ 
    std::vector<Bullet*>::iterator it = m_bullets.begin() + index;
    return (*it)->getPosition();
}

Bullet* Player::getBullet(const int index)
{
    std::vector<Bullet*>::iterator it = m_bullets.begin() + index;
    return (*it);
}

int Player::getBulletAble()    {   return m_bulletAble;    }
int Player::getBulletShot()    {   return m_bulletShot;    }
