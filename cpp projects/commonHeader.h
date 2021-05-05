#ifndef __COMMON_HEADER_H__
#define __COMMON_HEADER_H__

#include <ncurses.h>
#include <vector>
#include <random>

static const int MAP_SIZE = 8;

using namespace std;

struct Position
{
    Position() : x(0), y(0) {}
    int x;
    int y;
};

enum ShipType
{
    DATA_ERROR = -1,
    DATA_NONE,
    AIRCRAFT,
    BATTLESHIP,
    CRUISER,
    DESTROYER
};

enum HitResult
{
    MISS,
    HIT,
    DESTROY
};

#endif