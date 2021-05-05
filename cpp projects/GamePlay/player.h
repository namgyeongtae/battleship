#pragma once
#include "../commonHeader.h"

class Map;
class Ship;

#define SHIPS std::vector<Ship*>

class Player
{
public:
    Player();
    ~Player();

    //Defender
    void SetupShips(const SHIPS& ships);
    HitResult HitCheck(const Position& pos);

    //Attacker
    Position GetAttackPos();
    Map* getMap() {return m_Map;}

protected:
    Map* m_Map;
    SHIPS m_Ships;
};
