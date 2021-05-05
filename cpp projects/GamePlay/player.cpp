#include "player.h"
#include "Map.h"
#include "Ship.h"

Player::Player()
{
    m_Map = new Map();
}

Player::~Player()
{
    delete m_Map;

    for (auto pShip : m_Ships)
    {
        if(pShip)
        {
            delete pShip;
        }
    }
    m_Ships.clear();
}

void Player::SetupShips(const SHIPS& ships)
{
    m_Ships = ships;

    for (auto pShip : m_Ships)
    {
        srand((unsigned)time(NULL));
        
        while (true)
        {
            Position pos;
            pos.x = rand() % MAP_SIZE;
            pos.y = rand() % MAP_SIZE;

            ShipType dataType = m_Map->GetData(pos);
            if (dataType != DATA_NONE)
            {
                continue;
            }

            Position dir;

            if (rand() % 2)
            {
                dir.x = rand()%2 ? 1 : -1;
            }
            else{
                dir.y = rand()%2 ? 1 : -1;
            }

            pos.x += dir.x;
            pos.y += dir.y;

            bool bSuccess = true;

            for (int i = 0; i < pShip->Getlength(); i++)
            {
                pos.x += dir.x;
                pos.y += dir.y;
                ShipType dataType = m_Map->GetData(pos);
                if (dataType != DATA_NONE)
                {
                    bSuccess = false;
                    break;
                }
                pShip->SetPosition(i, pos);
            }
            if (bSuccess)
            {
                for (int i = 0; i < pShip->Getlength(); i++)
                {
                    m_Map->setType(pShip->GetPosition()[i].x, pShip->GetPosition()[i].y, pShip->GetType());
                    
                }
                break;
            }
        }
    }
}

HitResult Player::HitCheck(const Position& pos)
{
    
}