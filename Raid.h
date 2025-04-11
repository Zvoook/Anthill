#pragma once
#include "Game Settings.h"
#include "Enemy.h"

class Raid {
public:
    vector<Enemy> raid;
    Raid() :rad(start_radius) {};
    ~Raid() = default;
    void spawn_raid();
    void kill_raid() { raid.clear(); }

    int get_size() const { return raid.size(); }
private:
    float rad;
};