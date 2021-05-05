#pragma once
#include "Ship.h"

class BattleShip : public Ship
{
public:
    BattleShip();
    ~BattleShip();
protected:
    ShipType m_Type;
};