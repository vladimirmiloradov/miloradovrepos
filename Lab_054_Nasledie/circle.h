#pragma once
#include "Position.h"
class circle :
    public Position
{
private:
    int radius;
public:
    circle(int x0_pos, int y0_pos, int rad0) : Position(x0_pos, y0_pos) { radius = rad0; }
    void print_circle();
};
