#pragma once
#include "Game Settings.h"
#include "Ant.h"
class Enemy :public Ant {
private:
    int hp, age;
    Position pos, target;
    Vector2f velocity;
    CircleShape shape;
    bool has_target;
    bool robbed;
    bool going_home;
    bool visible;
    float radius_vision;
public:
    Enemy(float x = 0, float y = 0) :age(0), pos(x, y), hp(1), velocity(0, 0), target(0, 0), has_target(true), going_home(false), robbed(false), radius_vision(80.f) {
        hp = rand() % 201 + 300;
        shape.setRadius(ant_size);
        shape.setFillColor(Color::Red);
        shape.setPosition(x, y);
        visible = true;
    }
    void move();
    void set_velocity(float vx, float vy) { velocity.x = vx; velocity.y = vy; }
    void aged() { age++; }

    const CircleShape& get_shape() const { return shape; }
    int get_hp() const { return hp; }
    bool is_visible() const { return visible; }
};