#include "StatPane.h"

void StatPane::Draw()
{
    mvwprintw(m_pWindow, 0, 3, "<STATUS>");

    wattron(m_pWindow, COLOR_PAIR(2));
    mvwprintw(m_pWindow, 1, 2, "AIRCRAFT : AAAAA");
    mvwprintw(m_pWindow, 2, 2, "BATTLESHIP : BBBB");
    mvwprintw(m_pWindow, 3, 2, "CRUISER : CCC");
    mvwprintw(m_pWindow, 4, 2, "Destroyer : DD DD");
    wattroff(m_pWindow, COLOR_PAIR(2));

    wrefresh(m_pWindow);
}