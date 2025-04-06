#pragma once
#include "Game Settings.h"
class Position {
public:
    Position(int a = 0, int b = 0) :x(a), y(b) {};
    float x, y;
    float hipotenuse(int a, int b) {return sqrt(pow(a, 2) + pow(b, 2));}
    float distance(const Position& last) { return hipotenuse(x - last.x, y - last.y); }
    bool operator==(const Position& last) { return x == last.x && y == last.y; }
};