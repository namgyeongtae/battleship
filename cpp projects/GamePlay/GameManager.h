#pragma once
#include "Ship.h"
#include "Aircraft.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"

class Player;
class BattleShipApp;

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void Init();
    void Play();
    void Render();
    void Destroy();

protected:
    Player* m_Attacker;
    Player* m_Defender;

    BattleShipApp* battleship;
};