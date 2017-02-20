#ifndef _HUD_H
#define _HUD_H

class HUD
{
    public:
		enum EPrintComponent
		{
			EPC_Player1 = 'P',
			EPC_Player2 = 'p',
			EPC_Enemy = 'E',
			EPC_Bullet = 'B',
			EPC_World = 'W',
			EPC_ORevive = 'R',
			EPC_OLife = 'L',
			EPC_OBullet = 'b'
		};

		enum EColourConsole
		{
			ECC_BACKGROUND_BLUEDARK_TEXT_GREYDARK = 24,
			ECC_BACKGROUND_BLUEDARK_TEXT_RED = 28,
			ECC_BACKGROUND_BLUE_TEXT_YELLOW = 30,
			ECC_BACKGROUND_BLUEDARK_TEXT_WHITE = 31,
			ECC_BACKGROUND_GREENDARK_TEXT_GREYDARK = 40,
			ECC_BACKGROUND_GREENDARK_TEXT_RED = 44,
			ECC_BACKGROUND_GREENDARK_TEXT_WHITE = 47,
			ECC_BACKGROUND_BLUEMEDIUM_TEXT_WHITE = 151,
			ECC_BACKGROUND_BLUEMEDIUM_TEXT_BLUELIGHT = 155,
			ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED = 156,
			ECC_BACKGROUND_BLUEMEDIUM_TEXT_YELLOW = 158,
			ECC_BACKGROUND_BLUELIGHT_TEXT_RED = 188,
			ECC_BACKGROUND_BLUELIGHT_TEXT_YELLOW = 190,
			ECC_BACKGROUND_WHITE_TEXT_BLACK = 240,
			ECC_BACKGROUND_WHITE_TEXT_BLUEDARK = 241,
			ECC_BACKGROUND_WHITE_TEXT_GREENDARK = 242,
			ECC_BACKGROUND_WHITE_TEXT_GREYDARK = 248,
			ECC_BACKGROUND_WHITE_TEXT_RED = 252,
			ECC_BACKGROUND_WHITE_TEXT_PINK = 253
		};

		HUD();
        ~HUD();

        void        hidecursor(void);
        void        gotoxy(int, int);
        void        setColourConsole(EColourConsole);

        void        start();
        void        playerScreen(const int);
        void        gameOver(std::vector<int>);

        void        background(const int);
        void        backgroundAnimate(const int, int);

        void        printFirstComponent();
        void        printComponent(const char, const int);
        void        printEndComponent();

        void        showStats(const int, const int, const int);
        void        showScore(std::vector<int>);

        const int   getMinCoordAnimateBGX();
        const int   getMaxCoordAnimateBGX();
        const int   getMinCoordAnimateBGY();
        const int   getMaxCoordAnimateBGY();
    private:
        void        resizeWindow();
        void        clear();

        void        printControlMenu();
        void        printSimpleScore(int, const int, int);

        void        drawNumber(const int, const int, int, const bool);
        void        drawP1(const int, int);
        void        drawP2(const int, int);
        void        drawGun(const int, int);
        void        drawHeart(const int, int);
        void        drawCloseStats(const int, int);
        void        drawSpace(const int, int);
        void        drawTotalScore(int);

        const char  WORLD_ICON = '_';
        const char  PLAYER_ICON_R = '>';
        const char  PLAYER_ICON_L = '<';
        const char  BULLET_ICON = '*';
        const char  ENEMY_ICON_1 = '1';
        const char  ENEMY_ICON_2 = '2';
        const char  ENEMY_ICON_3 = '3';
        const char  ENEMY_ICON_4 = '4';
        const char  ENEMY_ICON_5 = '5';
        const char  ENEMY_ICON_6 = '6';
        const char  OBJECT_ICON_REVIVE = 'R';
        const char  OBJECT_ICON_LIFE = 'L';
        const char  OBJECT_ICON_BULLET = 'B';

        const int   COORD_EXIT_Y = 40;
        const int   COORD_EXIT_X = 18;

        const int   COORD_MENU_X = 15;
        const int   COORD_MENU_Y = 5;

        const int   COORD_GAMELINE_X = 25;
        const int   COORD_GAMELINE_Y = 21;
        const int   COORD_SCORE_Y = 9;

        const int   COORD_STATS_X = 13;
        const int   COORD_STATS_P1_Y = 23;
        const int   COORD_STATS_P2_Y = 34;

        const int   MIN_COORD_ANIMATE_BACKGROUND_X = 25;
        const int   MAX_COORD_ANIMATE_BACKGROUND_X = 97;
        const int   MIN_COORD_ANIMATE_BACKGROUND_Y = 16;
        const int   MAX_COORD_ANIMATE_BACKGROUND_Y = 21;

};

#endif /* _HUD_H */

