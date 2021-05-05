#include "Pane.h"

class StatPane : public Pane
{
public:
    StatPane(int x, int y, int width, int height) : Pane(x, y, width, height) {};
    ~StatPane() {};

    void Draw();
    
};