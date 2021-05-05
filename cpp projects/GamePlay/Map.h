#pragma once
#include    "../commonHeader.h"

class Map
{
public:
    Map();
    ~Map();

    ShipType GetData(const Position& pos)
    {
        if (pos.x >= MAP_SIZE || pos.y >= MAP_SIZE || pos.x < 0 || pos.y < 0)
        {
            return DATA_ERROR;
        }
        return m_data[pos.x][pos.y];
    }
    ShipType getType(int row, int col) {return m_data[row][col];}
    void setType(int row, int col, ShipType type) {m_data[row][col] = type;}
protected:
    ShipType m_data[MAP_SIZE][MAP_SIZE];
};