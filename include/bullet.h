#ifndef _BULLET_H
#define _BULLET_H

class Bullet
{
    public:
		Bullet();
        ~Bullet();

        void    init(int, bool);
        void    reset();

        int     getPosition();

        bool    getOrientation();
        bool    getInGame();

        void    setPosition(int);
        void    setOrientation(bool);
        void    setInGame(bool);

        void    move();
    private:
        int     m_position;
        bool    m_orientation;        // TRUE: Derecha | FALSE: Izquierda
        bool    m_inGame;
};

#endif /* _BULLET_H */

