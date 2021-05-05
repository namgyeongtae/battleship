#pragma once
#include "Ship.h"

class Aircraft : public Ship
{
public:
    Aircraft();
    ~Aircraft();
protected:
    ShipType m_Type;

};