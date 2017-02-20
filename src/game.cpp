#include "../lib/stdafx.h"
#include "../include/game.h"
#include "../include/hud.h"
#include "../include/input.h"
#include "../include/animationmanager.h"
#include "../include/objectmanager.h"
#include "../include/enemy.h"
#include "../include/player.h"
#include "../include/collision.h"

Game::Game():
    m_enemyCount(0),
    m_playerNumber(1),
    m_exit(false)
{
    for(int i = 0; i < MAX_PLAYER; i++)
        m_player[i] = new Player();

    m_hud = new HUD();
    m_input = new Input();
    m_collision = new Collision();
    m_animationManager = new AnimationManager(m_hud);

}


Game::~Game()
{
    for (int i = 0; i < MAX_PLAYER; i++)
        delete m_player[i];

    delete m_hud;
    delete m_input;
    delete m_collision;
    delete m_animationManager;

    deleteEnemy(NULL, true);
    deleteObject(NULL, true);
}

void Game::reset() 
{
    for (int i = 0; i < MAX_PLAYER; i++)
        m_player[i]->reset();

    deleteEnemy(NULL, true);
    deleteObject(NULL, true);
}

/***************************************/
/*                GAME                 */
/***************************************/

void Game::start() 
{
    while (!m_exit)
    {
        m_hud->hidecursor();
        switch (m_screen)
        {
            case ES_Start:          startScreen();          break;
            case ES_PlayerSelect:   playerSelectScreen();   break;
            case ES_Play:           play();                 break;
            case ES_GameOver:       gameOver();             break;
            default:                                        break;
        }
    }
}

void Game::startScreen()
{
    bool valid = false;

    m_hud->start();
    while (!valid)
    {
        valid = m_input->readKeyboard();
        if (valid)    valid = keyboardMenu();
    }
}

void Game::playerSelectScreen()
{
    bool valid = false;

    m_hud->playerScreen(m_playerNumber);
    while (!valid)
    {
        valid = m_input->readKeyboard();
        if (valid)    valid = keyboardPlayerSelect();
    }
}

void Game::play() 
{
    bool exit = false;
    bool read_keyboard = false;
    int  enemy_wait = 0;
    int  object_wait = 0;

    reset();

    m_hud->background(m_playerNumber);
    m_hud->backgroundAnimate(m_hud->getMinCoordAnimateBGX(), m_hud->getMinCoordAnimateBGY());
    
    if (m_playerNumber > 1)
    {
        for (int i = 0; i < m_playerNumber; i++)
        {
            if (i % 2)    addEnemy(true);
            else          addEnemy(false);
        }

        for (int i = 1; i < m_playerNumber; i++)
        {
            if (i % 2)    m_player[i]->moveLeft();
            else          m_player[i]->moveRight();
        }
    }
    else    addEnemy();

    while (!exit) {
        read_keyboard = m_input->readKeyboard();
        if (read_keyboard)    exit = playerMovement();

        if (!exit) 
        {
            // Actualizar movimiento balas
            for (int i = 0; i < m_playerNumber; i++)
            {
                m_player[i]->moveBullet();
                
                if (!m_player[i]->getGameOver() && m_player[i]->getBulletShot() > 0 && m_enemyCount > 0)
                {
                    bool collision = false;
                    for (int j = 0; j < m_player[i]->getBulletShot() && !collision; j++)
                        collision = collisionBulletEnemies(i, j);
                }
            }

            // Actualizar movimiento enemigos
            if (m_enemyCount > 0)
                for (std::vector<Enemy*>::iterator it = m_enemies.begin(); it != m_enemies.end(); ++it)
                {
                    int positionEnemy = 999999;
                    for (int j = 0; j < m_playerNumber; j++)
                        if (!m_player[j]->getGameOver() && m_player[j]->getPosition() < positionEnemy)    positionEnemy = m_player[j]->getPosition();
                    (*it)->followPlayer(positionEnemy);
                }

            // Actualizar colisiones
            for (int i = 0; i < m_playerNumber; i++)
            {
                if (!m_player[i]->getGameOver())
                {
                    if (m_player[i]->getBulletShot() > 0 && m_enemyCount > 0)
                    {
                        bool collision = false;
                        for (int j = 0; j < m_player[i]->getBulletShot() && !collision; j++)
                            collision = collisionBulletEnemies(i, j);
                    }
                    collisionPlayerEnemies(i);
                    if(m_objectCount > 0)    collisionPlayerObjects(i);
                }
            }

            // Agregar nuevos enemigos
            if (enemy_wait >= ENEMY_WAIT / m_playerNumber)
            {
                addEnemy();
                enemy_wait = 0;
            }

            // Agregar nuevos objetos
            if (object_wait >= OBJECT_WAIT / m_playerNumber)
            {
                if (m_objectCount < MAX_OBJECT - 1) addObject();
                object_wait = 0;
            }

            // Actualizar HUD
            updateHUD();

            // Comprobar GAME OVER
            exit = true;
            for (int i = 0; i < m_playerNumber; i++)
                if (!m_player[i]->getGameOver())    exit = false;
        }
        Sleep(MILISEC_PER_FRAME);
        m_animationManager->AnimationWaves();

        enemy_wait += MILISEC_PER_FRAME;
        object_wait += MILISEC_PER_FRAME;

        if (exit)    m_screen = ES_GameOver;
    }
}

void Game::gameOver() 
{
    bool valid = false;
    std::vector<int> scores;

    for (int i = 0; i < m_playerNumber; i++)
        scores.push_back(m_player[i]->getScore());

    m_hud->gameOver(scores);
    while (!valid)
    {
        valid = m_input->readKeyboard();
        if (valid)    valid = keyboardMenu();
    }
}

/***************************************/
/*             COLISIONES              */
/***************************************/

bool Game::collisionBulletEnemies(const int pindex, const int bindex)
{
    for (std::vector<Enemy*>::iterator it = m_enemies.begin(); it != m_enemies.end(); ++it)
        if (m_collision->getCollision1D(m_player[pindex]->getBulletPosition(bindex), (*it)->getPosition()))
        {
            bool dead;
            
            // Actualizar enemigo
            (*it)->wounded();
            dead = (*it)->getDead();

            if (dead)   deleteEnemy(it);

            // Actualizar bala
            m_player[pindex]->disableBullet(bindex, dead);

            return true;
        }

    return false;
}

void Game::collisionPlayerEnemies(const int pindex) 
{
    for (std::vector<Enemy*>::iterator it = m_enemies.begin(); it != m_enemies.end(); ++it)
        if (m_collision->getCollision1D(m_player[pindex]->getPosition(), (*it)->getPosition()))
        {
            m_player[pindex]->decLifes();
            deleteEnemy(it);
            return;
        }
}

void Game::collisionPlayerObjects(const int pindex)
{
    for (std::vector<ObjectManager*>::iterator it = m_objects.begin(); it != m_objects.end(); ++it)
    {
        if (m_collision->getCollision1D(m_player[pindex]->getPosition(), (*it)->getPosition()))
        {
            switch ((*it)->getType())
            {
                case ObjectManager::EO_BULLET:    m_player[pindex]->reloadBullet();     break;
                case ObjectManager::EO_LIFE:      m_player[pindex]->incLifes();         break;
                case ObjectManager::EO_REVIVE:
                    for (int i = 0; i < m_playerNumber; i++)
                        if (i != pindex)
                            if (m_player[i]->getGameOver())    m_player[i]->revive();
                    break;
            }
            deleteObject(it);
            return;
        }
    }
}

/***************************************/
/*              KEYBOARD               */
/***************************************/

bool Game::playerMovement() 
{
    bool exit = false;

    switch (m_input->getKey()) 
    {
        // Mover PLAYER 1 izquierda
        case KEY_MOVE_P1_LEFT:
        case KEY_MOVE_P1_LEFT_CAP:
            if (!m_player[0]->getGameOver())
            {
                m_player[0]->moveLeft();
                if (m_player[0]->getPosition() == m_player[1]->getPosition()) m_player[1]->moveRight();
                else                                                          collisionPlayerEnemies(0);
            }
            break;
        // Mover PLAYER 1 derecha
        case KEY_MOVE_P1_RIGHT:
        case KEY_MOVE_P1_RIGHT_CAP:
            if (!m_player[0]->getGameOver())
            {
                m_player[0]->moveRight();
                if (m_player[0]->getPosition() == m_player[1]->getPosition()) m_player[1]->moveLeft();
                else                                                          collisionPlayerEnemies(0);
            }
            break;
        // Disparar PLAYER 1
        case KEY_SHOOT_P1:
        case KEY_SHOOT_P1_CAP:
            if (!m_player[0]->getGameOver())                                   m_player[0]->shoot();
            break;
            // Mover PLAYER 2 izquierda
        case KEY_MOVE_P2_LEFT:
        case KEY_MOVE_P2_LEFT_CAP:
            if (!m_player[1]->getGameOver())
            {
                m_player[1]->moveLeft();
                if (m_player[0]->getPosition() == m_player[1]->getPosition()) m_player[0]->moveRight();
                else                                                          collisionPlayerEnemies(1);
            }
            break;
            // Mover PLAYER 2 derecha
        case KEY_MOVE_P2_RIGHT:
        case KEY_MOVE_P2_RIGHT_CAP:
            if (!m_player[1]->getGameOver())
            {
                m_player[1]->moveRight();
                if (m_player[0]->getPosition() == m_player[1]->getPosition()) m_player[0]->moveLeft();
                else                                                          collisionPlayerEnemies(1);
            }
            break;
            // Disparar PLAYER 2
        case KEY_SHOOT_P2:
        case KEY_SHOOT_P2_CAP:
            if (!m_player[1]->getGameOver())                                   m_player[1]->shoot();
            break;
        // Salir
        case KEY_EXIT:
            exit = true;
            break;
        default:    break;
    }

    return exit;
}

bool Game::keyboardMenu() 
{
    bool valid = true;;
    switch (m_input->getKey())
    {
        // Cerrar el juego
        case KEY_EXIT:      m_exit = true;                 break;
        // Comenzar partida
        case KEY_START:
        case KEY_START_CAP: m_screen = ES_PlayerSelect;    break;
        default:            valid = false;               break;
    }
    return valid;
}

bool Game::keyboardPlayerSelect() 
{
    bool valid = true;
    switch (m_input->getKey()) 
    {
        // Cerrar el juego
        case KEY_EXIT:      m_exit = true;         break;
        // Comenzar partida
        case KEY_START:
        case KEY_START_CAP: m_screen = ES_Play;    break;
        // Agregar segundo jugador
        case KEY_ADD_PLAYER:
            if (m_playerNumber == 1)    m_playerNumber++;
            else                        m_playerNumber--;
            break;
        default:            valid = false;       break;
    }
    return valid;
}

/***************************************/
/*               ENEMY                 */
/***************************************/

void Game::addEnemy()
{
    Enemy* enemy = new Enemy();
    enemy->reset();
    m_enemies.push_back(enemy);

    m_enemyCount++;
}

void Game::addEnemy(const bool orientation)
{
    Enemy* enemy = new Enemy();
    enemy->reset(orientation);
    m_enemies.push_back(enemy);

    m_enemyCount++;
}

void Game::deleteEnemy(const int index, const bool deleteAll)
{
    if (m_enemyCount <= 0)    return;

    if (deleteAll)
    {
        std::vector<Enemy*>::iterator it = m_enemies.begin();
        for (int i = 0; i < m_enemyCount; i++)
        {
            delete * it;
            it = m_enemies.erase(it);
        }

        m_enemyCount = 0;
    }
    else
    {
        std::vector<Enemy*>::iterator it = m_enemies.begin() + index;

        delete * it;
        it = m_enemies.erase(it);

        m_enemyCount--;
    }
}

void Game::deleteEnemy(std::vector<Enemy*>::iterator it)
{
    delete * it;
    it = m_enemies.erase(it);
    m_enemyCount--;
}


/***************************************/
/*              OBJECT                 */
/***************************************/

void Game::addObject()
{
    if (m_objectCount >= MAX_OBJECT)   return;

    ObjectManager* object = new ObjectManager();
    
    if(m_playerNumber > 1) object->generateObject(true);
    else                   object->generateObject(false);

    m_objects.push_back(object);

    m_objectCount++;
}

void Game::deleteObject(const int index, const bool deleteAll)
{
    if (m_objectCount <= 0)    return;

    if (deleteAll)
    {
        std::vector<ObjectManager*>::iterator it = m_objects.begin();
        for (int i = 0; i < m_objectCount; i++)
        {
            delete * it;
            it = m_objects.erase(it);
        }

        m_objectCount = 0;
    }
    else
    {
        std::vector<ObjectManager*>::iterator it = m_objects.begin() + index;

        delete * it;
        it = m_objects.erase(it);

        m_objectCount--;
    }
}

void Game::deleteObject(std::vector<ObjectManager*>::iterator it)
{
    delete * it;
    it = m_objects.erase(it);
    m_objectCount--;
}

/***************************************/
/*                HUD                  */
/***************************************/

void Game::updateHUD()
{
    std::vector<int> scores;

    m_hud->printFirstComponent();

    for (int i = 0; i <= TAM_WORLD; i++)
    {
        bool print = false;

        // Dibujar PLAYER
        for (int j = 0; j < m_playerNumber && !print; j++)
        {
            if (!m_player[j]->getGameOver() && i == m_player[j]->getPosition())
            {
                print = true;
                switch (j)
                {
                    case 0:    m_hud->printComponent(HUD::EPC_Player1, m_player[j]->getOrientation());    break;
                    case 1:    m_hud->printComponent(HUD::EPC_Player2, m_player[j]->getOrientation());    break;
                    default:   break;
                }
            }
        }

        // Dibujar BULLET
        for (int j = 0; j < m_playerNumber && !print; j++)
            if (!print && m_player[j]->getBulletShot() > 0)
                for (int k = 0; k < m_player[j]->getBulletShot() && !print; k++)
                    if (i == m_player[j]->getBulletPosition(k)) 
                    {
                        m_hud->printComponent(HUD::EPC_Bullet, false);
                        print = true;
                    }

        // Dibujar ENEMY
        if (m_enemyCount > 0)
            for (std::vector<Enemy*>::iterator it = m_enemies.begin(); it != m_enemies.end(); ++it)
                if (!print && i == (*it)->getPosition()) 
                {
                    m_hud->printComponent(HUD::EPC_Enemy, (*it)->getLifes());
                    print = true;
                }

        // Dibujar OBJECT
        if(m_objectCount > 0 && !print)
            for (std::vector<ObjectManager*>::iterator it = m_objects.begin(); it != m_objects.end() && !print; ++it)
                if (!print && i == (*it)->getPosition())
                {
                    switch ((*it)->getType())
                    {
                        case ObjectManager::EO_REVIVE:    m_hud->printComponent(HUD::EPC_ORevive, false);     break;
                        case ObjectManager::EO_LIFE:      m_hud->printComponent(HUD::EPC_OLife, false);       break;
                        case ObjectManager::EO_BULLET:    m_hud->printComponent(HUD::EPC_OBullet, false);     break;
                    }
                    print = true;
                }

        // Dibujar WORLD
        if (!print)    m_hud->printComponent(HUD::EPC_World, false);
    }
    m_hud->printEndComponent();

    for(int i = 0; i < m_playerNumber; i++)
    {
        m_hud->showStats(i, m_player[i]->getLifes(), m_player[i]->getBulletAble());
        scores.push_back(m_player[i]->getScore());
    }

    m_hud->showScore(scores);
}
