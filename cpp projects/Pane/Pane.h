#ifndef __PANE_H__
#define __PANE_H__
#include "../commonHeader.h"

class Pane
{
public:
    Pane(int x, int y, int width, int height);
    
    virtual ~Pane();
    virtual void Draw();

    WINDOW* getWindow() {return m_pWindow;}

protected:
    int m_width, m_height;
    int m_x, m_y;
    WINDOW* m_pWindow;

};
#endif