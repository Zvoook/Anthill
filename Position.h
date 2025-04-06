#pragma once
#include "Game Settings.h"
class Position {
private:
    float x, y;
    float hipotenuse(int a, int b) { return sqrt(pow(a, 2) + pow(b, 2)); }
public:
    Position(int a = 0, int b = 0) :x(a), y(b) {};
    float distance(const Position& last) { return hipotenuse(x - last.x, y - last.y); }
    bool operator==(const Position& last) { return x == last.x && y == last.y; }
    void set_pos(float a, float b) { x = a; y = b; }
    float get_x() { return x; }
    float get_y() { return y; }
};