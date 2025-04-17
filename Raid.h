#pragma once
#include "Game Settings.h"
#include "Enemy.h"

class Raid {
public:
    vector<Enemy> crowd;
    Raid() :rad(start_radius), diffuse(1) {};
    ~Raid() = default;
    void spawn_raid();
    void dif_up(int x) { diffuse += x; };

    int get_size() const { return crowd.size(); }
private:
    float rad, diffuse;
};