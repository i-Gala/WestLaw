#include "../lib/stdafx.h"
#include "../include/animationmanager.h"
#include "../include/hud.h"
#include "../include/random.h"

AnimationManager::AnimationManager():
    m_delete(true),
    m_active(false),
    m_count(0) 
{ 
    m_hud = new HUD();
}

AnimationManager::AnimationManager(HUD * h) :
    m_hud(h),
    m_delete(false),
    m_active(false),
    m_count(0) {}


AnimationManager::~AnimationManager()
{
    if (m_delete) delete m_hud;
}

/***************************************/
/*                OLAS                 */
/***************************************/

void AnimationManager::AnimationWaves() 
{
    if (!m_active)
    {
        const int min_y = m_hud->getMinCoordAnimateBGY();
        const int max_y = m_hud->getMaxCoordAnimateBGY();
        const int min_x = m_hud->getMinCoordAnimateBGX() + 3;    // Sumamos los spacebar incluidos en la imagen ASCII
        const int max_x = m_hud->getMaxCoordAnimateBGX() - 3;    // Restamos los spacebar incluidos en la imagen ASCII

        const int tam_y = max_y - min_y;
        const int tam_x = max_x - min_y;

        int new_waves = Random::getRandomClass()->getRandom(MAX_WAVES);
        int wave_x = 0, wave_y = 0;
        int coord_x = 0, coord_y = 0;

        m_hud->backgroundAnimate(m_hud->getMinCoordAnimateBGX(), min_y);
        m_hud->setColourConsole(HUD::ECC_BACKGROUND_BLUEMEDIUM_TEXT_WHITE);

        for (int i = 0; i < new_waves; i++) 
        {
            coord_x = Random::getRandomClass()->getRandom(tam_x) + min_x;
            coord_y = Random::getRandomClass()->getRandom(tam_y) + min_y;

            m_hud->gotoxy(coord_x, coord_y);
            printf("~");
        }

        m_active = true;
    }
    else    incCount();
}

/***************************************/
/*              CONTADOR               */
/***************************************/


void AnimationManager::incCount() 
{
    m_count++;

    if (m_count > MAX_TIME_TEXT)
    {
        m_active = false;
        m_count = 0;
    }
}

int AnimationManager::getCount()   {    return m_count;    }

/***************************************/
/*             ACTIVADOR               */
/***************************************/

bool AnimationManager::getActive() {    return m_active;   }

