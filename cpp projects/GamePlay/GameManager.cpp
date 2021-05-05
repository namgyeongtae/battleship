#include "../commonHeader.h"
#include "GameManager.h"
#include "player.h"
#include"Map.h"
#include "../Pane/BattleShipMap.h"
#include "../BattleShipApp/BattleShip.h"

GameManager::GameManager()
{
    m_Attacker = nullptr;
    m_Defender = nullptr;
    battleship = nullptr;
}

GameManager::~GameManager()
{
    if (m_Attacker)
    {
        delete m_Attacker;
        m_Attacker = nullptr;
    }
    if (m_Defender)
    {
        delete m_Defender;
        m_Defender = nullptr;
    }
}

void GameManager::Init()
{
    m_Attacker = new Player();
    m_Defender = new Player();
    battleship = new BattleShipApp();
    battleship->Init();

    vector<Ship*> vecShip;
    vecShip.push_back(new Aircraft());
    vecShip.push_back(new BattleShip());
    vecShip.push_back(new Cruiser());
    vecShip.push_back(new Destroyer());
    vecShip.push_back(new Destroyer());

    m_Defender->SetupShips(vecShip);

    
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            char a = '0';
            switch (m_Defender->getMap()->getType(i, j))
            {
                case AIRCRAFT:
                    a = 'A';
                    break;
                case BATTLESHIP:
                    a = 'B';
                    break;
                case CRUISER:
                    a = 'C';
                    break;
                case DESTROYER:
                    a = 'D';
                    break;
            }
            
            battleship->getBattleMap()->setMapData(i, j, a);

        }
    }


}

void GameManager::Play()
{
    battleship->Play();

}

void GameManager::Render()
{
    battleship->Render();
   
}

void GameManager::Destroy()
{
    battleship->Destroy(); 
}