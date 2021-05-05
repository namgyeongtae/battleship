#include "../GamePlay/GameManager.h"

int main()
{
    GameManager _gm;
    
    _gm.Init();
    _gm.Render();
    _gm.Play();
    _gm.Destroy();
    
    return 0;
}