#pragma once
#include "Ship.h"

class Cruiser : public Ship
{
public:
    Cruiser();
    ~Cruiser();

protected:
    ShipType m_Type;
};