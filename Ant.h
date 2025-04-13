#pragma once
#include "Game Settings.h"
#include "Role.h"
#include "Resource.h"
#include "Entity.h"

static Role* roles[7] = { new Baby(), new Sitter(), new Collector(), new Builder(), new Soldier(), new Shepperd(), new Cleaner() };

class Ant : public Entity {
private:
    int max_hp, role_id;
    Role* role;
    bool going_home;
    res_type inventory;

public:
    Ant(float x = 0, float y = 0) :Entity(x, y), role_id(0), going_home(false), inventory(no_res) {
        max_hp = hp;
        role = roles[role_id];
        shape.setRadius(ant_size);
    };

    void move() override;
    void upd_role();
    void upd_color();
    void look_around(vector<Resource>& resources);
    void set_inventory(res_type type) { inventory = type; }
    //bool pick(Resource& res);
    void work() { role->work(); }

    int get_role() const { return role_id; }
    res_type get_inventory() const { return inventory; }
    CircleShape get_vision_circle() const;
};

float randomise_velocity();