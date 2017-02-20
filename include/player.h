#ifndef PLAYER_H
#define PLAYER_H

class Bullet;
class Player
{
    public:
		Player();
        ~Player();

        void                    reset();
        void                    revive();

        int                     getScore();
        int                     getPosition();
        int                     getLifes();

        bool                    getOrientation();
        bool                    getGameOver();

        void                    setPosition(int);
        void                    setLifes(int);
        void                    setOrientation(bool);

        void                    moveLeft();
        void                    moveRight();

        void                    reloadBullet();
        void                    incBullet();
        void                    incLifes();
        void                    decLifes();
        void                    setScore(int);
        void                    incScore();

        bool                    shoot();
        void                    disableBullet(const int, const bool);
        void                    moveBullet();
        int                     getBulletAble();
        int                     getBulletShot();
        int                     getBulletPosition(const int);
        void                    deleteBullet(const int, const bool);
        Bullet                 *getBullet(const int);
    private:
        std::vector<Bullet *>   m_bullets;
        int                     m_score;
        int                     m_position;
        int                     m_lifes;
        int                     m_bulletAble;
        int                     m_bulletShot;
        bool                    m_orientation;        // TRUE: Derecha | FALSE: Izquierda
        bool                    m_gameOver;
        
};

#endif /* PLAYER_H */

