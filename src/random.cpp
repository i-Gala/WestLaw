#include "../lib/stdafx.h"
#include "../include/random.h"

#include <time.h>

Random* Random::m_random;

Random::Random()
{
    srand(time(NULL));
}


Random::~Random() {}

Random* Random::getRandomClass()
{
    if (m_random == NULL)    m_random = new Random();
    return m_random;
}

void Random::deleteRandom()
{
    if (m_random != NULL)    delete m_random;
}

int Random::getRandom(int max) {    return rand() % max;   }
