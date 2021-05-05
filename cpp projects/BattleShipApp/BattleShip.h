#include "../Pane/BattleShipMap.h"
#include "../Pane/StatPane.h"
#include "../Pane/InputPane.h"

class Player;
class BattleShipApp
{
private:
    bool visited[MAP_SIZE][MAP_SIZE] = { 
                                         {false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false}
                                       };

    bool isHit;

public:
    BattleShipApp();
    ~BattleShipApp();

    void Play();

public:
    void Init();
    void Render();
    void Destroy();
    void traceAlgo();
    void initVisited();

    BattleShipMap* getBattleMap() {return defendMap;}
    StatPane* getStatPane() {return m_pStatPane;}

protected:
    BattleShipMap* defendMap;
    BattleShipMap* m_pMap;
    StatPane* m_pStatPane;
    InputPane* m_pInputPane;
};