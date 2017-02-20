#ifndef GAME_H
#define GAME_H

#include "global.h"

class ObjectManager;
class AnimationManager;
class Input;
class HUD;
class Collision;
class Enemy;
class Player;
class Game
{
    public:
		enum EScreen { ES_Start, ES_PlayerSelect, ES_Play, ES_GameOver };

        Game();
        ~Game();
        void                    start();
    private:
        void                    reset();

        void                    startScreen();
        void                    playerSelectScreen();

        void                    play();
        void                    gameOver();

        bool                    collisionBulletEnemies(const int, const int);
        void                    collisionPlayerEnemies(const int);
        void                    collisionPlayerObjects(const int);

        bool                    playerMovement();
        bool                    keyboardMenu();
        bool                    keyboardPlayerSelect();

        void                    updateHUD();

        void                    addEnemy();
        void                    addEnemy(const bool);
        void                    deleteEnemy(const int, const bool);
        void                    deleteEnemy(std::vector<Enemy*>::iterator);

        void                    addObject();
        void                    deleteObject(const int, const bool);
        void                    deleteObject(std::vector<ObjectManager*>::iterator);

        AnimationManager               *m_animationManager;
        Collision                      *m_collision;
        Player                         *m_player[MAX_PLAYER];
        HUD                            *m_hud;
        Input                          *m_input;
							           
        std::vector<Enemy *>           m_enemies;
        std::vector<ObjectManager*>    m_objects;

        bool                           m_exit;           // Cerrar juego
        EScreen                        m_screen;         // Pantalla actual
								       
        int                            m_playerNumber;   // Número de jugadores en partida
        int                            m_objectCount;    // Número de objetos disponibles en el mapa
        int                            m_enemyCount;     // Número de enemigos en el mapa
								       
        const int                      ENEMY_WAIT = 1100;   // Tiempo de espera para generar un nuevo enemigo
        const int                      OBJECT_WAIT = 500; // Tiempo de espera para generar un nuevo objeto
        const unsigned int             FPS = 20;
        const unsigned int             MILISEC_PER_FRAME = 1000 / FPS;
};

#endif /* GAME_H */

