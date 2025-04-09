#pragma once
#include "Game Settings.h"
class Position {
public:
    Position(int a = 0, int b = 0) :x(a), y(b) {};
    float x, y;
    float hipotenuse(int a, int b) { return sqrt(pow(a, 2) + pow(b, 2)); }
    float distance(const Position& last) { return hipotenuse(x - last.x, y - last.y); }
    bool in_anthill() const {
        float dx = x - window_weidth / 2;
        float dy = y - window_high / 2;
        return (dx * dx + dy * dy) < (start_radius * start_radius);
    }
    bool operator==(const Position& last) { return x == last.x && y == last.y; }
};