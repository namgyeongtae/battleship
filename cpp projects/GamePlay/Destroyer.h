#pragma once
#pragma once
#include "Ship.h"

class Destroyer : public Ship
{
public:
    Destroyer();
    ~Destroyer();

protected:
    ShipType m_Type;
};