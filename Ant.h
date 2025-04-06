#pragma once
#include "Game Settings.h"
#include "Position.h"
#include "Role.h"
#include "Resource.h"
static Role* roles[7] = { new Baby(), new Sitter(), new Collector(), new Builder(), new Soldier(), new Shepperd(), new Cleaner() };

class Ant {
private:
    int hp, max_hp, age;
    Position pos, target;
    Vector2f velocity;
    Role* role;
    int role_id;
    CircleShape shape;
    bool has_target;
    res_type inventory;
public:
    Ant(float x=0, float y=0) : role(roles[0]), role_id(0), age(0), hp(1), velocity(0, 0), target(0, 0), has_target(false), inventory(no_res) {
        max_hp = rand() % 6 + 10;
        shape.setRadius(ant_size);
        shape.setFillColor(Color(255, 182, 193));
        shape.setPosition(x, y);
    }
    ~Ant() { delete role; }
    void set_velocity(float vx, float vy) { velocity.x = vx; velocity.y = vy; }
    void aged() { age++; }
    void set_hp(int n) { hp = n; }
    void upd_role();
    void move();
    void pick_res(Resource& res);
    void drop_res();

    void kill() { hp = 0; }
    //void work() { role->work(*this); }

    int get_hp() const { return hp; }
    int get_max_hp() const { return max_hp; }
    int get_age() const { return age; }
    int get_role() const { return role_id; }
};

float randomise_velocity();