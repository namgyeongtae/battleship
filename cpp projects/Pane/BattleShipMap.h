#pragma once
#include "Pane.h"
#include "../commonHeader.h"

class BattleShipMap : public Pane
{
public:
    BattleShipMap(int x, int y);
    ~BattleShipMap();

    void Draw();
    char getMapData(int row, int col) {return m_mapData[row][col];}
    void setMapData(int row, int col, char c) { m_mapData[row][col] = c; }

    char& getCharFromMap(char const cmd[2]);
    char& getCharFromMap(const int row, const int col);
protected:
    char m_mapData[MAP_SIZE][MAP_SIZE];

};


