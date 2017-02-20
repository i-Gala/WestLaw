#include "../lib/stdafx.h"
#include "../include/hud.h"
#include "../include/global.h"

HUD::HUD()
{ 
    hidecursor();
    resizeWindow();
}


HUD::~HUD() { }

/***************************************/
/*            PRINT SCREEN             */
/***************************************/

void HUD::resizeWindow()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1200, 960, TRUE);
}

void HUD::hidecursor(void) 
{
    HANDLE hdl;
    hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO t;
    t.dwSize = 100;
    t.bVisible = false;
    SetConsoleCursorInfo(hdl, &t);
}

void HUD::gotoxy(int x, int y) 
{
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void HUD::setColourConsole(EColourConsole color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void HUD::clear() {    system("cls");    }

/***************************************/
/*                GETS                 */
/***************************************/

const int HUD::getMinCoordAnimateBGX() {    return MIN_COORD_ANIMATE_BACKGROUND_X;    }
const int HUD::getMaxCoordAnimateBGX() {    return MAX_COORD_ANIMATE_BACKGROUND_X;    }
const int HUD::getMinCoordAnimateBGY() {    return MIN_COORD_ANIMATE_BACKGROUND_Y;    }
const int HUD::getMaxCoordAnimateBGY() {    return MAX_COORD_ANIMATE_BACKGROUND_Y;    }

/***************************************/
/*              ASCII ART              */
/***************************************/

void HUD::start()
{
    int x = COORD_MENU_X, y = COORD_MENU_Y;
    setColourConsole(ECC_BACKGROUND_BLUE_TEXT_YELLOW);
    clear();
    gotoxy(x, y);
    printf("           /$$      /$$ /$$$$$$$$  /$$$$$$  /$$$$$$$$       /$$        /$$$$$$  /$$      /$$\n");
    y++;
    gotoxy(x, y);
    printf("          | $$  /$ | $$| $$_____/ /$$__  $$|__  $$__/      | $$       /$$__  $$| $$  /$ | $$\n");
    y++;
    gotoxy(x, y);
    printf("          | $$ /$$$| $$| $$      | $$  \\__/   | $$         | $$      | $$  \\ $$| $$ /$$$| $$\n");
    y++;
    gotoxy(x, y);
    printf("          | $$/$$ $$ $$| $$$$$   |  $$$$$$    | $$         | $$      | $$$$$$$$| $$/$$ $$ $$\n");
    y++;
    gotoxy(x, y);
    printf("          | $$$$_  $$$$| $$__/    \\____  $$   | $$         | $$      | $$__  $$| $$$$_  $$$$\n");
    y++;
    gotoxy(x, y);
    printf("          | $$$/ \\  $$$| $$       /$$  \\ $$   | $$         | $$      | $$  | $$| $$$/ \\  $$$\n");
    y++;
    gotoxy(x, y);
    printf("          | $$/   \\  $$| $$$$$$$$|  $$$$$$/   | $$         | $$$$$$$$| $$  | $$| $$/   \\  $$\n");
    y++;
    gotoxy(x, y);
    printf("          |__/     \\__/|________/ \\______/    |__/         |________/|__/  |__/|__/     \\__/\n\n\n");
    y += 3;
    x += 3;
    gotoxy(x, y);

    printf("                                            .~~~~`\\~~\\\n");
    y++;
    gotoxy(x, y);
    printf("                                           ;       ~~ \\\n");
    y++;
    gotoxy(x, y);
    printf("                                           |           ;\n");
    y++;
    gotoxy(x, y);
    printf("                                       ,--------,______|---.\n");
    y++;
    gotoxy(x, y);
    printf("                                      /          \\-----`    \\\n");
    y++;
    gotoxy(x, y);
    printf("                                      `.__________`-_______-'\n");
    
    printControlMenu();
}

void HUD::playerScreen(const int numberPlayer)
{
    int x = COORD_MENU_X, y = COORD_MENU_Y;
    setColourConsole(ECC_BACKGROUND_BLUE_TEXT_YELLOW);
    clear();
    gotoxy(x, y);
    switch (numberPlayer)
    {
    case 1: // Un jugador registrado
        printf("                       _______     __                .           ");
        y++;
        gotoxy(x, y);
        printf("                      |       \\  _/  \\               |        ");
        y++;
        gotoxy(x, y);
        printf("                      | $$$$$$$\\|   $$               .          ");
        y++;
        gotoxy(x, y);
        printf("                      | $$__/ $$ \\$$$$               |           ");
        y++;
        gotoxy(x, y);
        printf("                      | $$    $$  | $$               .             ");
        y++;
        gotoxy(x, y);
        printf("                      | $$$$$$$   | $$               |             ");
        y++;
        gotoxy(x, y);
        printf("                      | $$       _| $$_              .            ");
        y++;
        gotoxy(x, y);
        printf("                      | $$      |   $$ \\             |      PRESS 'SPACE BAR' TO ADD PLAYER 2");
        y++;
        gotoxy(x, y);
        printf("                       \\$$       \\$$$$$$             .                    __              ");
        y++;
        gotoxy(x, y);
        printf("                                                     |                   /  |                ");
        y++;
        gotoxy(x, y);
        printf("                                                     .                 __$$ |__ ");
        y++;
        gotoxy(x, y);
        printf("                         _____ _____                 |                /  $$    | ");
        y++;
        gotoxy(x, y);
        printf("                        |     |     |                .                $$$$$$$$/   ");
        y++;
        gotoxy(x, y);
        printf("              Move Left |  A  |  D  | Move Right     |                   $$ |      ");
        y++;
        gotoxy(x, y);
        printf("                        |_____|_____|                .                   $$/        ");
        y++;
        gotoxy(x, y);
        printf("                        |     |                      |                               ");
        y++;
        gotoxy(x, y);
        printf("                        |  Z  |  Shoot               .                                ");
        y++;
        gotoxy(x, y);
        printf("                        |_____|                      |          ");
        break;
    case 2: // Dos jugadores registrados
        printf("                       _______     __                .                 _______    ______  ");
        y++;
        gotoxy(x, y);
        printf("                      |       \\  _/  \\               |                /       \\  /      \\ ");
        y++;
        gotoxy(x, y);
        printf("                      | $$$$$$$\\|   $$               .                $$$$$$$  |/$$$$$$  |");
        y++;
        gotoxy(x, y);
        printf("                      | $$__/ $$ \\$$$$               |                $$ |__$$ |$$____$$ |");
        y++;
        gotoxy(x, y);
        printf("                      | $$    $$  | $$               .                $$    $$/  /    $$/ ");
        y++;
        gotoxy(x, y);
        printf("                      | $$$$$$$   | $$               |                $$$$$$$/  /$$$$$$/  ");
        y++;
        gotoxy(x, y);
        printf("                      | $$       _| $$_              .                $$ |      $$ |_____ ");
        y++;
        gotoxy(x, y);
        printf("                      | $$      |   $$ \\             |                $$ |      $$       |");
        y++;
        gotoxy(x, y);
        printf("                       \\$$       \\$$$$$$             .                $$/       $$$$$$$$/ ");
        y++;
        gotoxy(x, y);
        printf("                                                     |                                    ");
        y++;
        gotoxy(x, y);
        printf("                                                     .");
        y++;
        gotoxy(x, y);
        printf("                         _____ _____                 |                   _____ _____                 ");
        y++;
        gotoxy(x, y);
        printf("                        |     |     |                .                  |     |     |                ");
        y++;
        gotoxy(x, y);
        printf("              Move Left |  A  |  D  | Move Right     |        Move Left |  J  |  K  | Move Right     ");
        y++;
        gotoxy(x, y);
        printf("                        |_____|_____|                .                  |_____|_____|                 ");
        y++;
        gotoxy(x, y);
        printf("                        |     |                      |                  |     |                      ");
        y++;
        gotoxy(x, y);
        printf("                        |  Z  |  Shoot               .                  |  M  |  Shoot                 ");
        y++;
        gotoxy(x, y);
        printf("                        |_____|                      |                  |_____|                      ");
        break;
    default:
        break;
    }

    y++;
    gotoxy(x, y);
    printf("                                                     .");
    y++;
    gotoxy(x, y);
    printf("                                                     |");
    y++;
    gotoxy(x, y);
    printf("                                                     .");
    y++;
    gotoxy(x, y);
    printf("                                                     |");
    
    printControlMenu();
}

void HUD::gameOver(std::vector<int> scores)
{
    int x = COORD_MENU_X;
    int y = COORD_MENU_Y;
    int score = 0;
    setColourConsole(ECC_BACKGROUND_BLUE_TEXT_YELLOW);
    clear();
    
    gotoxy(x, y);
    printf("     /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$       $$$$$$\\  $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\  ");
    y++;
    gotoxy(x, y);
    printf("    /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/      $$  __$$\\ $$ |   $$ |$$  _____|$$  __$$\\ ");    
    y++;
    gotoxy(x, y);
    printf("   | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$            $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |");    
    y++;
    gotoxy(x, y);
    printf("   | $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         $$ |  $$ |\\$$\\  $$  |$$$$$\\    $$$$$$$  |");   
    y++;
    gotoxy(x, y);
    printf("   | $$|_  $$| $$__  $$| $$  $$$| $$| $$__/         $$ |  $$ | \\$$\\$$  / $$  __|   $$  __$$< ");    
    y++;
    gotoxy(x, y);
    printf("   | $$  \\ $$| $$  | $$| $$\\  $ | $$| $$            $$ |  $$ |  \\$$$  /  $$ |      $$ |  $$ |");   
    y++;
    gotoxy(x, y);
    printf("   |  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$       $$$$$$  |   \\$  /   $$$$$$$$\\ $$ |  $$ |");   
    y++;
    gotoxy(x, y);
    printf("    \\______/ |__/  |__/|__/     |__/|________/       \\______/     \\_/    \\________|\\__|  \\__|");
    
    y++;
    gotoxy(x, y);
    for (unsigned i = 0; i < scores.size(); i++)
        score += scores[i];

    drawTotalScore(score);

    printControlMenu();
}

void HUD::showStats(const int index, const int life, const int bullets)
{
    int x = COORD_STATS_X;
    int y;
    EColourConsole colourBasic, colourHeart, colourGun;
    switch (index)
    {
    case 0:
        colourBasic = ECC_BACKGROUND_BLUEDARK_TEXT_WHITE;
        setColourConsole(colourBasic);
        y = COORD_STATS_P1_Y;
        drawSpace(x, y);
        x += 1;
        drawSpace(x, y);
        x += 1;
        drawP1(x, y);
        break;
    case 1:
        colourBasic = ECC_BACKGROUND_GREENDARK_TEXT_WHITE;
        setColourConsole(colourBasic);
        y = COORD_STATS_P2_Y;
        drawSpace(x, y);
        x += 1;
        drawSpace(x, y);
        x += 1;
        drawP2(x, y);
    default:    break;
    }

    x += 29;
    drawHeart(x, y);

    x += 21;
    drawNumber(life, x, y, true);

    x += 8;
    drawCloseStats(x, y);

    x += 5;
    drawGun(x, y);

    x += 30;
    drawNumber(bullets, x, y, true);

    x += 8;
    drawCloseStats(x, y);

    x += 5;
    drawSpace(x, y);
}

void HUD::showScore(std::vector<int> scores)
{
    int x;
    if (scores.size() == 1)
    {
        x = 60;
        //for (unsigned i = 0; i < scores.size(); i++)
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_BLACK);
        gotoxy(x, COORD_SCORE_Y);
        printf("SCORE: ");
       
        x += 8;
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_BLUEDARK);
        printSimpleScore(x, COORD_SCORE_Y, scores[0]);
    }
    else
    {
        x = 56;
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_BLACK);
        gotoxy(x, COORD_SCORE_Y);
        printf("SCORE: ");

        x += 8;
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_BLUEDARK);
        printSimpleScore(x, COORD_SCORE_Y, scores[0]);
        for (int i = 1; i < scores.size(); i++)
        {
            x += 3;
            setColourConsole(ECC_BACKGROUND_WHITE_TEXT_BLACK);
            printf(" | ");
            x += 3;
            setColourConsole(ECC_BACKGROUND_WHITE_TEXT_GREENDARK);
            printSimpleScore(x, COORD_SCORE_Y, scores[i]);
        }
    }
}

void HUD::background(const int pnum)
{
    int x = COORD_GAMELINE_X, y = 0;
    setColourConsole(ECC_BACKGROUND_WHITE_TEXT_BLACK);
    clear();
    gotoxy(x, y);
    printf("*-----------------------------------------------------------------------------------*\n");
    y++;
    gotoxy(x, y);

    switch (pnum)
    {
    case 2:
        printf("|                PLAYER 1                  |                PLAYER 2                |\n");
        y++;
        gotoxy(x, y);
        printf("|-----------------------------------------------------------------------------------|\n");
        y++;
        gotoxy(x, y);
        printf("|        %c: MOVER IZQUIERDA                |        %c: MOVER IZQUIERDA              |\n", KEY_MOVE_P1_LEFT_CAP, KEY_MOVE_P2_LEFT_CAP);
        y++;
        gotoxy(x, y);
        printf("|        %c: MOVER DERECHA                  |        %c: MOVER DERECHA                |\n", KEY_MOVE_P1_RIGHT_CAP, KEY_MOVE_P2_RIGHT_CAP);
        y++;
        gotoxy(x, y);
        printf("|        %c: DISPARAR                       |        %c: DISPARAR                     |\n", KEY_SHOOT_P1_CAP, KEY_SHOOT_P2_CAP);
        break;
    case 1:
        printf("|                                     PLAYER 1                                      |\n");
        y++;
        gotoxy(x, y);
        printf("|-----------------------------------------------------------------------------------|\n");
        y++;
        gotoxy(x, y);
        printf("|                               %c: MOVER IZQUIERDA                                  |\n", KEY_MOVE_P1_LEFT_CAP);
        y++;
        gotoxy(x, y);
        printf("|                               %c: MOVER DERECHA                                    |\n", KEY_MOVE_P1_RIGHT_CAP);
        y++;
        gotoxy(x, y);
        printf("|                               %c: DISPARAR                                         |\n", KEY_SHOOT_P1_CAP);
        break;
    default:    break;
    }


    y++;
    gotoxy(x, y);
    printf("|-----------------------------------------------------------------------------------|\n");
    y++;
    gotoxy(x, y);
    printf("|                               ESC: CERRAR EL JUEGO                                |\n");
    y++;
    gotoxy(x, y);
    printf("*-----------------------------------------------------------------------------------*\n");

    y += 3;
    gotoxy(x, y);
    setColourConsole(ECC_BACKGROUND_BLUELIGHT_TEXT_RED);
    printf("                                     @@@@@@@@@                                       \n");

    y++;
    gotoxy(x, y);
    printf("                                  @@");
    setColourConsole(ECC_BACKGROUND_BLUELIGHT_TEXT_YELLOW);
    printf("@@@@@@@@@@");
    setColourConsole(ECC_BACKGROUND_BLUELIGHT_TEXT_RED);
    printf("@@@                                    \n");

    y++;
    gotoxy(x, y);
    printf("                                @@");
    setColourConsole(ECC_BACKGROUND_BLUELIGHT_TEXT_YELLOW);
    printf("@@@@@@@@@@@@@");
    setColourConsole(ECC_BACKGROUND_BLUELIGHT_TEXT_RED);
    printf("@@@                                   \n");

    y++;
    gotoxy(x, y);
    printf("                               @@");
    setColourConsole(ECC_BACKGROUND_BLUELIGHT_TEXT_YELLOW);
    printf("@@@@@@@@@@@@@@@");
    setColourConsole(ECC_BACKGROUND_BLUELIGHT_TEXT_RED);
    printf("@@@                                  \n");

    y++;
    gotoxy(x, y);
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_BLUELIGHT);
    printf("     ~~~~ ~~ ~~~~~ ~~~~~~~~ ~~ ");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED);
    printf("&&");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_YELLOW);
    printf("&&&&&&&&&&&&&&&");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED);
    printf("&&&");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_BLUELIGHT);
    printf(" ~~~~~~~ ~~~~~~~~~~~ ~~~          \n");
}

void HUD::backgroundAnimate(const int x, int y)
{
    gotoxy(x, y);
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_BLUELIGHT);
    printf("     ~         ~~   ~  ~       ");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED);
    printf("~~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_YELLOW);
    printf("~~~~~~~~~~~~~~~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED);
    printf("~~~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_BLUELIGHT);
    printf(" ~       ~~     ~~ ~              \n");

    y++;
    gotoxy(x, y);
    printf("       ~      ~~      ~~ ~~ ~~  ");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED);
    printf("~~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_YELLOW);
    printf("~~~~~~~~~~~ ~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED);
    printf("~~~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_BLUELIGHT);
    printf("  ~     ~~~    ~ ~~~  ~ ~~         \n");

    y++;
    gotoxy(x, y);
    printf("       ~  ~~     ~         ~      ");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED);
    printf("~~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_YELLOW);
    printf("~~~~  ~~ ");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED);
    printf("~~~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_BLUELIGHT);
    printf("       ~~ ~ ~~  ~~ ~                 \n");

    y++;
    gotoxy(x, y);
    printf("     ~  ~       ~ ~      ~           ");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED);
    printf("~~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_YELLOW);
    printf("~~~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_RED);
    printf("~~~");
    setColourConsole(ECC_BACKGROUND_BLUEMEDIUM_TEXT_BLUELIGHT);
    printf("~      ~~  ~             ~~             \n");

    y++;
    gotoxy(x, y);
    printf("           ~             ~        ~      ~      ~~   ~             ~                 \n");
}

void HUD::printFirstComponent()
{
    gotoxy(COORD_GAMELINE_X, COORD_GAMELINE_Y);
    setColourConsole(ECC_BACKGROUND_WHITE_TEXT_BLACK);
    printf("\\");
}

void HUD::printComponent(const char component, const int data)
{
    switch (component)
    {
    case EPC_Player1:
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_BLUEDARK);
        if (data)    printf("%c", PLAYER_ICON_R);
        else         printf("%c", PLAYER_ICON_L);
        break;
    case EPC_Player2:
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_GREENDARK);
        if (data)    printf("%c", PLAYER_ICON_R);
        else         printf("%c", PLAYER_ICON_L);
        break;
    case EPC_Enemy:
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_RED);
        if (data == 1)               printf("%c", ENEMY_ICON_1);
        else if (data == 2)          printf("%c", ENEMY_ICON_2);
        else if (data == 3)          printf("%c", ENEMY_ICON_3);
        else if (data == 4)          printf("%c", ENEMY_ICON_4);
        else if (data == 5)          printf("%c", ENEMY_ICON_5);
        else if (data == 6)          printf("%c", ENEMY_ICON_6);
        break;
    case EPC_Bullet:
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_GREYDARK);
        printf("%c", BULLET_ICON);
        break;
    case EPC_World:
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_BLACK);
        printf("%c", WORLD_ICON);
        break;
    case EPC_ORevive:
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_PINK);
        printf("%c", OBJECT_ICON_REVIVE);
        break;
    case EPC_OLife:
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_PINK);
        printf("%c", OBJECT_ICON_LIFE);
        break;
    case EPC_OBullet:
        setColourConsole(ECC_BACKGROUND_WHITE_TEXT_PINK);
        printf("%c", OBJECT_ICON_BULLET);
        break;

    default:    break;
    }
}

void HUD::printEndComponent()
{
    setColourConsole(ECC_BACKGROUND_WHITE_TEXT_BLACK);
    printf("//");
}

void HUD::printControlMenu()
{
    int x = COORD_EXIT_X;
    int y = COORD_EXIT_Y;
    gotoxy(x, y);
    printf("                                         PRESS 'S' TO START \n");
    
    y++;
    gotoxy(x, y);
    printf("                                        PRESS 'ESC' TO CLOSE\n ");
}

void HUD::printSimpleScore(int x, const int y, int score)
{
    gotoxy(x, y);
    if (score < 100)    printf("0");
    else
    {
        printf("%d", score / 100);
        score -= (score / 100) * 100;
    }

    x++;
    gotoxy(x, y);
    if (score < 10)     printf("0");
    else
    {
        printf("%d", score / 10);
        score -= (score / 10) * 10;
    }

    x++;
    gotoxy(x, y);
    printf("%d", score);
}

void HUD::drawCloseStats(const int x, int y)
{
    gotoxy(x, y);
    printf("---. \n");
    y++;
    gotoxy(x, y);
    printf("-.  |\n");
    y++;
    gotoxy(x, y);
    printf("  | |\n");
    y++;
    gotoxy(x, y);
    printf("  | |\n");
    y++;
    gotoxy(x, y);
    printf("  | |\n");
    y++;
    gotoxy(x, y);
    printf("  | |\n");
    y++;
    gotoxy(x, y);
    printf("  | |\n");
    y++;
    gotoxy(x, y);
    printf("  | |\n");
    y++;
    gotoxy(x, y);
    printf("  | |\n");
    y++;
    gotoxy(x, y);
    printf("--' |\n");
    y++;
    gotoxy(x, y);
    printf("---' ");
}

void HUD::drawNumber(const int number, const int x, int y, const bool design)
{
    if (design)
    {
        gotoxy(x, y);
        printf("--------\n");
        y++;
        gotoxy(x, y);
        printf("--------\n");
        y++;
    }
    gotoxy(x, y);
    switch (number)
    {
    case 1:
        printf("  __    \n");

        y++;
        gotoxy(x, y);
        printf(" /_ |   \n");
        y++;
        gotoxy(x, y);
        printf("  | |   \n");
        y++;
        gotoxy(x, y);
        printf("  | |   \n");
        y++;
        gotoxy(x, y);
        printf("  | |   \n");
        y++;
        gotoxy(x, y);
        printf("  |_|   \n");
        break;
    case 2:
        printf("  ___   \n");
        y++;
        gotoxy(x, y);
        printf(" |__ \\  \n");
        y++;
        gotoxy(x, y);
        printf("    ) | \n");
        y++;
        gotoxy(x, y);
        printf("   / /  \n");
        y++;
        gotoxy(x, y);
        printf("  / /_  \n");
        y++;
        gotoxy(x, y);
        printf(" |____| \n");
        break;
    case 3:
        printf(" ____   \n");
        y++;
        gotoxy(x, y);
        printf("|___ \\  \n");
        y++;
        gotoxy(x, y);
        printf("  __) | \n");
        y++;
        gotoxy(x, y);
        printf(" |__ <  \n");
        y++;
        gotoxy(x, y);
        printf(" ___) | \n");
        y++;
        gotoxy(x, y);
        printf("|____/  \n");
        break;
    case 4:
        printf(" _  _   \n");
        y++;
        gotoxy(x, y);
        printf("| || |  \n");
        y++;
        gotoxy(x, y);
        printf("| || |_ \n");
        y++;
        gotoxy(x, y);
        printf("|__   _|\n");
        y++;
        gotoxy(x, y);
        printf("   | |  \n");
        y++;
        gotoxy(x, y);
        printf("   |_|  \n");
        break;
    case 5:
        printf(" _____  \n");
        y++;
        gotoxy(x, y);
        printf("| ____| \n");
        y++;
        gotoxy(x, y);
        printf("| |__   \n");
        y++;
        gotoxy(x, y);
        printf("|___ \\  \n");
        y++;
        gotoxy(x, y);
        printf(" ___) | \n");
        y++;
        gotoxy(x, y);
        printf("|____/  \n");
        break;
    case 6:
        printf("   __   \n");
        y++;
        gotoxy(x, y);
        printf("  / /   \n");
        y++;
        gotoxy(x, y);
        printf(" / /_   \n");
        y++;
        gotoxy(x, y);
        printf("| '_ \\  \n");
        y++;
        gotoxy(x, y);
        printf("| (_) | \n");
        y++;
        gotoxy(x, y);
        printf(" \\___/  \n");
        break;
    case 7:
        printf(" ______ \n");
        y++;
        gotoxy(x, y);
        printf("|____  |\n");
        y++;
        gotoxy(x, y);
        printf("    / / \n");
        y++;
        gotoxy(x, y);
        printf("   / /  \n");
        y++;
        gotoxy(x, y);
        printf("  / /   \n");
        y++;
        gotoxy(x, y);
        printf(" /_/    \n");
        break;
    case 8:
        printf("  ___   \n");
        y++;
        gotoxy(x, y);
        printf(" / _ \\  \n");
        y++;
        gotoxy(x, y);
        printf("| (_) | \n");
        y++;
        gotoxy(x, y);
        printf(" > _ <  \n");
        y++;
        gotoxy(x, y);
        printf("| (_) | \n");
        y++;
        gotoxy(x, y);
        printf(" \\___/  \n");
        break;
    case 9:
        printf("  ___    \n");
        y++;
        gotoxy(x, y);
        printf(" / _ \\  \n");
        y++;
        gotoxy(x, y);
        printf("| (_) | \n");
        y++;
        gotoxy(x, y);
        printf(" \\__, | \n");
        y++;
        gotoxy(x, y);
        printf("   / /  \n");
        y++;
        gotoxy(x, y);
        printf("  /_/   \n");
        break;
    case 0:
    default:
        printf("  ___  \n");

        y++;
        gotoxy(x, y);
        printf(" / _ \\ \n");

        y++;
        gotoxy(x, y);
        printf("| | | |\n");

        y++;
        gotoxy(x, y);
        printf("| | | |\n");

        y++;
        gotoxy(x, y);
        printf("| |_| |\n");

        y++;
        gotoxy(x, y);
        printf(" \\___/ \n");
        break;
    }
    if (design)
    {
        y++;
        gotoxy(x, y);
        printf("        \n");
        y++;
        gotoxy(x, y);
        printf("--------\n");
        y++;
        gotoxy(x, y);
        printf("--------\n");
    }
}

void HUD::drawP1(const int x, int y) 
{
    gotoxy(x, y);
    printf(".--------------------------. \n");
    y++;
    gotoxy(x, y);
    printf("| .----------------------.  |\n");
    y++;
    gotoxy(x, y);
    printf("| |     _______   __      | |\n");
    y++;
    gotoxy(x, y);
    printf("| |    |_   __ \\ /  |     | |\n");
    y++;
    gotoxy(x, y);
    printf("| |      | |__) | | |     | |\n");
    y++;
    gotoxy(x, y);
    printf("| |      |  ___/  | |     | |\n");
    y++;
    gotoxy(x, y);
    printf("| |     _| |_    _| |_    | |\n");
    y++;
    gotoxy(x, y);
    printf("| |    |_____|  |_____|   | |\n");
    y++;
    gotoxy(x, y);
    printf("| |                       | |\n");
    y++;
    gotoxy(x, y);
    printf("| '-----------------------' |\n");
    y++;
    gotoxy(x, y);
    printf(" '-------------------------' \n");
}

void HUD::drawP2(const int x, int y)
{
    gotoxy(x, y);
    printf(".--------------------------. \n");
    y++;
    gotoxy(x, y);
    printf("| .----------------------.  |\n");
    y++;
    gotoxy(x, y);
    printf("| |   _______    _____    | |\n");
    y++;
    gotoxy(x, y);
    printf("| |  |_   __ \\  / ___ `.  | |\n");
    y++;
    gotoxy(x, y);
    printf("| |    | |__) ||_/___) |  | |\n");
    y++;
    gotoxy(x, y);
    printf("| |    |  ___/  .'____.'  | |\n");
    y++;
    gotoxy(x, y);
    printf("| |   _| |_    / /_____   | |\n");
    y++;
    gotoxy(x, y);
    printf("| |  |_____|   |_______|  | |\n");
    y++;
    gotoxy(x, y);
    printf("| |                       | |\n");
    y++;
    gotoxy(x, y);
    printf("| '-----------------------' |\n");
    y++;
    gotoxy(x, y);
    printf(" '-------------------------' \n");
}

void HUD::drawGun(const int x, int y)
{
    gotoxy(x, y);
    printf(".-----------------------------\n");
    y++;
    gotoxy(x, y);
    printf(" .----------------------------\n");
    y++;
    gotoxy(x, y);
    printf(" |          _______________   \n");
    y++;
    gotoxy(x, y);
    printf(" |        <#|=====|_______/   \n");
    y++;
    gotoxy(x, y);
    printf(" |       / C|=====|---'       \n");
    y++;
    gotoxy(x, y);
    printf(" |      /   |-|-|~            \n");
    y++;
    gotoxy(x, y);
    printf(" |     /    /---'             \n");
    y++;
    gotoxy(x, y);
    printf(" |    |____|                  \n");
    y++;
    gotoxy(x, y);
    printf(" |                            \n");
    y++;
    gotoxy(x, y);
    printf(" '----------------------------\n");
    y++;
    gotoxy(x, y);
    printf("'-----------------------------\n");
}

void HUD::drawHeart(const int x, int y)
{
    gotoxy(x, y);
    printf(".--------------------\n");
    y++;
    gotoxy(x, y);
    printf(" .-------------------\n");
    y++;
    gotoxy(x, y);
    printf(" |                   \n");
    y++;
    gotoxy(x, y);
    printf(" |    ,d88b.d88b,    \n");
    y++;
    gotoxy(x, y);
    printf(" |    88888888888    \n");
    y++;
    gotoxy(x, y);
    printf(" |    `Y8888888Y'    \n");
    y++;
    gotoxy(x, y);
    printf(" |      `Y888Y'      \n");
    y++;
    gotoxy(x, y);
    printf(" |        `Y'        \n");
    y++;
    gotoxy(x, y);
    printf(" |                   \n");
    y++;
    gotoxy(x, y);
    printf(" '-------------------\n");
    y++;
    gotoxy(x, y);
    printf("'--------------------");
}

void HUD::drawSpace(const int x, int y)
{
    gotoxy(x, y);
    printf(" \n");
    y++;
    gotoxy(x, y);
    printf(" \n");
    y++;
    gotoxy(x, y);
    printf(" \n");
    y++;
    gotoxy(x, y);
    printf(" \n");
    y++;
    gotoxy(x, y);
    printf(" \n");
    y++;
    gotoxy(x, y);
    printf(" \n");
    y++;
    gotoxy(x, y);
    printf(" \n");
    y++;
    gotoxy(x, y);
    printf(" \n");
    y++;
    gotoxy(x, y);
    printf(" \n");
    y++;
    gotoxy(x, y);
    printf(" \n");
    y++;
    gotoxy(x, y);
    printf(" ");
}

void HUD::drawTotalScore(int score)
{
    int x = 5;
    int y = 20;

    gotoxy(x, y);
    printf(" _________     ____     _________       __        _____            _______     ______     ____     _______      _________     ");
    y++;
    gotoxy(x, y);
    printf("|  _   _  |  .'    `.  |  _   _  |     /  \\      |_   _|          /  ___  |  .' ___  |  .'    `.  |_   __ \\    |_   ___  |  _ ");
    y++;
    gotoxy(x, y);
    printf("|_/ | | \\_| /  .--.  \\ |_/ | | \\_|    / /\\ \\       | |           |  (__ \\_| / .'   \\_| /  .--.  \\   | |__) |     | |_  \\_| (_)");
    y++;
    gotoxy(x, y);
    printf("    | |     | |    | |     | |       / ____ \\      | |   _        '.___`-.  | |        | |    | |   |  __ /      |  _|  _   _ ");
    y++;
    gotoxy(x, y);
    printf("   _| |_    \\  `--'  /    _| |_    _/ /    \\ \\_   _| |__/ |      |`\\____) | \\ `.___.'\\ \\  `--'  /  _| |  \\ \\_   _| |___/ | (_)");
    y++;
    gotoxy(x, y);
    printf("  |_____|    `.____.'    |_____|  |____|  |____| |________|      |_______.'  `._____.'  `.____.'  |____| |___| |_________|    ");
    
    y += 2;
    gotoxy(x, y);

    if (score < 100)     drawNumber(0, 58, y, false);
    else
    {
        drawNumber(score / 100, 68, y, false);
        score -= (score / 100) * 100;
    }

    if (score < 10)     drawNumber(0, 65, y, false);
    else
    {
        drawNumber(score / 10, 65, y, false);
        score -= (score / 10) * 10;
    }

    drawNumber(score, 72, y, false);
}