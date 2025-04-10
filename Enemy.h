#pragma once
#include "Game Settings.h"
#include "Ant.h"
class Enemy :public Ant {
private:
    int hp, max_hp, age;
    Position pos, target;
    Vector2f velocity;
    Role* role;
    int role_id;
    CircleShape shape;
    bool has_target;
    res_type inventory;
    bool visible;
public:
    Enemy(float x = 0, float y = 0) :pos(x, y), role_id(0), age(0), hp(1), velocity(0, 0), target(0, 0), has_target(false), inventory(no_res) {
        role = roles[role_id];
        max_hp = rand() % 6 + 10;
        shape.setRadius(ant_size);
        shape.setFillColor(Color::Red);
        shape.setPosition(x, y);
        visible = true;
    }
    //void move();
    void set_velocity(float vx, float vy) { velocity.x = vx; velocity.y = vy; }
    void aged() { age++; }
    bool is_visible() const { return visible; }
    const CircleShape& get_shape() const { return shape; }
};