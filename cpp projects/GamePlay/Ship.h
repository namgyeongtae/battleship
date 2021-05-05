#pragma once
#include "../commonHeader.h"

class Ship
{
public:
    Ship(int length, ShipType type);
    virtual ~Ship();

    int Getlength() const { return m_length; }
    ShipType GetType() const {return m_Type;}
    void SetPosition(int index, const Position& pos);
    vector<Position> GetPosition() {return m_Pos;}

protected:
    ShipType m_Type;
    int m_length;
    vector<Position> m_Pos;

};