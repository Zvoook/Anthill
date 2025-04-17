#pragma once
#include "Game Settings.h"
#include "Entity.h"
#include "Role.h"
#include "Resource.h"
#include "Tlya.h"

static Role* roles[7] = { new Baby(), new Sitter(), new Collector(), new Builder(), new Soldier(), new Shepperd(), new Cleaner() };

class Ant : public Entity {
private:
    int max_hp, role_id, damage;
    bool is_regenerating;
    bool already_dead;
    bool has_collected_honey;
    Role* role;
    bool going_home;
    res_type inventory;
    int protection_timer;
    bool under_attack = false, being_warmed = false;
public:
    Ant(float x = 0, float y = 0) :Entity(x, y), role_id(0), going_home(false), inventory(no_res), is_regenerating(false), already_dead(false), has_collected_honey(false) {
        max_hp = hp;
        damage = rand() % 21 + 40;
        role = roles[role_id];
        shape.setRadius(ant_size);
    };

    void move() override;
    void upd_role();
    void upd_color();
    void take_damage(int enemy_damage) { hp -= enemy_damage; }
    float get_radius_vision() { return radius_vision; }
    int get_attack_power() { return damage; }
    void look_around(vector<Resource>& resources, vector<Enemy>& enemies, vector<Aphid>& aphids);
    void set_inventory(res_type type) { inventory = type; }
    bool pick(Resource& res);
    void work(vector<Resource>& resources, vector<Enemy>& enemies, vector<Aphid>& aphids);
    void set_protection_timer(int time) { protection_timer = time; }
    void decrease_protection() { if (protection_timer > 0) protection_timer--; }
    void dead(vector<Resource>& resources);
    void age_up(int x) { age += x; }

    int get_age() const { return age; }
    Position get_target() const { return target; }
    bool is_already_dead() const { return already_dead; }
    void set_already_dead() { already_dead = true; }
    int get_role() const { return role_id; }
    res_type get_inventory() const { return inventory; }
    CircleShape get_vision_circle() const;
};

float randomise_velocity();