#ifndef _ENEMY_H
#define _ENEMY_H

class Enemy
{
    public:
		Enemy();
		Enemy(int, int);
        ~Enemy();

        void         reset();
        void         reset(const bool);
        void         reset(const int, const int);
                     
        int          getPosition();
        int          getLifes();
                     
        bool         getOrientation();
        bool         getDead();
                     
        void         setPosition(int);
        void         setOrientation(bool);
        void         setLifes(int);
                     
        void         decLifes();
        void         followPlayer(int);
        void         wounded();
    private:
        int          m_position;
        int          m_lifes;
        bool         m_orientation;        // TRUE: Derecha | FALSE: Izquierda
        bool         m_dead;

        const int    ENEMY_RECOIL = 3;
};

#endif /* _ENEMY_H */
