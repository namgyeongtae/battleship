#include "BattleShip.h"
#include "../GamePlay/player.h"

BattleShipApp::BattleShipApp() {

}

BattleShipApp::~BattleShipApp() {
    
}

void BattleShipApp::Init()
{
    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    defendMap = new BattleShipMap(2, 4);
    m_pMap = new BattleShipMap(2, 16);
    m_pStatPane = new StatPane(30, 3, 30, 6);
    m_pInputPane = new InputPane(30, 15, 30, 4);

    


}

void BattleShipApp::Play()
{
    int count = 0;
    unsigned int timer = 0;
    bool isGameOver = false;
    int AHP = 5;
    int BHP = 4;
    int CHP = 3;
    int DHP = 2;
    int DHP2 = 2;
    while (!isGameOver)
    {
        timer++;

        if (timer % 100000000 == 0)
        {
            int row = rand() % MAP_SIZE;
            int col = rand() % MAP_SIZE;

            if (visited[row][col]) {
                timer = 99999992;
                continue;
            }
            visited[row][col] = true;


            if ((m_pMap->getCharFromMap(row, col) == 'H') || (m_pMap->getCharFromMap(row, col) == 'M'))
            {

                ++count;
            }
            else if (defendMap->getCharFromMap(row, col) == '0')
            {
                //m_pMap->getCharFromMap(input) = 'M';
                m_pMap->setMapData(row, col, 'M');
                ++count;
            }
            else
            {
                switch (defendMap->getCharFromMap(row, col))
                {
                    case 'A':
                        AHP -= 1;
                        break;
                    case 'B':
                        BHP -= 1;
                        break;
                    case 'C':
                        CHP -= 1;
                        break;
                    case 'D':
                        if (DHP <= 0){
                            DHP2 -= 1;
                        }
                        DHP -= 1;

                        break;
                }
                //m_pMap->getCharFromMap(input) = 'H';
                if (AHP == 0 && defendMap->getCharFromMap(row, col) == 'A'){
                    m_pMap->setMapData(row, col, 'A');
                }
                else if (BHP == 0 && defendMap->getCharFromMap(row, col) == 'B'){
                    m_pMap->setMapData(row, col, 'B');
                }
                else if (CHP == 0 && defendMap->getCharFromMap(row, col) == 'C'){
                    m_pMap->setMapData(row, col, 'C');
                }
                else if (DHP == 0 && defendMap->getCharFromMap(row, col) == 'D'){
                    m_pMap->setMapData(row, col, 'D');
                }
                else if (DHP2 == 0 && defendMap->getCharFromMap(row, col) == 'D'){
                     m_pMap->setMapData(row, col, 'D');
                }
                else{
                    m_pMap->setMapData(row, col, 'H');
                }

                ++count;
            }

            m_pMap->Draw();

            if (AHP <= 0 && BHP <= 0 && CHP <= 0 && DHP <= 0 && DHP2 <= 0){
                isGameOver = true;
            }

            wrefresh(m_pInputPane->getWindow());

            timer = 0;
        }
    }
}

void BattleShipApp::Render()
{
    mvprintw(1, 1, "<< Battle Ship Game >>");

    defendMap->Draw();
    m_pMap->Draw();
    m_pStatPane->Draw();
    m_pInputPane->Draw();

    refresh();
}

void BattleShipApp::Destroy()
{
    getch();
    endwin();
    delete m_pMap;
    delete defendMap;
}

void BattleShipApp::traceAlgo()
{
    
}

void BattleShipApp::initVisited()
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            visited[i][j] = false;
        }
    }
}