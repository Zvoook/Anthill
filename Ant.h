#pragma once
#include "Game Settings.h"
#include "Position.h"
#include "Role.h"
#include "Resource.h"
static Role* roles[7] = { new Baby(), new Sitter(), new Collector(), new Builder(), new Soldier(), new Shepperd(), new Cleaner() };

class Ant {
private:
    int hp, age, max_hp;
    Position pos, target;
    Vector2f velocity;
    Role* role;
    int role_id;
    CircleShape shape;
    bool has_target;
    res_type inventory;
    bool visible;
public:
    Ant(float x = 0, float y = 0) :pos(x, y), role_id(0), age(0), hp(1), velocity(0, 0), target(0, 0), has_target(false), inventory(no_res) {
        max_hp = rand() % 201 + 300;
        role = roles[role_id];
        hp = max_hp;
        shape.setRadius(ant_size);
        shape.setFillColor(Color::White);
        shape.setPosition(x, y);
        visible = true;
    }
    void upd_role();
    void move();
    bool pick(Resource& res);
    void drop();
    //void work() { role->work(*this); }
    void upd_color();
    void set_velocity(float vx, float vy) { velocity.x = vx; velocity.y = vy; }
    void set_inventory(res_type type) { inventory = type; }
    void up_time() { age++; }
    //void set_target_on_res(vector<Resource>& res);
    int get_hp() const { return hp; }
    int get_age() const { return age; }
    int get_role() const { return role_id; }
    bool is_visible() const { return visible; }
    const CircleShape& get_shape() const { return shape; }

    //Target
    void set_target(const Position& p) { target = p; has_target = true; }
    void clear_target() { has_target = false; }
    bool has_valid_target() const { return has_target; }
    Position get_pos() const { return pos; }
    res_type get_inventory() const { return inventory; }

};

float randomise_velocity();
