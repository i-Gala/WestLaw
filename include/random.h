#ifndef RANDOM_H
#define RANDOM_H

class Random
{
    public:
        int                getRandom(int);
        void               deleteRandom();
        static Random     *getRandomClass();
    private:			  
        static Random     *m_random;

		Random();
        ~Random();
};

#endif /* RANDOM_H */

