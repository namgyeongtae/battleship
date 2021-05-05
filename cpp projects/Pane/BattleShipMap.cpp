#include "BattleShipMap.h"

BattleShipMap::BattleShipMap(int x, int y)
    :Pane(x, y, MAP_SIZE + 3, MAP_SIZE + 2)
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; ++j)
        {
            m_mapData[i][j] = '0';
        }
    }

    for (int i = 0; i < MAP_SIZE; ++i)
    {
        mvprintw(i + 1 + m_y, m_x - 1, "%c", 'A' + i);
        mvprintw(m_y + m_height, m_x + 2 + i, "%d", 1 + i);
    }

    mvwprintw(m_pWindow, 0, 3, "<MAP>");
}

BattleShipMap::~BattleShipMap()
{

}

void BattleShipMap::Draw()
{
    wattron(m_pWindow, COLOR_PAIR(1));
    for (int i = 0; i < MAP_SIZE; ++i)
    {
        for (int j = 0; j < MAP_SIZE; ++j)
        {
            mvwprintw(m_pWindow, i + 1, j + 2, "%c", m_mapData[i][j]);
        }
    }
    wattroff(m_pWindow, COLOR_PAIR(1));

    wrefresh(m_pWindow);
}

char& BattleShipMap::getCharFromMap(char const cmd[2])
{
    if (cmd[0] <= 72 && cmd[0] >= 65 && cmd[1] < '9' && cmd[1] > '0'){
        return m_mapData[cmd[0] - 65][cmd[1] - 48 - 1];
    }
    else if(cmd[0] <= 104 && cmd[0] >= 97 && cmd[1] < '9' && cmd[1] > '0'){
        return m_mapData[cmd[0] - 97][cmd[1] - 48 - 1];
    }
}

char& BattleShipMap::getCharFromMap(const int row, const int col)
{
    if (row >= 0 && col >= 0 && row < MAP_SIZE && col < MAP_SIZE)
    {
        return m_mapData[row][col];
    }
}